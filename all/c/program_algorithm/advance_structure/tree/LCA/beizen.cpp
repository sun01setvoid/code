// P3379 模板 lca
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
vector<vii> g(maxn);
int n, m, s;
int f[maxn][21], dep[maxn];
void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    int mx = __lg(dep[u]);
    for (int j = 1; j <= mx; j++)
    {
        f[u][j] = f[f[u][j - 1]][j - 1];
    }
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}
int LCA(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    int tmp = dep[v] - dep[u];
    for (int j = 0; tmp; ++j, tmp >>= 1)
    {
        if (tmp & 1)
            v = f[v][j];
    }
    if (v == u)
        return u;
    for (int j = 20; j >= 0 && v != u; --j) // 跳多了不算
    {
        if (f[u][j] != f[v][j])
        {
            u = f[u][j];
            v = f[v][j];
        }
    }
    return f[u][0];
}
void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
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