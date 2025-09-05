//lg1595 信封问题
//每个人必须寄出一封信，每个人必须收到一封信，每个人不能寄信给自己
//错排问题
//每个人有一个出度和一个入度’
/*   1    */   //错排公式
//f(n)=(n-1)*(f(n-2)+f(n-1))
//{这里的为什么是f(n-1)，相当于把x看成a->b的这一对（还有一对出度和一个入度）,后面的cde与x错排}
/*    2   */   //二项式反演
//n排列g(n)
//分为有i个人不在自己的位置 f(i)
//特别的i=1时为0
//g(n)与C（n,i)f(i)有关系
//可以直接反演,查找一个f[n]时可能稍快一点
#include <iostream>
using namespace std;
typedef long long LL;
LL fac[21];
int main(){ 
    int n;
    cin>>n;
    fac[0]=1;
    for (int i=1;i<=20;i++) fac[i]=fac[i-1]*i;
    int flag=-1;
    LL ans=0;
    for (int i=0;i<=n;i++){
        flag=-flag;
        ans+=flag*fac[n]/fac[i];
    }
    cout<<ans<<endl;
}