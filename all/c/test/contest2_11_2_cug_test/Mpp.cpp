//另起一版plus(超时)
#include <iostream>
#include <cstring>
using namespace std;//思考dp[n][k]超标，或许可以用dp[n][m],m为低谷数(想到dp是因为处理最后一个低谷时对前面不影响)
long long dp[2][50010];//(最小操作数)
int main(){
    int n,k,a[100010],opr[100010],ans=0,cnt=3;//cnt是人数
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    //先找操作数
    for (int i=2;i<=n-1;i++){
        opr[i]=max(a[i]-a[i-1],a[i]-a[i+1])+1;
        if (opr[i]<=0)  opr[i]=0;//低谷不用操作
    }
    while (cnt<=n)
    {
        memcpy(dp[0],dp[1],(1+(cnt-2)/2)*8);//先除再乘
        for (int j=(cnt-1)/2;j>=1;j--)//i个数，最多有（i-1)/个峰数
            if(j<=(cnt-2)/2)
                dp[1][j]=min(dp[1][j],dp[0][j-1]+opr[cnt-1]);//注意他（i-1）可能达不到j（达不到j的就是0）,操作i-1和不操作i-1
            else
                dp[1][j]=dp[0][j-1]+opr[cnt-1];
        cnt++;
    }
    for (int i=0;i<=(n-1)/2;i++){
        if (dp[1][i]<=k)    ans=i;
    }
    cout<<ans;
    getchar();
    getchar();
}