#include <iostream>
#include <cstring>
using namespace std;//思考dp[n][k]超标，或许可以用dp[n][m],m为低谷数(想到dp是因为处理最后一个低谷时对前面不影响)
long long dp[3010][1550];//(最小操作数)
int main(){
    int n,k,a[3010],opr[3010],ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    //先找操作数
    for (int i=2;i<=n-1;i++){
        opr[i]=max(a[i]-a[i-1],a[i]-a[i+1])+1;
        if (opr[i]<=0)  opr[i]=0;//低谷不用操作
    }
    for (int i=3;i<=n;i++){
        for (int j=1;j<=(i-1)/2;j++)//i个数，最多有（i-1)/个峰数
            if(j<=(i-2)/2)
            dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+opr[i-1]);//注意他（i-1）可能达不到j（达不到j的就是0）,操作i-1和不操作i-1
            else
            dp[i][j]=dp[i-2][j-1]+opr[i-1];
    }
    for (int i=0;i<=(n-1)/2;i++){
        if (dp[n][i]<=k)    ans=i;
    }
    cout<<ans;
    getchar();
    getchar();
}