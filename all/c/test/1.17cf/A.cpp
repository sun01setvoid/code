#include <iostream>
using namespace std;
int main(){
    int t;
    int x,y,n,m;
    cin>>t;
    while (t--){
        int a=0,b=0;
        cin>>n>>m;
        n--;
        cin>>x>>y;
        while (n--){
            cin>>x>>y;
            a+=x;
            b+=y;
        }
        a+=m,b+=m;
        cout<<(a+b)*2<<endl;
    }
}