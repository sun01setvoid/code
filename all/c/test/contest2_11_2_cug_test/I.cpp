#include <iostream>
using namespace std;
long long fac(long long x){
    long long ans=1;
    for (long long i=x;x!=0;x--){
        ans=(ans*x)%(1000000007);
    }
    return ans;
}
int main(){
    int t,n,k;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>k;

    }
}