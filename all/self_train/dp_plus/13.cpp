// P3089 Pogo-Cow S
// 单调队列优化
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
const int maxn = 1010;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
pii a[maxn];
deque<pii> pre[maxn];
deque<pii> suf[maxn];
// 也可以发现随着i打dp[i][j]能取到的dp[j][k]越多，所以定义now,不断扩展
// 然后虽然dp[i][j]和dp[i-1][j]没有直接关系，但可以从数值中发现他们有关系
// 因为一段其实是锁死的，所以没必要用单调队列优化

// 而我这种就是正经的单调队列优化（奇怪的）
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i].pb({0, a[i].se});
        for (auto cur : pre[i])
        {
            ans = max(ans, cur.se);
        }
        for (int j = n; j >= i + 1; j--)
        {
            while (pre[i].size() && a[j].fi - a[i].fi < pre[i].front().fi)
                pre[i].pop_front();
            while (pre[j].size() && pre[j].back().se < pre[i].front().se + a[j].se)
            {
                pre[j].pop_back();
            }
            pre[j].pb({a[j].fi - a[i].fi, pre[i].front().se + a[j].se});
        }
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i].pb({0, a[i].se});
        for (auto cur : suf[i])
        {
            ans = max(ans, cur.se);
        }
        for (int j = 1; j <= i - 1; j++)
        {
            while (suf[i].size() && a[i].fi - a[j].fi < suf[i].front().fi)
                suf[i].pop_front();
            while (suf[j].size() && suf[j].back().se < suf[i].front().se + a[j].se)
            {
                suf[j].pop_back();
            }
            suf[j].pb({a[i].fi - a[j].fi, suf[i].front().se + a[j].se});
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