//P 1896 SCOI2005 互不侵犯
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
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[2][1 << 9][45];
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k >= 42)
    {
        cout << 0 << endl;
        return;
    }
    int st = 1;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s < 1 << n; s++)
        {
            if (s & s << 1)
                continue;
            for (int sz = 0; sz <= 41; sz++)
                dp[st][s][sz] = 0;
        }
        for (int s = 0; s < 1 << n; s++)
        {
            if (s & s << 1)
                continue;
            int cnt1 = __builtin_popcountll(s);
            for (int t = 0; t < 1 << n; t++)
            {
                if (s & t || s & t << 1 || s & t >> 1)
                    continue;
                int cnt2 = __builtin_popcountll(t);
                for (int sz = cnt2; sz <= 41 - cnt1; sz++)
                {
                    dp[st][s][sz + cnt1] += dp[st ^ 1][t][sz];
                }
            }
        }
        st ^= 1;
    }
    int ans = 0;
    st = st ^ 1;
    for (int i = 0; i < 1 << n; i++)
    {
        ans += dp[st][i][k];
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