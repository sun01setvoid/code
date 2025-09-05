#include <iostream>
using namespace std;
int main(){
    int T;
    int x,y,z;
    cin>>T;
    for (int i=0;i<T;i++){
        cin>>x>>y>>z;
        int t=(z+y)%7+((z+y)%7==0)*7;
        cout<<(t+x)%7+((t+x)%7==0)*7<<endl;
    }
}