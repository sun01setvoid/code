#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int MOD=1e9+7;
int n,m,k;
char mp[105][105];
int dp[105][105][8005];
//正负用mul分辨
//一般dfs反向记忆化(有时候反向难就最好不用，正向的化dfs会超时吧，因为正向过的不是已经得到答案的)，dp可以正向推理也可反向
void solve(){
    int ans=0;
    cin>>n>>m>>k;
    getchar();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
        getchar();
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    for (int st=0;st<=k*k*k-1;st++)
            dp[i][j][st]=0;
    dp[1][1][k+(mp[1][1]-'0')%k]=1; // mul=1,cur=mp[1][1]-'0';
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int st=0;st<=k*k*k-1;st++){
                int sum=st/(k*k),mul=st/k%k,cur=st%k;
                if (dp[i][j][st]==0) continue;
                if (i==n && j==m && (sum+mul*cur)%k==0) ans=(ans+dp[i][j][st])%MOD;
                if (j+1<=m){
                    if (isdigit(mp[i][j+1]))dp[i][j+1][sum*k*k+mul*k+(cur*10+mp[i][j+1]-'0')%k]=(dp[i][j+1][sum*k*k+mul*k+(cur*10+mp[i][j+1]-'0')%k]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                    else if (!isdigit(mp[i][j+1]) && isdigit(mp[i][j])){
                        if(mp[i][j+1]=='+') dp[i][j+1][(sum+mul*cur)%k*k*k+k]=(dp[i][j+1][(sum+mul*cur)%k*k*k+k]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                        else if (mp[i][j+1]=='-') dp[i][j+1][(sum+mul*cur)%k*k*k+k*(k-1)]=(dp[i][j+1][(sum+mul*cur)%k*k*k+k*(k-1)]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                        else dp[i][j+1][sum*k*k+cur*mul%k*k]=(dp[i][j+1][sum*k*k+cur*mul%k*k]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                    }
                }
                if (i+1<=n){
                    if (isdigit(mp[i+1][j]))dp[i+1][j][sum*k*k+mul*k+(cur*10+mp[i+1][j]-'0')%k]=(dp[i+1][j][sum*k*k+mul*k+(cur*10+mp[i+1][j]-'0')%k]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                    else if (!isdigit(mp[i+1][j]) && isdigit(mp[i][j])){
                        if(mp[i+1][j]=='+') dp[i+1][j][(sum+mul*cur)%k*k*k+k]=(dp[i+1][j][(sum+mul*cur)%k*k*k+k]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                        else if (mp[i+1][j]=='-') dp[i+1][j][(sum+mul*cur)%k*k*k+k*(k-1)]=(dp[i+1][j][(sum+mul*cur)%k*k*k+k*(k-1)]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                        else dp[i+1][j][sum*k*k+cur*mul%k*k]=(dp[i+1][j][sum*k*k+cur*mul%k*k]+dp[i][j][sum*k*k+mul*k+cur])%MOD;
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}