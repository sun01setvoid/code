#include <iostream>
int a[10001];
using namespace std;
int main(){
    int l,r,i,j,ans=0;
    cin>>l>>r;
    for (i=2028;i<10000 ;i+=4){
        a[i]++;
    }
    for (i=2026;i<10000 ;i+=4){
        a[i]++;
    }
    for (int i=l;i<=r;i++){
        ans+=a[i];
    }
    cout<<ans;
    getchar();
    getchar();
}