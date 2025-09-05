#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c=a/b,d=a%b;
    if (d>b/2) cout<<c+1;
    else cout<<c;
}