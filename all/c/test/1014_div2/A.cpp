#include <iostream>
using namespace std;
int main(){
    int t,n,tmp;
    cin>>t;
    while (t--){
        int mi=0x3f3f3f3f;
        int ma=0;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>tmp;
            if (tmp>ma) ma=tmp;
            if (tmp<mi) mi=tmp;
        }
        cout<<ma-mi<<endl;
    }
}