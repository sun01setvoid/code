#include <iostream>
using namespace std;
typedef long long LL;
int main(){
    LL n;
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        LL ans=0;
        for (int i=1;i<=n;i++){
            ans+=abs(n-i+1-i);
        }
        cout<<ans/2+1<<"\n";
    }
}
//一个环做差,只为偶数
//可以将偶数看做0,奇数看做1,进行异或，因为每个都出现两次，所以是偶数
//加减法，判断奇偶性，可看作异或

//一个环内的数的和为2(y-x)(x(min),y(max))
//那就是大的几个去减小的