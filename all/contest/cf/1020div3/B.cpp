#include <iostream>
using namespace std;
int main(){
    int t;
    int n,x;
    cin>>t;
    while (t--){
        cin>>n>>x;
        for (int i=x-1;i>=0;i--){
            cout<<i<<" ";
        }
        for (int i=x+1;i<=n-1;i++){
            cout<<i<<" ";
        }
        if(x<=n-1) cout<<x;
        cout<<"\n";
    }
}