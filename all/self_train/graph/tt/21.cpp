// P5536 核心城市，直径
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
int f[maxn];
vector<vii> g(maxn);
int dist[maxn], mdist[maxn];
void dfs(int u, int fa)
{
    f[u] = fa;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dist[v] = dist[u] + 1;
        dfs(v, u);
        mdist[u] = max(mdist[v] + 1, mdist[u]);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dist[1] = 0;
    dfs(1, -1);
    int s = 1, t;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[s])
        {
            s = i;
        }
    }
    dist[s] = 0;
    dfs(s, -1);
    t = s;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[t])
            t = i;
    }
    int len = dist[t];
    int mid = t;
    for (int i = 1; i <= len / 2; i++)
    {
        mid = f[mid];
    }
    for (int i = 1; i <= n; i++)
        mdist[i] = 0;
    dist[mid] = 0;
    dfs(mid, -1);
    sort(mdist + 1, mdist + n + 1);
    mdist[0] = -1;
    cout << mdist[n - k] + 1 << endl;
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