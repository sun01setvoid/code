#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e2 + 5;
const int maxm = 6e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    
};
int fac[maxn],C[maxn][maxn];
vii solve(vii a,vii b,int k)//多项式表示
{
    if(a.empty()||b.empty())return {1};
    if(!k)
    {
        int siz=min(a.size(),b.size());vii dp(siz+1);
        for(int i=0;i<=siz;i++)
        {
            dp[i]=(C[a.size()][i]*C[b.size()][i])%mod*fac[i]%mod;
        }
        return dp;
    }
    int h= 63 - __builtin_clzll(k);map<int,vector<pii>>mp;
    const int mask=(~0ll)<<(h+1);
    for(int x:a)mp[x&mask].pb({x&(~mask),0});
    for(int x:b)mp[x&mask].pb({x&(~mask),1});
    int siz=min(a.size(),b.size());vii dp(siz+1);dp[0]=1;
    const int mask2 = ~(1ll << h);
    int sum1=0,sum2=0;
    for(auto &[val,vec]:mp)
    {
        vii aa[2],bb[2];int s1=0,s2=0;
        for(auto it :vec)
        {
            int v=it.fi;
            if(it.so==0)
            {
                aa[(v>>h)&1].pb(v&mask2);s1++;
            }
            else 
            {
                bb[(v>>h)&1].pb(v&mask2);s2++;
            }
        }
        int s=min(s1,s2);vii f(s+1);
        vii f1=solve(aa[0],bb[1],k^(1ll<<h));
        vii f2=solve(aa[1],bb[0],k^(1ll<<h));
        vii ndp(siz+1);
        for(int i=0;i<f1.size();i++)
        {
            for(int j=0;j+i<=s&&j<f2.size();j++)
            {
                f[i+j]=(f[i+j]+f1[i]*f2[j]%mod)%mod;
            }
        }
        for(int i=0;i<=min(sum1,sum2);i++)
        {
            if(!dp[i])continue;
            for(int j=0;j<=s;j++)
            {
                if(!f[j])continue;
                int ayu=sum1-i;
                int byu=sum2-i;
                int ay=s1-j;
                int by=s2-j;
                for(int v1=0;v1<=min(ayu,by);v1++)
                {
                    for(int v2=0;v2<=min(ay,byu);v2++)
                    {
                        int val=dp[i]*f[j]%mod;
                        val=((val*C[ayu][v1])%mod*C[by][v1])%mod;
                        val=((val*C[ay][v2])%mod*C[byu][v2])%mod;
                        val=((val*fac[v1])%mod*fac[v2])%mod;
                        ndp[i+j+v1+v2]=(ndp[i+j+v1+v2]+val)%mod;
                    }
                }
            }
        }
        dp=ndp;sum1+=s1;sum2+=s2;
    }
    return dp;
}
void Raze()
{
    int n,k;cin>>n>>k;vii a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j)C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    vii ans=solve(a,b,k);
    ans.resize(n+1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    //cin >> _;
    while (_--)Raze(); return 0;
}