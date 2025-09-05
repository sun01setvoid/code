//P1156 垃圾陷阱
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
int dp[110][3010];
void solve()
{
    int D, G;
    cin >> D >> G;
    vector<array<int, 3>> tmp(G + 1);
    vector<vii> dp(G + 1, vii(G * 30 + 20, -INF)); // 前i个物品，能够存活j时间，达到的最大高度
    vii cnt(10 + G * 30);
    for (int i = 1; i <= G; i++)
    {
        int t, f, h;
        cin >> t >> f >> h;
        tmp[i] = {t, f, h};
        cnt[t] += h;
    }
    sort(tmp.begin() + 1, tmp.end());
    dp[0][10] = 0;
    for (int i = 1; i <= G; i++)
    {
        for (int j = 0; j <= 10 + G * 30; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j == tmp[i][0] && dp[i - 1][j] + cnt[tmp[i][0]] >= D)
            {
                cout << tmp[i][0] << endl;
                return;
            }
            if (j > tmp[i][0])
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + tmp[i][2]);
            if (j - tmp[i][1] >= tmp[i][0])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - tmp[i][1]]);
            if (dp[i][j] >= D)
            {
                cout << tmp[i][0] << endl;
                return;
            }
        }
    }
    int ans = 10;
    for (int j = 10 + G * 30; j >= 0; j--)
    {
        if (dp[G][j] == 0)
            ans = max(ans, j);
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