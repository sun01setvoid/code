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
const int maxn = 5e3 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
// 这是高峰版，低谷版更简单一点，因为只需要操作一个位置，考虑第i-1个位置是怎样的就行
int dp[maxn][maxn][2]; // 前i个位置，j个符合，最后的符合
//因为前一个位置的状态会影响当前的决策，所以要存取前一个位置的状态
//只考虑前面较简单，所以不妨先考虑向前
int a[maxn];
// 只考虑向前，不然状态定义太难
// 0表示该位置不满足，1表示操作该位置满足
// 这里的边界满足条件只看向前
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, 1, n) dp[i][j][0] = dp[i][j][1] = INF;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    dp[1][1][1] = 0;
    dp[2][1][0] = max(0ll, a[2] - a[1] + 1);
    dp[2][1][1] = max(0ll, a[1] - a[2] + 1);
    for (int i = 0; i <= n; i++)
        dp[i][0][0] = dp[i][0][1] = 0; // 0个的花费0
    rep(i, 3, n)
    {
        rep(j, 1, (i + 1) / 2)
        {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + max(0ll, a[i] - a[i - 1] + 1));
            dp[i][j][1] = min(dp[i - 2][j - 1][1] + max({a[i - 1] - a[i - 2] + 1, 0ll, a[i - 1] - a[i] + 1}), dp[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0ll));
            //i成立，i-1一定不成立，考虑i-1不成立的两种情况
        }
    }
    rep(i, 1, (n + 1) / 2)
    {
        cout << min(dp[n][i][0], dp[n][i][1]) << " ";
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