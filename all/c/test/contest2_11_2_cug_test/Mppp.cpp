#include <stdio.h>
void fact(long long n){
    for (long long i=2;i<=n/i;i++){
       if (n%i==0){
           long long cnt=0;
            while (n%i==0)    cnt++,n/=i;
            printf("%lld %lld\n",i,cnt);
       }
    }
    if (n)
        printf("%lld %lld\n",n,1);
}
long long f(long long n){
    return !n?1:n*f(n-1);
}
int main(){
    long long n,res;
    scanf("%lld",&n);
    res=f(n);
    printf("%lld\n",res);
    fact(res);
    return 0;
}