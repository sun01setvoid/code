#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
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
const int maxn = 1e2 + 5;
const int maxm = 4e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n,m,a[maxn];
void solve()
{
    cin>>n>>m;vector<vii>ma(n+1,vii(n+1,0));
    int mx=0,mi=INF;
    for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),mi=min(mi,a[i]);
    vector<vector<vii>>dp(n+2,vector<vii>(n+2,vii(mx+2)));
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ma[i][j]=max(ma[i][j-1],a[j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=ma[i][j];k<=mx;k++)dp[i][j][k]=INF;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=mx;j++)
        {
            dp[i][i][j]=j-a[i];
        }
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;int s=ma[i][j],mi=INF;
            for(int k=i;k<j;k++)
            {
                mi=min(mi,dp[i][k][s]+dp[k+1][j][s]);
            }
            dp[i][j][s]=mi;
            for(int k=s+1;k<=mx;k++)dp[i][j][k]=dp[i][j][k-1]+1;
        }
    }
    if(m==1)
    {
        cout<<dp[1][n][mx]<<endl;return ;
    }
    //m==2,一个值为mi-(mx-1),另一个为mx，
    //特判若初始全为mx，ans=1
    bool f=1;
    for(int i=1;i<=n;i++)if(a[i]!=mx)f=0;;
    if(f){cout<<"1"<<endl;return ;}
    int res=INF;
    for(int v=mi;v<mx;v++)
    {
        int ans=0;int l=1;
        for(l;l<=n;l++)
        {
            if(a[l]<=v)break;
        }
        while(l<=n)
        {
            for(l;l<=n;l++)
            {
                if(a[l]<=v)break;
            }
            int r;
            for(r=l;r<=n;r++)
            {
                if(a[r]<=v)continue;
                else {r--;break;}
            }
            ans+=dp[l][r][v];
            l=r+1;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>v)ans+=(mx-a[i]);
        }
        debug(res);
        res=min(res,ans);
    }
    cout<<res<<endl;
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