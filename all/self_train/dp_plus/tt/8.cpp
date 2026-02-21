// P5005 中国象棋
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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[2][1 << 6][1 << 6];
// 注意，中国象棋的蹩马腿并不是相互的
void solve()
{
    int n, m;
    cin >> n >> m;
    dp[0][0][0] = 1;
    int st = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 1 << m; j++)
        {
            for (int k = 0; k < 1 << m; k++)
                dp[st][j][k] = 0;
        }
        for (int s = 0; s < 1 << m; s++)
        {
            for (int t = 0; t < 1 << m; t++)
            {
                if (s & ~s >> 1 & t >> 2)
                    continue;
                if (t & ~t << 1 & s << 2)
                    continue;
                if (s & ~s << 1 & t << 2)
                    continue;
                if (t & ~t >> 1 & s >> 2)
                    continue;
                for (int l = 0; l < 1 << m; l++)
                {
                    if (s & ~t & l >> 1)
                        continue;
                    if (l & ~t & s << 1)
                        continue;
                    if (s & ~t & l << 1)
                        continue;
                    if (l & ~t & s >> 1)
                        continue;
                    dp[st][s][t] = (dp[st][s][t] + dp[st ^ 1][t][l]) % mod;
                }
            }
        }
        st ^= 1;
    }
    st ^= 1;
    int ans = 0;
    for (int s = 0; s < 1 << m; s++)
    {
        for (int t = 0; t < 1 << m; t++)
        {
            ans = (ans + dp[st][s][t]) % mod;
            // cout<<s<<" "<<t<<" "<<dp[st][s][t]<<endl;
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