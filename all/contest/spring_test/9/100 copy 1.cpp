#include <bits/stdc++.h>
using namespace std;
int dp[65][25][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int t,n,m;
        cin>>t>>n>>m;
        vector<int> a(n);
        for (int i=1;i<n;i++){
            cin>>a[i];
        }
        memset(dp,0x3f,sizeof dp);
        //time,position,operation
        dp[0][0][0]=0;
        for (int i=0;i<=n*t;i++){
            for (int j=1;j<n;j++){
                for (int k=0;k<=m;k++){
                    for (int s=0;s<=i;s++){
                        if (abs(a[j]-i)<=k && dp[s][j-1][k-abs(a[j]-i)]!=0x3f3f3f3f){
                            dp[i][j][k]=min(dp[i][j][k],dp[s][j-1][k-abs(a[j]-i)]+(i-s)*(i-s));
                        }
                    }
                }
            }
        }
        int ans=0x3f3f3f3f;
        for (int i=0;i<=n*t;i++){
                for (int k=0;k<=m;k++){
                    if (dp[i][n-1][k]!=0x3f3f3f3f){
                        ans=min(ans,dp[i][n-1][k]+(n*t-i)*(n*t-i));
                    }
                }
        }
        cout<<ans<<"\n";
    }
}