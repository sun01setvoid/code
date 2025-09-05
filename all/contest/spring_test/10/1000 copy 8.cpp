#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[105][1005][55];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof dp);
        vector <vector <int>> a(n+1,vector<int>(m+1));
        vector <int> ma(n+1),vis(n+1,0);
        for (int i=1;i<=n;i++){
            int sma=0;
            for (int j=1;j<=m;j++)  cin>>a[i][j],sma=max(sma,a[i][j]);
            ma[i]=sma;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                for (int k=0;k<=n/2+1;k++){
                    int t=k+1;
                    if (t>n/2+1) {
                        dp[i][j][k]=dp[i-1][j][k]+ma[i];
                        continue;
                    }
                    if (ma[i]==a[i][j]) dp[i][j][t]=max(dp[i][j][t],dp[i-1][j][k]+ma[i]);
                    else {
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j][k]+a[i][j]);
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+ma[i]);
                    }
                }
            }
        }
        int ans=0;
        for (int i=1;i<=m;i++) ans=max(ans,dp[n][i][n/2+1]);
        cout<<ans<<"\n";
    }
}
