// P4408
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
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
vector<vector<pii>> g(maxn);
int diam[maxn], f[maxn], dist[maxn];
void dfs(int u, int fa)
{
    f[u] = fa;
    for (auto [v, w] : g[u])
    {
        if (v == fa)
            continue;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}
int dfs1(int u, int fa)
{
    int res = 0;
    for (auto [v, w] : g[u])
    {
        if (v == fa || diam[v])
            continue;
        int tt = dfs1(v, u);
        res = max(res, w+ tt);
    }
    return res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1, -1);
    int s = -1, t = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s == -1 || dist[i] > dist[s])
            s = i;
    }
    dist[s] = 0;
    dfs(s, -1);
    for (int i = 1; i <= n; i++)
    {
        if (t == -1 || dist[i] > dist[t])
            t = i;
    }
    int mx = 0;
    for (int i = t; i != -1; i = f[i])
    {
        diam[i] = 1;
    }
    for (int i = t; i != -1; i = f[i])
    {
        int tt = dfs1(i, -1);
        mx = max(mx, min(tt + dist[i], tt + dist[t] - dist[i]));
    }
    cout << mx + dist[t] << endl;
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