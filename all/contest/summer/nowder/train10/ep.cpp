#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 410;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
template <class _t1, class _t2>
inline void cmin(_t1 &a, _t2 b) { a = a > b ? b : a; }
//-----------------------------------------------------//
int n, m, a[maxn], mx, mn, ans;
int dp[410][250][3]; // 前i个，多出来几个1
// 0 -&
// 1 0
// 2 &
void solve()
{
    cin >> n >> m;
    ans = 0, mn = INF, mx = 0;
    vii c(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
    for (int i = 1; i <= n; i++)
        c[i] = mx - a[i];
    for (int i = 1; i <= n + 1; i++)
        ans += abs(c[i] - c[i - 1]);
    ans = ans / 2;
    if (m == 1)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        vii b(n + 1);
        for (int i = 2; i <= n; i++)
            b[i] = a[i] - a[i - 1];
        int lim = 210;
        for (int d = 0; d <= lim; d++)
        {
            memset(dp, 0x3f,sizeof dp);
            for (int j = 0; j <= lim; j++)
                dp[1][j][0] = dp[1][j][1] = j;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 0; j <= lim; j++)
                {
                    if (b[i] > 0 && b[i] - j <= 0)
                    {
                        cmin(dp[i][j - b[i]][0], dp[i - 1][j][0]);
                        cmin(dp[i][j - b[i]][1], dp[i - 1][j][1]);
                    }
                    if (b[i] <= 0)
                    {
                        cmin(dp[i][j - b[i]][0], dp[i - 1][j][0] - b[i]);
                        cmin(dp[i][j - b[i]][1], dp[i - 1][j][1] - b[i]);
                    }
                    if (b[i] > d && b[i] - j <= d)
                    {
                        cmin(dp[i][j - (b[i] - d)][0], dp[i - 1][j][1]);
                    }
                    if (b[i] <= d)
                    {
                        cmin(dp[i][j - (b[i] - d)][0], dp[i - 1][j][1] - (b[i] - d));
                    }
                    if (b[i] > -d && b[i] - j <= -d)
                    {
                        cmin(dp[i][j - (b[i] + d)][1], dp[i - 1][j][0]);
                    }
                    if (b[i] <= -d)
                    {
                        cmin(dp[i][j - (b[i] + d)][1], dp[i - 1][j][0] - (b[i] + d));
                    }
                }
            }
            for (int j = 0; j <= lim; j++)
                cmin(ans, dp[n][j][0]), cmin(ans, dp[n][j][1]);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}