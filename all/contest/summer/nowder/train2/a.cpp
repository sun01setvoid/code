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
const int mod = 998244353;
//-----------------------------------------------------//
void solve()
{
    int n;
    cin>>n;
    vii a(n+1);
    rep(i,1,n) cin>>a[i];
    vector <vector<pii>> dp(n+1,vector<pii>(2,{0,0}));
    
    if (a[1] == 1) {
        dp[1][1] = {1, 1};
    } else if (a[1] == 0) {
        dp[1][0] = {0, 1};
    } else {
        dp[1][1] = {1, 1};
        dp[1][0] = {0, 1};
    }
    for (int i=2;i<=n;i++){
        if (a[i]==1){
            dp[i][1].fi=(dp[i][1].fi+dp[i-1][0].fi+dp[i-1][0].se+dp[i-1][1].fi)%mod;
            dp[i][1].se=(dp[i][1].se+dp[i-1][1].se+dp[i-1][0].se)%mod;
        }else if(a[i]==0){
            dp[i][0].fi=(dp[i][0].fi+dp[i-1][1].fi+dp[i-1][0].fi)%mod;
            dp[i][0].se=(dp[i][0].se+dp[i-1][1].se+dp[i-1][0].se)%mod;
        }else{
            dp[i][1].fi=(dp[i][1].fi+dp[i-1][0].fi+dp[i-1][0].se+dp[i-1][1].fi)%mod;
            dp[i][1].se=(dp[i][1].se+dp[i-1][1].se+dp[i-1][0].se)%mod;
            dp[i][0].fi=(dp[i][0].fi+dp[i-1][1].fi+dp[i-1][0].fi)%mod;
            dp[i][0].se=(dp[i][0].se+dp[i-1][1].se+dp[i-1][0].se)%mod;
        }
    }
    cout<<(dp[n][1].first + dp[n][0].first) % mod<<endl;
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