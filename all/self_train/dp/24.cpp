//P1040 加分二叉树
//区间dp通常线性
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int dp[35][35], pre[35][35]; // 合并建树，区间dp
int a[35];
vii path;
void dfs(int l, int r, int u)
{
    path.push_back(u);
    if (l < u)
        dfs(l, u - 1, pre[l][u - 1]);
    if (u < r)
        dfs(u + 1, r, pre[u + 1][r]);
}
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i], dp[i][i] = a[i], pre[i][i] = i;
    rep(i, 1, n - 1) dp[i][i + 1] = a[i] + a[i + 1], pre[i][i + 1] = i;
    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++)
            {
                if (dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + a[k])
                    pre[i][j] = k, dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + a[k];
            }
        }
    }
    cout << dp[1][n] << endl;
    dfs(1, n, pre[1][n]);
    for (auto i:path) cout<<i<<" ";
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