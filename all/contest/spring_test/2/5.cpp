#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    int t;
    ll n,k,c;
    cin>>t;
    while (t--){
        cin>>n>>k;
        if (k%2==1) cout<<0<<endl;
        else{
            c=k/2;
            ll d=(n-c)/(2*c);
            ll r=(n-c)%(2*c);
            ll ans=(1+d)*d*c;
            for (ll i=1;i<=r;i++){
                ans+=d+1;
            }
            cout<<c<<" "<<d<<" "<<r<<endl;
            cout<<ans<<endl;
        }
    }
}