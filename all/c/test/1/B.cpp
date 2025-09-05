#include <iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int t=j+i-1;
            if (j+i-1>n)  t=j+i-1-n;  
            cout<<t<<" ";
        }
        cout<<endl;
    }
}