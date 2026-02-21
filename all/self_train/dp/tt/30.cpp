// P3698 小Q的棋盘
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
const int maxn = 1e2 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int v, n;
int dp[maxn][maxn][2];
// 0,1区分最后一次走圈和不走圈
// 背包
vector<vii> adj(maxn);
void dfs(int u, int fa) // 注意树形dp只有一个点的话，可能没转移
{
    for (int i = 1; i <= n; i++)
        dp[u][i][0] = dp[u][i][1] = 1;
    // 不卡空间的话，可以这么写一下（就是直接把当前节点记录，而不是先处理子节点）
    // 但是这边要把第一次转移写好，考虑转移可能是很多个位置的，不要想当然初始化一个点，
    // 不然就不是背包的转移了
    for (auto &v : adj[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        for (int i = n; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (i - j - 2 >= 0)
                {
                    dp[u][i][1] = max(dp[u][i][1], dp[u][i - j - 2][1] + dp[v][j][1]);
                    dp[u][i][0] = max(dp[u][i][0], dp[u][i - j - 2][0] + dp[v][j][1]);
                }
                dp[u][i][0] = max(dp[u][i][0], dp[u][i - j - 1][1] + dp[v][j][0]); // 直接走，步数1
            }
        }
    }
}
void solve()
{
    cin >> v >> n;
    rep(i, 1, v - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 0, v - 1) dp[i][0][1] = dp[i][0][0] = 1;
    dfs(0, 0);
    if (v==1){
        cout<<1<<endl;
        return;
    }
    cout<<dp[0][n][0]<<endl;
    /*
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(dp[0][i][0], ans); // 因为不一定有转移，如果是一个点的话
    cout << ans << endl;
    */
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
/*贪心，很明显，画一下就行*/
/*
int v, n;
vector<vii> adj(maxn);
int ans = 0;
void dfs(int u, int fa, int d)
{
    ans = max(ans, d);
    for (auto &v : adj[u])
    {
        if (v == fa)
            continue;
        dfs(v, u, d + 1);
    }
}
void solve()
{
    cin >> v >> n;
    for (int i = 0; i <= v - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, 0, 0);
    if (ans >= n)
        cout << n + 1 << endl;
    else
    {
        cout << ans + 1 + min((n - ans) / 2, v - ans - 1) << endl;
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
*/