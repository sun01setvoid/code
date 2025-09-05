// P3558 [POI2013] BAJ-Bytecomputer
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
    vii a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vii> dp(n + 1, vii(3, INF));
    dp[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (dp[i - 1][0] != INF) 
        {
            for (int j = 0; j <= a[i] + 1; j++)
                dp[i][j] = min(dp[i][j], dp[i - 1][0] + a[i] + 1 - j);
        } 
        if (dp[i - 1][1] != INF && a[i] + 1 >= 1)
            dp[i][a[i] + 1] = min(dp[i][a[i] + 1], dp[i - 1][1]);
        if (dp[i - 1][2] != INF)    dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1 - a[i]);
    }
    int ans = INF;
    for (int i = 0; i <= 2; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    if (ans==INF) cout<<"BRAK";
    else cout<<ans;
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