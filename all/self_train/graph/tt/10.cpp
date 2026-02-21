// P3387 [模板]缩点
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
vector<vii> adj(maxn), g(maxn);
int dfn[maxn], low[maxn], ts;
int stk[maxn], top;
int id[maxn], scc_cnt;
bool ins[maxn];
int a[maxn];
int w[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++ts;
    stk[++top] = u, ins[u] = 1;
    for (auto v : adj[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        int y;
        ++scc_cnt;
        do
        {
            y = stk[top--];
            ins[y] = 0, id[y] = scc_cnt;
            w[scc_cnt] += a[y];
        } while (y != u);
    }
}
int dp[maxn];
int dfs(int u)
{
    if (dp[u] != -1)
        return dp[u];
    int res = 0;
    for (auto v : g[u])
    {
        int t = dfs(v);
        res = max(t, res);
    }
    return dp[u] = w[u] + res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            if (id[i] != id[j])
                g[id[i]].pb(id[j]);
        }
    }
    int ans = 0;
    for (int i = scc_cnt; i >= 1; i--)
    {
        if (dp[i] == -1)
            dfs(i);
        ans = max(dp[i], ans);
    }
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