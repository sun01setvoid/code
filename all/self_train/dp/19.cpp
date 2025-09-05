// P3146 248G
// 特点：区间合并
// first
// 非常规区间dp  //对于右端点模糊不清的情况，不如直接把他做值
/*
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
int dp[50][250]; // 从i开始，成为j的（右端点+1）
// 只要知道右端点，就可以转移
int a[250];
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i], dp[a[i]][i] = i + 1;
    int ans = 1;
    for (int j = 2; j <= 47; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[j - 1][i])
                 dp[j][i] = dp[j - 1][dp[j - 1][i]];
            if (dp[j][i])
                ans = max(ans, j);
        }
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
*/

// second
// 常规区间dp非常规
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
int dp[250][250]; // 只有相等的，转移过的才能转移  //只考虑合并了的堆
int a[250];
void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    rep(i, 1, n) cin >> a[i], dp[i][i] = a[i], ans = max(ans, a[i]);
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (!dp[i][k] || !dp[k + 1][j])
                    continue;
                if (dp[i][k] == dp[k + 1][j])
                    dp[i][j] = max(dp[i][k] + 1, dp[i][j]);
                //cout << i << " " << k << " " << j << " " << dp[i][k] << " " << dp[k + 1][j] <<" "<<dp[i][j]<<endl;
            }
            ans = max(dp[i][j], ans);
        }
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