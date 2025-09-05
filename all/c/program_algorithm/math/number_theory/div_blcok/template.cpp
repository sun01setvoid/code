#include <iostream>
using namespace std;
typedef long long LL;

//sum[i,n](n/i)
//整除求和
//O(2根号n)
//  5/2=2  所以不是看因子的
//R是怎么推出来的，我也不知道
int main(){
    LL n,L,R,ans=0;
    cin>>n;
    for (L=1;L<=n;L=R+1){
        R=n/(n/L); //
        ans+=(R-L+1)*(n/L);
        cout<<L<<"-"<<R<<":"<<n/R<<endl;
    }
    cout<<ans;
}