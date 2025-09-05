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
//-----------------------------------------------------//
int n, m, a[maxn], mx, mn, ans;
int dp[410][260][3]; // 前i个，多出来几个1
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
        int lim = 250;
        for (int d = 5; d <= 5; d++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= lim; j++)
                    dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = INF;
            }
            for (int i = 0; i <= lim; i++) // 初始化有几次操作
                dp[1][i][1] = i;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 0; j <= lim; j++)
                {
                    if (b[i] >= 0 && b[i] + j <= lim) //-
                    {
                        int del = b[i];
                        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j + del][1]);
                        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j + del][0]);
                        dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j + del][2]);
                    }
                    else if (b[i] < 0 && j + b[i] >= 0)
                    {
                        int del = -b[i];
                        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - del][1] + del);
                        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - del][0] + del);
                        dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - del][2] + del);
                    }
                    if (b[i] <= d && b[i] >= -d)
                    {
                        if (d - b[i] <= j) //+
                        {
                            int del = d - b[i];
                            dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - del][1] + del);
                            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - del][0] + del);
                        }
                        if (b[i] + d + j <= lim) //-
                        {
                            int del = b[i] + d;
                            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j + del][1]);
                            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j + del][2]);
                        }
                    }
                    else if (b[i] > d) //-
                    {
                        if (b[i] - d + j <= lim) //-
                        {
                            int del = b[i] - d;
                            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j + del][0]);
                            dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j + del][1]);
                        }
                        if (b[i] + d + j <= lim)
                        {
                            int del = b[i] + d;
                            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j + del][1]);
                            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j + del][2]);
                        }
                    }
                    else //+
                    {
                        if (-d - b[i] <= j) //-
                        {
                            int del = -d - b[i];
                            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - del][1] + del);
                            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - del][2] + del);
                        }
                        if (d - b[i] <= j)
                        {
                            int del = d - b[i];
                            dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - del][1] + del);
                            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - del][0] + del);
                        }
                    }
                    // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << endl;
                }
            }
            for (int j = 0; j <= lim; j++)
                ans = min({ans, dp[n][j][0], dp[n][j][1], dp[n][j][2]});
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