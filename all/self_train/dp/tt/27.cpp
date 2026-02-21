// P2014 选课
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 300 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
// 拓扑排序建树
// 树上背包
int dp[maxn][maxn];
vector<vii> adj(maxn);
int a[maxn], sz[maxn];
int n, m;
void dfs(int u, int fa)
{
    sz[u] = 0;
    for (auto &v : adj[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        for (int j = sz[u] + sz[v]; j >= 0; j--)
        {
            for (int k = max(0ll, j - sz[u]); k <= min(sz[v],j); k++)
            {
                // j-sz[u]使最小的,再小的话u就给不出来了
                // 用来降低时间复杂度,使树上背包的复杂度大概达到(O(n*m),O(n*n))
                //因为只在节点对的lca时更新
                // 滚动数组
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
            }
        }
        sz[u] += sz[v];
    }
    sz[u]++;
    for (int i = sz[u]; i >= 1; i--)
        dp[u][i] = dp[u][i - 1] + a[u];
}
void solve()
{
    cin >> n >> m;
    queue<int> q;
    rep(i, 1, n)
    {
        int k, s;
        cin >> k >> s;
        if (k != 0)
            adj[k].pb(i);
        else
            adj[n + 1].pb(i);
        a[i] = s;
    }
    a[n + 1] = 0;
    dfs(n + 1, 0);
    cout << dp[n + 1][m + 1];
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