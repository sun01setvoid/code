// P2466 Sue的小球
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
// 当前决策会对之后的决策产生影响
// 如果产生的影响能算，直接先计算，然后处理掉就行
// 或者换一种dp方式
//两者都考虑一下
// 带贪dp,尽量走相邻的
int dp[2][1100][1100]; // 0在左侧，1在右侧
array<int, 3> a[1100];
int pre[1100];
void solve()
{
    int n, x0;
    cin >> n >> x0;
    rep(i, 1, n) cin >> a[i][0];
    rep(i, 1, n) cin >> a[i][1];
    rep(i, 1, n) cin >> a[i][2];
    a[n + 1] = {x0, 0, 0};
    sort(a + 1, a + n + 2);
    n = n + 1;
    rep(i, 1, n) rep(j, 1, n) dp[0][i][j] = dp[1][i][j] = -INF;
    rep(i, 1, n)
    {
        if (a[i][0] == x0 && a[i][1] == 0 && a[i][2] == 0)
            dp[0][i][i] = 0, dp[1][i][i] = 0;
        pre[i] = pre[i - 1] + a[i][2];
    }
    for (int len = 2; len <= n; len++)
    {
        // debug(len);
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[0][i][j] = max(dp[0][i + 1][j] - (pre[i] + pre[n] - pre[j]) * (a[i + 1][0] - a[i][0]),
            dp[1][i + 1][j] - (pre[i] + pre[n] - pre[j]) * (a[j][0] - a[i][0])) +a[i][1];
            dp[1][i][j] = max(dp[0][i][j - 1] - (pre[i - 1] + pre[n] - pre[j - 1]) * (a[j][0] - a[i][0]),
            dp[1][i][j - 1] - (pre[i - 1] + pre[n] - pre[j - 1]) * (a[j][0] - a[j - 1][0])) +a[j][1];
            // cout << i << " " << j << " " << dp[0][i][j] << " " << dp[1][i][j] << endl;
        }
    }
    cout << fixed << setprecision(3) << (double)max(dp[0][1][n], dp[1][1][n]) / 1000;
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