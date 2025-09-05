//P1063 能量项链
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
const ld eps = 1e-7;
//-----------------------------------------------------//
pii a[220];
int tmp[220];
int dp[220][220];
void solve()
{
    int n;
    cin>>n;
    rep(i,1,n) cin>>tmp[i];
    rep(i,1,n) tmp[n+i]=tmp[i];
    n=2*n;
    rep(i,1,n-1) a[i]=make_pair(tmp[i],tmp[i+1]);
    for (int len=2;len<=n;len++){
        for (int i=1;i+len-1<=n-1;i++){
            int j=i+len-1;
            for (int k=i;k<j;k++){
                dp[i][j]=max(dp[i][k]+dp[k+1][j]+a[i].fi*a[k].se*a[j].se,dp[i][j]);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n/2;i++){
        int j=i+n/2-1;
        ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}