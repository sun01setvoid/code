#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#define inf 0x3f3f3f3f3f3f3f3f
const int N=500,MOD=1e9+7;
LL dp[N][N],a[N];
int main(){
    int t=1;
    int n,m,V;
    cin>>t;
    while (t--){
        cin>>n>>m>>V;
        for (int i=1;i<=n;i++)  cin>>a[i];
        memset(dp,0x3f,sizeof dp);
        for (int i=0;i<=V;i++)  dp[i][0]=1;
        for (int i=1;i<=n;i++){
            for (int j=a[i];j<=V;j++){
                for (int k=1;k<=m;k++){
                    if (dp[j-a[i]][k-1]!=inf){
                        if (dp[j][k]==inf)   dp[j][k]=0;
                        dp[j][k]=(dp[j][k]+dp[j-a[i]][k-1])%MOD;
                    }
                }
            }    
        }
        cout<<dp[V][m]<<endl;
    }
}