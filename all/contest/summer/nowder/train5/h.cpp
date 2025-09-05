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
void solve()
{
    int m, s, t, n;
    cin >> m >> s >> t;
    cin >> n;
    vector<array<int, 4>> a(n + 1);
    int ma = 0;
    rep(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3], ma = max(ma, a[i][2]);
    // 所需科技点  //完成后科技点增量   //  触发生产力   ///阈值的减量
    vii pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i][1];
    int l = 1, r = ma;
    while (l <= r)
    {
        vector<vector<vector<int>>> dp(t + 1, vector<vector<int>>(n + 1, vector<int>(t + 1, -INF)));
        dp[0][0][0] = 0;
        // 前i个回合在,已完成前j个物品,剩余k个回合用于分配生产力
        int mid = (l + r) / 2;
        int ans = -INF;
        rep(i, 0, t)
        {
            rep(j, 0, n)
            {
                rep(k, 0, i)
                {
                    ans = max(ans, dp[i][j][k]);
                    if (i + 1 <= t)
                        dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + m + pre[j]);
                    if (j + 1 <= n)
                    {
                        int tm = (a[j + 1][0] + m + pre[j] - 1) / (m + pre[j]);
                        if (i + tm <= t)
                            dp[i + tm][j + 1][k + tm] = max(dp[i + tm][j + 1][k + tm], dp[i][j][k]);
                    }
                    if (j + 1 <= n)
                    {
                        int tm1 = (a[j + 1][0] - a[j + 1][3] + m + pre[j] - 1) / (m + pre[j]);
                        int tm2 = (a[j + 1][0] - a[j + 1][3] + m + pre[j] - 1) / (m + pre[j]) - (a[j + 1][2] + mid - 1) / mid;
                        if (i + tm1 <= t && k + tm2 >= 0)
                            dp[i + tm1][j + 1][k + tm2] = max(dp[i + tm1][j + 1][k + tm2], dp[i][j][k]);
                    }
                }
            }
        }
        if (ans >= s)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l == ma + 1)
    {
        cout << -1 << endl;
        return;
    }
    if (r == 0)
    {
        cout << 0 << endl;
        return;
    }
    cout << l << endl;
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