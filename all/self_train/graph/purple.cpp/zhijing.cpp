// 选第二条边与第一条边重叠的就要减去价值
// 所以第一条边上的直接设成-1，然后dp求直径
//  P6961
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define pb push_back
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, k;
vector<vii> g(maxn);
vector<vector<pii>> ng(maxn);
int dep[maxn], ans, dist[maxn], f[maxn];
int diam[maxn];
void dfs(int u, int fa)
{
    f[u] = fa;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
void dp(int u, int fa)
{
    int d1 = 0, d2 = 0;
    for (auto [v, w] : ng[u])
    {
        if (v == fa)
            continue;
        dp(v, u);
        int tmp = dist[v] + w;
        if (tmp > d1)
            d2 = d1, d1 = tmp;
        else if (tmp > d2)
            d2 = tmp;
        ans = max(ans, d1 + d2);
    }
    dist[u] = d1;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        ng[a].pb({b, 1});
        g[b].pb(a);
        ng[b].pb({a, 1});
    }
    int s = -1, t = -1;
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (s == -1 || dep[i] > dep[s])
            s = i;
    }
    dep[s] = 0;
    dfs(s, -1);
    for (int i = 1; i <= n; i++)
    {
        if (t == -1 || dep[i] > dep[t])
            t = i;
    }
    if (k == 1)
    {
        cout << 2 * (n - 1) + 1 - dep[t] << endl;
        return;
    }
    for (int i = t; i != -1; i = f[i])
    {
        diam[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto &[v, w] : ng[i])
        {
            if (diam[i] && diam[v])
                w = -1;
        }
    }
    dp(1, -1);
    cout << 2 * (n - 1) + 2 - ans - dep[t] << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}