
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
int f[maxn][21], p[maxn], a[maxn];
int dep[maxn];
bool vis[maxn];
vector<vii> g(maxn);
vector<array<int, 3>> ed(maxn);
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
void dfs(int u, int fa)
{
    vis[u] = 1;
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (auto v : g[u])
    {
        dfs(v, u);
    }
}
int LCA(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    int tmp = dep[v] - dep[u];
    for (int i = 0; tmp; tmp >>= 1, i++)
    {
        if (tmp & 1)
            v = f[v][i];
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = n;
    for (int i = 1; i <= n + m; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed[i] = {w, u, v};
    }
    sort(ed.begin() + 1, ed.begin() + m + 1);
    reverse(ed.begin() + 1, ed.begin() + m + 1);
    for (int i = 1; i <= m; i++)
    {
        auto &[w, u, v] = ed[i];
        int fu = find(u), fv = find(v);
        if (fu != fv)
        {
            a[++cnt] = w;
            g[cnt].pb(fu);
            g[cnt].pb(fv);
            p[fu] = cnt, p[fv] = cnt;
        }
    }
    for (int i = cnt; i >= n + 1; i--)
    {
        if (!vis[i])
            dfs(i, 0);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            cout << -1 << endl;
        }
        else
        {
            int anc = LCA(x, y);
            cout << a[anc] << endl;
        }
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