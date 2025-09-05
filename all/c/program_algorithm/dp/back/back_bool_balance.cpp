#include <bits/stdc++.h>
using namespace std;
int dp[110][10010],a[110];
#define inf 0x3f3f3f3f
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        int S=0;
        for (int i=1;i<=n;i++) cin>>a[i],S+=a[i];
        memset(dp,0x3f,sizeof dp);
        dp[0][0]=1;
        for (int i=1;i<=n;i++){
            for (int j=S;j>=0;j--){
                dp[i][j]=dp[i-1][j];
                if (dp[i-1][abs(j-a[i])]!=inf) dp[i][j]=1;//abs
                if (j+a[i]<=S && dp[i-1][j+a[i]]!=inf) dp[i][j]=1;
            }//写正向的比较好，不会很乱，这样就很乱
        }
        int cnt=0;
        for (int i=1;i<=S;i++) {
            if (dp[n][i]==inf) cnt++;
        }
        cout<<cnt<<endl;
        for (int i=1;i<=S;i++){
            if (dp[n][i]==inf)    cout<<i<<" ";
        }
        if (cnt)    cout<<endl;
    }
}