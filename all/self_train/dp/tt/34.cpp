// P3177  树上染色
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
const int maxn = 2e3 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, k;
vector<vector<pair<int, int>>> adj(maxn);
int dp[maxn][maxn], sz[maxn];
// 因为考虑路径，可以单独考虑某条路的贡献
// 在u的子树内，染了j个点得到的贡献
// 这样我们对转移的这条边就不会有后效性和难以计算的问题了
int get(int x, int y)
{
    //cout << "x=" << x << " y=" << y << endl;
    //cout << x * (k - x) + (y - x) * (n - y - (k - x)) << endl;
    return x * (k - x) + (y - x) * (n - y - (k - x));
    // 将计算变为只与给定状态有关，不与它dp的值有关，这样就无后效性了
}
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (auto p : adj[u])
    {
        int v = p.first, w = p.second;
        if (v == fa)
            continue;
        dfs(v, u);
        for (int i = min(sz[u] + sz[v], k); i >= 0; i--)
        {
            for (int j = max(0ll, i - sz[u]); j <= min(sz[v], i); j++)
            {
                dp[u][i] = max(dp[u][i - j] + dp[v][j] + w * get(j, sz[v]), dp[u][i]);
            }
        }
        sz[u] += sz[v];
    }
    /*
    for (int i = 0; i <= k; i++)
        cout << u << " " << i << " " << dp[u][i] << " " << endl;
    */
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dfs(1, 0);
    cout << dp[1][k] << endl;
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