#include <iostream>
using namespace std;
int main(){
    int t,n,m,x,y;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>m>>x>>y;
        if (n==1 && m==1){
            cout<<"0"<<endl;
        }
        else if (n==1 || m==1)
            cout<<"1"<<endl;
        else{
            if (n>m)
            cout<<m+1<<endl;
            else
        cout<<n+1<<endl;
        }
    }
}