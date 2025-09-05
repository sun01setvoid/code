#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n,m;cin>>n>>m;
    vector<vii>dp(2,vii(2*m*n+5));
    vii tmp(m*2+2);
    int ct=n*m+2;
    dp[1][ct]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=2*m+1;j++)cin>>tmp[j];
        int ans=0;
        for(int j=0;j<=i*m;j++)dp[i&1][j+ct]=0;
        for(int j=0;j<=i*m;j++){
            for(int k=m+1;k<=2*m+1;k++){
                dp[i&1][j+ct+k-1-m]=(dp[i&1][j+ct+k-1-m]+dp[(i+1)&1][j+ct]*tmp[k]%mod)%mod;
            }
        }
        for(int j=0;j<=(i+1)*m;j++)ans=(ans+dp[i&1][j+ct])%mod;
        cout<<ans<<" ";
    }
    cout<<endl;
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