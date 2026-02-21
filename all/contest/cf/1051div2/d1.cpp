
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 300 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[2][maxn][maxn];
int a[maxn];
void solve()
{
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0][0] = 1;
    int st = 1;
    for (int i = 1; i <= n; i++)
    {
        int d = a[i];
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                dp[st][j][k] = dp[st ^ 1][j][k];
            }
        }
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (d >= j)
                    dp[st][d][k] = (dp[st][d][k] + dp[st ^ 1][j][k]) % mod;
                else if (d >= k)
                    dp[st][j][d] = (dp[st][j][d] + dp[st ^ 1][j][k]) % mod;
            }
        }
        st ^= 1;
    }
    st ^= 1;
    int ans = 0;
    for (int j = 0; j <= n; j++)
    {
        for (int k = 0; k <= n; k++)
        {
            ans = (ans + dp[st][j][k]) % mod;
        }
    }
    cout << ans % mod << endl;
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