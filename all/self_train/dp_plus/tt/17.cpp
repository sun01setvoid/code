//P11030
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define pa pair<int,int>
#define ld long double
#define vii vector<int>
#define pb push_back
#define debug(x) cerr<<#x<<'='<<(x)<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int z=5e5+10;
const int zz=5e5;
const int B=2000;
const int inf=1e12;
const int mod=998244353;
const int N=13;
struct mat{
    int a[N][N];
    mat(){memset(a,0,sizeof(a));}
    mat operator *(const mat &t){
        mat res;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<N;k++)
                    res.a[i][k]=(res.a[i][k]+a[i][j]*t.a[j][k]%mod)%mod;
        return res;
    }
};
mat fp(mat a,int b){
    mat res;
    for(int i=0;i<N;i++)res.a[i][i]=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b/=2;
    }
    return res;
}
int dp[2][N][N];
void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int st = 1;
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j <N; j++)
        {
            for (int k = 0; k <N; k++)
                dp[st][j][k] = dp[st ^ 1][j][k];
        }
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                dp[st][j + 1][j + 2] = (dp[st][j + 1][j + 2] + 1) % mod;
                for (int k = j; k >= 1; k--)
                    dp[st][k][j + 2] = (dp[st][k][j + 2] + dp[st ^ 1][k][j + 1])%mod;
            }
        }
        st ^= 1;
    }
    st ^= 1;
    mat ans;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)ans.a[i][j]=dp[st][i][j];
    for(int i=0;i<N;i++)ans.a[i][i]=1; 
    ans=fp(ans,n);
    cout<<ans.a[1][s2.size()+1]<<endl;
}
signed main(){
    IOS;
    int t=1;
    //cin>>t;
    while(t--)solve();
}