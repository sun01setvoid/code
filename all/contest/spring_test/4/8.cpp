#include <iostream>
#include <vector>
using namespace std;
//前i个物品，划分成j轮
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int n,k;
    while (t--){
        cin>>n>>k;
        vector <vector<int>> p(n+1,vector<int>(k+1,0));
        vector <vector<int>> dp(n+1,vector<int>(k+1,0));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=k;j++){
                cin>>p[i][j];
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=k;j++){
                dp[i][j]=max(dp[i-1][j]+p[i][j],dp[i-1][j-1]+p[i][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);//第j轮可能不妨东西
            }
        }
        int ans=0;
        for (int j=1;j<=k;j++)  ans=max(dp[n][j],ans);
        cout<<ans<<endl;
    }
}