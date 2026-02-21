//P2569 SCOI 股票交易
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
const int maxn = 2010;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int t, maxp, w;
int dp[maxn][maxn];
int q1[maxn], q2[maxn];
void solve()
{
    cin >> t >> maxp >> w;
    vii ma(maxp + 1, 0);
    for (int i = 1; i <= maxp; i++)
        ma[i] = -inf;
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= maxp; j++)
            dp[i][j] = -inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= t; i++)
    {
        int ap, bp, as, bs;
        cin >> ap >> bp >> as >> bs;
        for (int j = 0; j <= maxp; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (i >= w + 1)
                ma[j] = max(ma[j], dp[i - w - 1][j]);
        }
        int hh = 0, tt = -1;
        for (int j = 0; j <= maxp; j++)
        {
            if (hh <= tt && q1[hh] < j - as)
                hh++;
            while (hh <= tt && q2[tt] < ma[j] + j * ap)
                tt--;
            q1[++tt] = j;
            q2[tt] = ma[j] + j * ap;
            dp[i][j] = max(dp[i][j], q2[hh] - j * ap);
        }
        hh = 0, tt = -1;
        for (int j = maxp; j >= 0; j--)
        {
            if (hh <= tt && q1[hh] > j + bs)
                hh++;
            while (hh <= tt && q2[tt] < ma[j] + j * bp)
                tt--;
            q1[++tt] = j;
            q2[tt] = ma[j] + j * bp;
            dp[i][j] = max(dp[i][j], q2[hh] - j * bp);
        }
    }
    int ans = 0;
    for (int j = 0; j <= maxp; j++)
        ans = max(dp[t][j], ans);
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