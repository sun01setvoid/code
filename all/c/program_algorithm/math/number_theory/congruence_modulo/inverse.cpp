/*连续数字逆元递推*/
//lg3811 卡大量输出
/*
#include <cstdio>
using namespace std;
const int N=3e6+10;
typedef long long LL;
LL inv[N];
int main(){
    int n,p;
    inv[1]=1;
    scanf("%d %d",&n,&p);
    for (int i=2;i<=n;i++){ //互质才有逆元
        inv[i]=(p-inv[p%i]*(p/i)%p);
    }
    for (int i=1;i<=n;i++) printf("%d\n",inv[i]);
}
*/
/*连续阶乘逆元递推*/
/*
#include <cstdio>
using namespace std;
const int N=3e6+10;
typedef long long LL;
LL inv_fac[N],fac[N];
LL qpow(LL a,LL n,LL p){
    LL res=1;
    while (n){
        if (n&1)    res=res*a%p;
        a=a*a%p;
        n>>=1;    
    }
    return res;
}
int main(){
    int n,p;
    fac[0]=1;
    scanf("%d %d",&n,&p);
    for (int i=1;i<=n;i++)  fac[i]=i*fac[i-1]%p;
    inv_fac[n]=qpow(fac[n],n-2,p);
    for (int i=n-1;i>=0;i--){ //互质才有逆元
        inv_fac[i]=inv_fac[i+1]*(i+1)%p;
    }
    for (int i=0;i<=n;i++) printf("%d\n",inv_fac[i]);
}
*/