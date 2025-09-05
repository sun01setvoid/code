//P1005 矩阵取数
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
// 反向来dp
// 从中间开始，考虑前一次选谁
__int128 fac[100];
__int128 dp[100][100][100];
void solve()
{
    int n, m;
    cin >> n >> m;
    int x;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> x;
            dp[i][j][j] = x*fac[m];
        }
    }
    __int128 ans=0;
    for (int row=1;row<=n;row++){
        for (int len=2;len<=m;len++){
            for (int i=1;i+len-1<=m;i++){
                int j=i+len-1;
                dp[row][i][j]=max(dp[row][i][j-1]+dp[row][j][j]/fac[m]*fac[m-len+1],dp[row][i+1][j]+dp[row][i][i]/fac[m]*fac[m-len+1]);
            }
        }
        ans+=dp[row][1][m];
    }
    vector <int> vc;
    if (ans==0){
        cout<<0;
        return;
    }
    while (ans){
        vc.pb(ans%10);
        ans/=10;
    }
    for (int i=vc.size()-1;i>=0;i--){
        cout<<vc[i];
    }
}
signed main()
{
    IOS;
    int _ = 1;
    fac[0]=1;
    rep(i,1,80) fac[i]=fac[i-1]*2;
    //也可以fac和原dp一起在过程中做dp
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}