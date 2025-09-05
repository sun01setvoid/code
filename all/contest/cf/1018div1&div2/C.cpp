#include <iostream>
using namespace std;
typedef long long LL;
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1010;
LL mp[N][N],m[N][N];
LL a[N],b[N];
LL dp1[N][2],dp2[N][2];
int t,n;
LL solve(LL dp[][2],LL c[]){
    dp[1][1]=c[1];
    for (int i=2;i<=n;i++){
        bool f=0,vis=0,st=0;
        for (int j=1;j<=n;j++){
            if (mp[i][j]==mp[i-1][j]){
                f=1;
            }
            if (mp[i][j]+1==mp[i-1][j]){
                vis=1;
            }
            if (mp[i][j]==mp[i-1][j]+1){
                st=1;
            }
        }
        if (f){
            if (!vis){
                dp[i][1]=dp[i-1][0]+c[i];
                if (!st)    dp[i][0]=dp[i-1][1];
                else dp[i][0]=inf;
            }
            else{
                dp[i][1]=inf;
                if (!st)    dp[i][0]=dp[i-1][1];
                else dp[i][0]=inf;
            }
        }
        else{
            if (!vis){
                if (!st) dp[i][0]=min(dp[i-1][1],dp[i-1][0]);
                else dp[i][0]=dp[i-1][0];
                dp[i][1]=min(dp[i-1][1],dp[i-1][0])+c[i];
            }
            else{
                dp[i][1]=dp[i-1][1]+c[i];
                if (!st){
                    dp[i][0]=min(dp[i-1][1],dp[i-1][0]);
                }
                else{
                    dp[i][0]=dp[i-1][0];
                }
            }
        }
    }
    return min(dp[n][1],dp[n][0]);
}
int main(){
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>m[i][j];
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++)  cin>>b[i];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                mp[i][j]=m[i][j];
        LL ans=0;
        LL res=solve(dp1,a);
        if (res>=inf){
            cout<<-1<<"\n";continue;
        }
        else ans+=res;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                mp[i][j]=m[j][i];
        res=solve(dp2,b);
        if (res>=inf){
            cout<<-1<<"\n";continue;
        }
        else ans+=res;
        cout<<ans<<"\n";
    }
}