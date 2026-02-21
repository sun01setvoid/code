#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1000 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int dp[2][maxn][maxn]; // 0 向右  1向左
void solve()
{
    memset(dp, 0, sizeof dp);
    int n, k;
    cin >> n >> k;
    dp[0][k][1] = 1; // 向右指向1
    for (int j = k; j >= 1; j--)
    {
        if (j == 1)
            break;
        for (int i = 1; i <= n; i++)
        {
            (dp[1][j - 1][i - 1] += dp[0][j][i]) %= mod, (dp[1][j - 1][n] -= dp[0][j][i]) %= mod;
            (dp[0][j - 1][i + 1] += dp[1][j][i]) %= mod, (dp[0][j - 1][1] -= dp[1][j][i]) %= mod;
        }
        for (int i = 1; i <= n + 1; i++)
        {
            (dp[1][j - 1][i] += dp[1][j - 1][i - 1]) %= mod;
            // cout << j - 1 << " " << i << " " << dp[1][j - 1][i] << endl;
        }
        for (int i = n; i >= 0; i--)
        {
            (dp[0][j - 1][i] += dp[0][j - 1][i + 1]) %= mod;
            // cout << j - 1 << " " << i << " " << dp[0][j - 1][i] << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            ans = (ans + dp[0][j][i] + dp[1][j][i]) % mod;
        }
    }
    cout << (ans + mod) % mod << endl;
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