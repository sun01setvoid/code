//P3047 Nearby Cow G
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
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int dp1[maxn][22], dp2[maxn][22]; // 距离当前点i距离为j的地方有多少头牛
//  第一个考虑：第二次dp时，这个向上需不需要存它自己的，会不会重
//  第二个考虑：第二次dp时，这个向下的又没有把包含v的子树的部分删掉
//  第三个考虑：第一次dp是前序遍历，第二次dp是后序遍历
//如果要合成为一个dp数组的话，考虑容斥操作，减去v本身的部分
//这时要注意循环顺序，因为1-j都要减，所以倒着遍历
int n, k;
int c[maxn];
vector<vii> adj(maxn);
void dfs1(int u, int fa)
{
    for (auto &v : adj[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
        for (int i = 1; i <= k; i++)
        {
            dp1[u][i] += dp1[v][i - 1];
        }
    }
}
void dfs2(int u, int fa)
{
    for (auto &v : adj[u])
    {
        if (v == fa)
            continue;
        for (int i = 1; i <= k; i++)
        {
            dp2[v][i] += dp1[u][i - 1] + dp2[u][i - 1] - (i >= 2 ? dp1[v][i - 2] : 0);
        }
        dfs2(v, u);
    }
}
void solve()
{
    cin >> n >> k;
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 1, n) cin >> c[i], dp1[i][0] = c[i];
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            dp1[i][j] = dp1[i][j - 1] + dp1[i][j], dp2[i][j] = dp2[i][j - 1] + dp2[i][j];
        // cout << dp1[i][k] << ' ' << dp2[i][k] << endl;
        cout << dp1[i][k] + dp2[i][k] << endl;
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