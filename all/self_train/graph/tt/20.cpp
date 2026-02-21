// P2195 HXY造公园
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
int p[maxn], c[maxn], dis[maxn];
bool vis[maxn];
int diam;
vector<vii> g(maxn);
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
void dfs(int u, int fa)
{
    vis[u] = 1;
    int d1 = 0, d2 = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        int tmp=dis[v]+1;
        dis[u] = max(dis[u], tmp);
        if (tmp> d1)
        {
            d2 = d1;
            d1 =tmp;
        }
        else if (tmp > d2)
            d2 = tmp;
        diam = max(d1 + d2, diam);
    }
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        int fu = find(u), fv = find(v);
        if (fu != fv)
            p[fu] = fv;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            diam = 0, dfs(find(i), find(i)), c[find(i)] = diam;
    }
    for (int i = 1; i <= q; i++)
    {
        int op, u, v;
        cin >> op;
        if (op == 1)
        {
            cin >> u;
            int fu = find(u);
            cout << c[fu] << endl;
        }
        else
        {
            cin >> u >> v;
            int fu = find(u), fv = find(v);
            if(fu==fv) continue;
            p[fu] = fv;
            c[fv] = max({(c[fu] + 1) / 2 + (c[fv] + 1) / 2 + 1, c[fu], c[fv]});
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