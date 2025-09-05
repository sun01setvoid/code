#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
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
const ld eps = 998244353;
//-----------------------------------------------------//
void solve()
{
    int n;
    cin>>n;
    vii a(n+1);
    rep(i,1,n) cin>>a[i];
    vector<array<pair<int, int>, 2>> dp(n + 1);
    if (a[1] == 1) {
        dp[1][1] = {1, 1};
    } else if (a[1] == 0) {
        dp[1][0] = {0, 1};
    } else {
        dp[1][1] = {1, 1};
        dp[1][0] = {0, 1};
    }
        for (int i = 2; i <= n; i++) {
        if (a[i] == 1 || a[i] == -1) {
            dp[i][1].first = (dp[i - 1][0].first + dp[i - 1][0].second + dp[i - 1][1].first) % mod;
            dp[i][1].second = (dp[i - 1][0].second + dp[i - 1][1].second) % mod;
        }
        if (a[i] == 0 || a[i] == -1) {
            dp[i][0].first = (dp[i - 1][0].first + dp[i - 1][1].first) % mod;
            dp[i][0].second = (dp[i - 1][0].second + dp[i - 1][1].second) % mod;
        }
    }
    
    int ans = 0;
    if (a[n] == 1) {
        ans = dp[n][1].first;
    } else if (a[n] == 0) {
        ans = dp[n][0].first;
    } else {
        ans = (dp[n][1].first + dp[n][0].first) % mod;
    }
    cout << ans << endl;
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
