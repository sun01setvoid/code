
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int v,w;
        cin>>v>>w;
        int s=w/2+1,t=(w+1)/2;
        int ans;
        if (v<t) ans=1;
        else{
            ans=(v-t)/s+1;
        }
        cout<<ans<<"\n";
    }
}