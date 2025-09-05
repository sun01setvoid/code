//lg 10596
#include <iostream>
using namespace std;
typedef long long LL;
const int p=1e9+7, N=1e6+10;
LL  fac[N],inv[N],g[N];
int n,k;
LL c(int i,int j){
    if (j < 0 || j > i) return 0; // 添加边界检查确保安全
    return fac[i]*inv[j]%p*inv[i-j]%p;
}
LL fpow(LL a,LL k,LL m){
    LL res=1;
    while (k){
        if (k&1)    res=res*a%m;
        a=a*a%m;
        k/=2;
    }
    return res;
}
int main(){
    cin>>n>>k;
    fac[0]=1;
    for (int i=1;i<=n;i++)  fac[i]=fac[i-1]*i%p;
    inv[n]=fpow(fac[n],p-2,p);
    for (int i=n-1;i>=0;i--)  inv[i]=inv[i+1]*(i+1)%p;
    LL tmp=2;
    for (int i=n;i>=0;i--)  g[i]=tmp,tmp=tmp*tmp%p;
    for (int i=0;i<=n;i++)  g[i]=(g[i]+p-1)%p*c(n,i)%p;
    LL ans=0;
    for (int i=k;i<=n;i++){
        if (((i-k)&1)==0){
            ans=(ans+c(i,k)*g[i]%p)%p;
        }
        else{
            ans=(ans+c(i,k)*g[i]%p*(p-1)%p)%p;
        }
    }
    cout<<ans;
}