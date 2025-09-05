#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll r,b,m;
    int t;
    cin>>t;
    while (t--){
        cin>>r>>b>>m;
        if (r==0 && b==0)   {cout<<"Bob"<<endl;continue;}
        if (b%2==0){
            if (r%4==0) cout<<"Bob"<<endl;
            else    cout<<"Alice"<<endl;
        }
        else {
            if ((r-2)%4==0) cout<<"Bob"<<endl;
            else    cout<<"Alice"<<endl;
        }
    }
}