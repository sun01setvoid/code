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
    int n;
    cin >> n;
    vii a(n + 1), b(n + 1);
    vector<pii> c(n + 1);
    int sum = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n)
    {
        c[i].fi = a[i] - b[i];
        if (c[i].fi < 0)
            sum += c[i].fi;
        c[i].se = a[i];
    }
    sort(c.begin() + 1, c.begin() + n + 1);
    if (c[1].fi > 0 || c[n].fi < 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> dp(-sum + 1, -1);
    dp[-sum] = 0;
    dp[-sum + c[1].fi] = c[1].se;
    for (int i = 2; i <= n; i++)
    {
        if (c[i].fi <= 0)
            for (int j = 0; j <= -sum + c[i].fi; j++)
            {
                if (dp[j - c[i].fi] != -1)
                    dp[j] = max(dp[j], dp[j - c[i].fi] + c[i].se);
            }
        else
            for (int j = -sum; j >= c[i].fi; j--)
            {
                if (dp[j - c[i].fi] != -1)
                    dp[j] = max(dp[j], dp[j - c[i].fi] + c[i].se);
            }
    }
    cout << dp[-sum] << endl;
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