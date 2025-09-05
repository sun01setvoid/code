//P1880 石子合并(圆形)
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
int dp[220][220], gp[220][220], pre[220];
int n;
void solve()
{
    cin >> n;
    vii a(2 * n + 1);
    int sum = 0;
    rep(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    rep(i, 1, n) a[n + i] = a[i], pre[n + i] = pre[n + i - 1] + a[n + i];
    n = 2 * n;
    rep(i, 1, n) rep(j, i, n)
    {
        dp[i][j] = 0, gp[i][j] = INF;
        if (i == j)
            gp[i][j] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = max(dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1], dp[i][j]);
                gp[i][j] = min(gp[i][k] + gp[k + 1][j] + pre[j] - pre[i - 1], gp[i][j]);
            }
            // cout << i << " " << j << " " << gp[i][j] << endl;
        }
    }
    int mi = INF, ma = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        mi = min(gp[i][i + n / 2 - 1], mi);
        ma = max(dp[i][i + n / 2 - 1], ma);
    }
    cout << mi << endl
         << ma;
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