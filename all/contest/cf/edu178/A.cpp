#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int a,b,c;
        cin>>a>>b>>c;
        int sum=a+b+c;
        if (sum%3!=0) cout<<"NO"<<"\n";
        else{
            int d=sum/3;
            if (a<=d && b<=d && d-a+d-b<=c) cout<<"YES"<<"\n";
            else cout<<"NO\n";
        }
    }
}