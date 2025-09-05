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
const int mod = 998244353;
const ld eps = 1e-7;
int dp[55][105][105];
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    string s, s1 = "#", s2 = "&";
    cin >> s;
    s1 += s.substr(0, n);
    s2 += s.substr(n, n);
    int ans = 0;
    for (int pos = 0; pos <= 2 * n; pos++)
    {
        if (pos == n)
            continue;
        memset(dp, 0, sizeof dp);
        dp[0][n][n] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2 * n; j++)
            {
                for (int k = 0; k <= 2 * n; k++)
                {
                    if (n + j == pos + k)
                        continue;
                    if (s1[i] == 'L' && j - 1 >= 0)
                    {
                        if (s2[i] == 'L' && k - 1 >= 0)
                        {
                            if (n + j - 1 != pos + k - 1)
                                dp[i][j - 1][k - 1] = (dp[i][j - 1][k - 1] + dp[i - 1][j][k]) % mod;
                        }
                        else if (s2[i] == 'R' && k + 1 <= 2 * n)
                        {
                            if (n + j - 1 != pos + k + 1)
                                dp[i][j - 1][k + 1] = (dp[i][j - 1][k + 1] + dp[i - 1][j][k]) % mod;
                        }
                        else
                        {
                            if (k - 1 >= 0 && n + j - 1 != pos + k - 1)
                                dp[i][j - 1][k - 1] = (dp[i][j - 1][k - 1] + dp[i - 1][j][k]) % mod;
                            if (k + 1 <= 2 * n && n + j - 1 != pos + k + 1)
                                dp[i][j - 1][k + 1] = (dp[i][j - 1][k + 1] + dp[i - 1][j][k]) % mod;
                        }
                    }
                    else if (s1[i] == 'R' && j + 1 <= 2 * n)
                    {
                        if (s2[i] == 'L' && k - 1 >= 0)
                        {
                            if (n + j + 1 != pos + k - 1)
                                dp[i][j + 1][k - 1] = (dp[i][j + 1][k - 1] + dp[i - 1][j][k]) % mod;
                        }
                        else if (s2[i] == 'R' && k + 1 <= 2 * n)
                        {
                            if (n + j + 1 != pos + k + 1)
                                dp[i][j + 1][k + 1] = (dp[i][j + 1][k + 1] + dp[i - 1][j][k]) % mod;
                        }
                        else
                        {
                            if (k - 1 >= 0 && n + j + 1 != pos + k - 1)
                                dp[i][j + 1][k - 1] = (dp[i][j + 1][k - 1] + dp[i - 1][j][k]) % mod;
                            if (k + 1 <= 2 * n && n + j + 1 != pos + k + 1)
                                dp[i][j + 1][k + 1] = (dp[i][j + 1][k + 1] + dp[i - 1][j][k]) % mod;
                        }
                    }
                    else
                    {
                        if (s2[i] == 'L' && k - 1 >= 0)
                        {
                            if (j - 1 >= 0 && n + j - 1 != pos + k - 1)
                                dp[i][j - 1][k - 1] = (dp[i][j - 1][k - 1] + dp[i - 1][j][k]) % mod;
                            if (j + 1 <= 2 * n && n + j + 1 != pos + k - 1)
                                dp[i][j + 1][k - 1] = (dp[i][j + 1][k - 1] + dp[i - 1][j][k]) % mod;
                        }
                        else if (s2[i] == 'R' && k + 1 <= 2 * n)
                        {
                            if (j - 1 >= 0 && n + j - 1 != pos + k + 1)
                                dp[i][j - 1][k + 1] = (dp[i][j - 1][k + 1] + dp[i - 1][j][k]) % mod;
                            if (j + 1 <= 2 * n && n + j + 1 != pos + k + 1)
                                dp[i][j + 1][k + 1] = (dp[i][j + 1][k + 1] + dp[i - 1][j][k]) % mod;
                        }
                        else
                        {
                            if (j - 1 >= 0 && k - 1 >= 0 && n + j - 1 != pos + k - 1)
                                dp[i][j - 1][k - 1] = (dp[i][j - 1][k - 1] + dp[i - 1][j][k]) % mod;
                            if (j + 1 <= 2 * n && k - 1 >= 0 && n + j + 1 != pos + k - 1)
                                dp[i][j + 1][k - 1] = (dp[i][j + 1][k - 1] + dp[i - 1][j][k]) % mod;
                            if (j - 1 >= 0 && k + 1 <= 2 * n && n + j - 1 != pos + k + 1)
                                dp[i][j - 1][k + 1] = (dp[i][j - 1][k + 1] + dp[i - 1][j][k]) % mod;
                            if (j + 1 <= 2 * n && k + 1 <= 2 * n && n + j + 1 != pos + k + 1)
                                dp[i][j + 1][k + 1] = (dp[i][j + 1][k + 1] + dp[i - 1][j][k]) % mod;
                        }
                    }
                }
            }
        }
        for (int j = 0; j <= 2 * n; j++)
            ans = (ans + dp[n][pos][j]) % mod;
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