#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010],dp[1010][1010];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i];
    }
    memset(dp,0x3f,sizeof dp);
    for (int i=0;i<=m;i++)    dp[i][0]=0;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if (j>=a[i])
                dp[i][j]=min(dp[i][j],dp[i-1][j-a[i]]+1);
            if (j+a[i]>=n)
                dp[i][j]=min(dp[i][j],dp[i-1][2*n-a[i]-j]+1);
        }
    }
    if (dp[m][n]==0x3f3f3f3f)
        cout<<-1;
    else    cout<<dp[m][n];
}
