//答案包错的代码
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
思考dp[n][k]超标，或许可以用dp[n][m],m为低谷数(想到dp是因为处理最靠后的一个低谷时对前面不影响)
可以由dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+opr[i-1])
看到j只与j，j-1有关调换位置处理dp[m][n]
dp[i][j]=min(dp[i-1][j-2]+opr[j-1],dp[i][j-1]),这是以是否有最靠后的一个低谷未分类
这样就是滚动的，考虑空间优化，变成一维；
dp[j]=(dp[j-2]+opr[j-1],dp[j-1])(从前往后因为有i时更近的j-1(此时dp[i-1][j-2]已经被更新为dp[i][j-2])，所以好像不能这么优化？因为此时他是i-1的j-1)
只能时dp[2][j]
那不如原来的dp[3][j]
*/
long long dp[100010];//(最小操作数)
int main(){
    int n,k,a[100010],opr[100010],ans=1,fans;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    //先找操作数
    for (int i=2;i<=n-1;i++){
        opr[i]=max(a[i]-a[i-1],a[i]-a[i+1])+1;
        if (opr[i]<=0)  opr[i]=0;//低谷不用操作
    }
    for (int j=3;j<=n;j++){
        dp[j]=min(dp[j-2]+opr[j-1],dp[j-1]);
        if (dp[j]<=k) ans++;
        else break;
    }
    //ans记录峰数
    cout<<ans-1;
}
