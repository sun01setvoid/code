//所以标答的dp是表示这个时候的期望，DAG图
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int N=10,M=5010;
int s[N],c[N];
double p[N],dp[1<<9][M];
int main(){
    int n,x;
    cin>>n>>x;
    for (int i=0;i<n;i++){
        cin>>s[i]>>c[i]>>p[i];
        p[i]=p[i]/100.0;
    }
    double ans=0;
    for (int i=x;i>=0;i--){
        for (int j=0;j<(1<<n);j++){
            for (int k=0;k<n;k++){
                int xx=i+c[k];
                if (xx>x)   continue;
                int ss=j^(1<<k);
                if (j>>k&1) dp[j][i]=max(dp[j][i],p[k]*(dp[ss][xx]+s[k])+(1.0-p[k])*dp[j][xx]);
                else    dp[j][i]=max(dp[j][i],(1.0-p[k])*dp[j][xx]);
                ans=max(ans,dp[j][i]);
            }
        }
    }
    cout<<fixed<<setprecision(7)<<ans<<"\n";
}