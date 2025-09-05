// P1879 USACO06NOV Corn Field G
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e8;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[2][1 << 12];
int a[15];
void solve()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            a[i] = a[i] * 2 + x;
        }
    }
    dp[0][0] = 1;
    int st = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[st][j] = 0;
        }
        for (int j = 0; j < (1 << n); j++)
        {
            if (j & (j << 1))
                continue;
            if ((j | a[i]) != a[i])
                continue;
            for (int k = 0; k < (1 << n); k++)
            {
                if (k & (k << 1))
                    continue; 
                if (j & k)
                    continue;                       
                (dp[st][j] += dp[st ^ 1][k]) %= mod; //%=
            }
        }
        st ^= 1;
    }
    int ans = 0;
    st = st ^ 1;
    for (int i = 0; i < 1 << n; i++)
    {
        // cout << i << " " << dp[0][i] << endl;
        (ans += dp[st][i]) %= mod; //%=
        // ans = (ans + dp[st][i]) % mod;
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