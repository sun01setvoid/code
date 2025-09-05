#include <iostream>
#include <unordered_map>
using namespace std;
int a[100020];
int main(){
    int t,n;
    unordered_map <int,int> S;
    for (int i=1;i<=100000;i=(i+1)*2){
        a[i]=1;
    }
    for (int i=1;i<=100000;i++){
        a[i]=a[i]+a[i-1];
    }
    for (int i=1;i<=100010;i*=2){
        S[i]=1;
    }
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        if ((n+2)%3==0 && S.count((n+2)/3)) cout<<a[n]<<endl;
        else    cout<<a[n]+1<<endl;
    }
}