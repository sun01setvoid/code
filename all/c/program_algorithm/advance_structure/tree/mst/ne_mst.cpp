#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pb push_back
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
struct edge
{
    int w, u, v;
    bool operator<(const edge &oth) const { return w < oth.w; }
};
vector<edge> ed;
bool used[maxn];
int n, m, sum;
int p[maxn];
int dep[maxn], mx[maxn][21], nmx[maxn][21], f[maxn][21];
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
vector<vector<pii>> g(maxn);
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    nmx[u][0] = -inf;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
        int kk[4] = {mx[u][i - 1], mx[f[u][i - 1]][i - 1], nmx[u][i - 1], nmx[f[u][i - 1]][i - 1]};
        sort(kk, kk + 4);
        mx[u][i] = kk[3];
        int ptr = 2;
        while (ptr >= 0 && kk[ptr] == kk[3])
            ptr--;
        nmx[u][i] = (ptr == -1 ? -inf : kk[ptr]);
    }
    for (auto &[v, w] : g[u])
    {
        if (v == fa)
            continue;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int LCA(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    int tmp = dep[v] - dep[u];
    for (int i = 0; tmp; i++, tmp >>= 1) // 错误：这里应该是倍增跳转
    {
        if (tmp & 1)
            v = f[v][i]; // 错误：应该用f[v][i]
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

int qry(int u, int v, int w)
{
    int res = -inf;
    for (int i = 20; i >= 0; i--)
    {
        if (dep[f[u][i]] >= dep[v])
        {
            if (mx[u][i] != w)
                res = max(res, mx[u][i]);
            else
                res = max(res, nmx[u][i]);
            u = f[u][i];
        }
    }
    return res;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int w, u, v;
        cin >> u >> v >> w;
        ed.pb({w, u, v});
    }
    sort(ed.begin(), ed.end());
    int tot = 0;
    sum = 0;
    for (int i = 0; i <= m - 1; i++)
    {
        auto &[w, u, v] = ed[i];
        int fu = find(u), fv = find(v);
        if (fu != fv)
        {
            p[fu] = fv; // 构图过程中建树
            g[u].pb({v, w});
            g[v].pb({u, w});
            tot++;
            sum += w;
            used[i] = 1;
        }
        if (tot == n - 1)
            break;
    }
    dfs(1, 0);
    int ans = inf;
    for (int i = 0; i <= m - 1; i++)
    {
        if (!used[i])
        {
            auto &[w, u, v] = ed[i];
            int anc = LCA(u, v);
            int tmp1 = qry(u, anc, w), tmp2 = qry(v, anc, w);
            int mxval = max(tmp1, tmp2);
            if (mxval != -inf)
            {
                ans = min(ans, sum - mxval + w);
            }
        }
    }
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
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