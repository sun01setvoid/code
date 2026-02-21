// P4281 集会
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
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
int dep[maxn];
int f[maxn][21];
vector<vii> g(maxn);
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int j = 1; j <= 20; j++)
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
    if (u == v)
        return u;
    for (int j = 20; j >= 0; j--)
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int a = LCA(x, y), b = LCA(y, z), c = LCA(x, z);
        int d = LCA(z, a), e = LCA(x, b), f = LCA(y, c);
        //深度更大的就是最优点
        int mx = inf, id = a;
        if (mx > dep[x] + dep[y] - 2 * dep[a] + dep[z] + dep[a] - 2 * dep[d])
            id = a, mx = dep[x] + dep[y] - 2 * dep[a] + dep[z] + dep[a] - 2 * dep[d];
        if (mx > dep[z] + dep[y] - 2 * dep[b] + dep[x] + dep[b] - 2 * dep[e])
            id = b, mx = dep[z] + dep[y] - 2 * dep[b] + dep[x] + dep[b] - 2 * dep[e];
        if (mx > dep[z] + dep[x] - 2 * dep[c] + dep[y] + dep[c] - 2 * dep[f])
            id = c, mx = dep[z] + dep[x] - 2 * dep[c] + dep[y] + dep[c] - 2 * dep[f];
        cout << id << " " << mx << endl;
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