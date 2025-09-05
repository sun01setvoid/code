//lg p2602 数位dp
//注意前导0和最高位的限制
#include <iostream>
using namespace std;
typedef long long LL;
int num[20];
LL dp[20],ten[20],cnta[20],cntb[20];
//dp是无高位限制时每个数的数量
void solve(LL x,LL * cnt){
    int len=0;
    while (x){
        ++len;
        num[len]=x%10;
        x/=10;
    }
    ten[0]=1;
    for (int i=1;i<=len;i++){
        dp[i]=dp[i-1]*10+ten[i-1];    //或者dp[i]=i*ten[i-1]; 
        ten[i]=10*ten[i-1];
    }
    for (int i=len;i>=1;i--){
        for (int j=0;j<num[i];j++) cnt[j]+=ten[i-1];//外部的
        for (int j=0;j<=9;j++) cnt[j]+=num[i]*dp[i-1];//内部的,000~(num[i]-1)99
        LL num1=0;
        for (int j=i-1;j>=1;j--) num1=num1*10+num[j];//高位限制
        cnt[num[i]]+=num1+1;
        cnt[0]-=ten[i-1];//因为是从1开始，0不行
    }
}
int main(){
    LL a,b;
    cin>>a>>b;
    solve(b,cntb);solve(a-1,cnta);
    for (int i=0;i<=9;i++)  cout<<cntb[i]-cnta[i]<<" ";
}
/*      //记忆化dfs
#include <iostream>
#include <cstring>
using namespce std;
typedef long long ll;
const int N=15;
ll dp[N][N];//dp[pos][sum]表示最后pos位范围，前面出现的2的个数为sum时，数字2的总个数
int num[N],now;
ll solve(){
    int len =0;
    while (x){
        num[++len]=x%10;
        x/=10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(len,0,true,true);
}
int main(){
    ll a,b;
    cin>>a>>b;
   solve();
    
}
*/