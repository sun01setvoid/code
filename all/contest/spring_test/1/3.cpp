#include <iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int main(){
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        if (n%2==1)    n=n-1;
        n=n/2;
        cout<<n*(n+1)%mod<<endl;
    }
}