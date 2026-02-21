
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
int f[maxn][10], dep[maxn];
vector<vii> g(maxn);
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int j = 1; j <= 8; j++)
        f[u][j] = f[f[u][j - 1]][j - 1];
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
    for (int j = 8; j >= 0; j--)
    {
        if (f[u][j] != f[v][j])
        {
            u = f[u][j];
            v = f[v][j];
        }
    }
    return f[u][0];
}
int getdis(int u, int v)
{
    int anc = LCA(u, v);
    return 2 * (dep[u] - dep[anc]) + dep[v] - dep[anc];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    int mx=0,wid=0;
    vii cnt(n+1,0);
    for (int i=1;i<=n;i++){
        mx=max(mx,dep[i]);
        cnt[dep[i]]++;
        wid=max(wid,cnt[dep[i]]);
    }
    int x,y;
    cin>>x>>y;
    cout<<mx<<endl;
    cout<<wid<<endl;
    cout<<getdis(x,y)<<endl;
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