#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
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
        a = a * a % p;
    }
    return res;
}
LL inv1,inv2;
inline LL dfs(int n){
    if (n%5==0){
        int k=n/5;
        return (fpow(2,k,MOD)+MOD-1)%MOD*fpow(fpow(2,k,MOD),MOD-2,MOD)%MOD;
    }
    else{
        int k=(n-2)/5+1;
        return (fpow(2,k,MOD)+MOD-1)%MOD*fpow(fpow(2,k,MOD),MOD-2,MOD)%MOD;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    int n;
    cin>>t;
    inv1=fpow(2,MOD-2,MOD);
    inv2=fpow(4,MOD-2,MOD);
    while (t--){
        LL ans=0;
        cin>>n;
        if (n%5==2||n%5==0) ans=1;
        else if (n==1)  ans=inv1;
        else if (n==3)  ans=(inv1+inv2)%MOD;
        else if (n%5==1)    ans=(inv1*dfs(n-1)%MOD+inv1*dfs(n-4)%MOD)%MOD;
        else if (n%5==3)    ans=(inv1*dfs(n-1)%MOD+inv1)%MOD;
        else if (n%5==4)    ans=(inv1*dfs(n-4)%MOD+inv1)%MOD;
        cout<<ans<<endl;
    }
}