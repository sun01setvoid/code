#include <iostream>
using namespace std;
typedef long long LL;
const int MOD=1e9+7,N=2e5+10;
LL inv [N],fac[N];
LL fpow(LL a, LL k, LL p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1)
        {
            res = res * a % p;
        }
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fac[0]=fac[1]=1;
    LL tmp=1;
    for (int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%MOD,tmp=tmp*2%MOD;
    inv[200000]=fpow(tmp,MOD-2,MOD);
    for (int i=200000-1;i>=0;i--)    inv[i]=inv[i+1]*2%MOD;
    int n;
    int t=1;
    cin>>t;
    while (t--){
        cin>>n;
        LL ans=0,sum=0;
        for (int i=1;i<=n;i++){
            cin>>tmp;
            if (i==1)   {sum+=tmp;continue;}
            ans=(ans+sum*tmp)%MOD;
            sum=(sum+tmp)%MOD;
        }
        cout<<ans<<" "<<fac[n]*fac[n-1]%MOD*inv[n-1]%MOD;
    }
}