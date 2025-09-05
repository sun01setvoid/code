// P2921 USACO08DEC] Trick or Treat on the Farm G
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dfn[maxn], low[maxn], ts;
int stk[maxn], top;
bool ins[maxn];
int id[maxn], scc_cnt, sz[maxn], ans[maxn];
int p[maxn];
bool self[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++ts;
    stk[++top] = u, ins[u] = 1;
    int v = p[u];
    if (!dfn[v])
    {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    else if (ins[v])
    {
        low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int y;
        ++scc_cnt;
        int cnt = 0;
        do
        {
            y = stk[top--], ins[y] = 0, id[y] = scc_cnt;
            cnt++;
        } while (y != u);
        sz[scc_cnt] = cnt;
    }
}
int dfs(int u)
{
    int v = p[u];
    if (sz[id[u]] >= 2 || self[u])
        return sz[id[u]];
    if (ans[u])
        return ans[u];
    return ans[u] = dfs(v) + 1;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (i == p[i])
            self[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (sz[id[i]] >= 2 || self[i])
        {
            ans[i] = sz[id[i]];
        }
        else
        {
            int res = dfs(p[i]);
            ans[i] = res + 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
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