//P4395 气垫车
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
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int dp[maxn][51];//其实最大点权是logn+1（我不知道，我也没懂）
//每次只需要次小值和最小值？
int n;
vector<vii> adj(maxn);
void dfs(int u, int fa)
{
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        for (int i = 1; i <= 50; i++)
        {
            int mi = INF;
            for (int j = 1; j <= 50; j++)
            {
                if (i == j)
                    continue;
                mi = min(dp[v][j], mi);
            }
            dp[u][i] += mi;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 1, n) rep(j, 1, 50) dp[i][j] = j;
    dfs(1, 0);
    int ans = INF;
    for (int i = 1; i <= 50; i++)
        ans = min(ans, dp[1][i]);
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