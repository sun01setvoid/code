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
    int n, v;
    cin >> n >> v;
    vector<int> hs(n), ss(n), ds(n);
    for (int i = 0; i < n; i++)
        cin >> hs[i] >> ss[i] >> ds[i];
    int ans = 0;
    for (int unused = 0; unused < v; unused++)
    {
        int used = v - unused;
        vector<vii> values(used + 1);
        for (int i = 0; i < n; i++)
            if (ss[i] <= used)
                values[ss[i]].eb(1ll * unused * ds[i] - hs[i]);
        vector<int> dp(used + 1, -INF);
        dp[0] = 0;
        for (int i = 1; i <= used; i++)
        {
            int k = min(used / i, (int)values[i].size());
            nth_element(values[i].begin(), values[i].begin() + k - 1, values[i].end());

            for (int idx = 0; idx < k; idx++)
            {
                for (int cur = used; cur >= i; cur--)
                {
                    dp[cur] = max(dp[cur], dp[cur - i] - values[i][idx]);
                }
            }
        }

        ans = max(ans, dp[used]);
    }
    cout << ans << '\n';
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