#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n0,n1,n;
    cin>>n0>>n1>>n;
    int m=100010;
    int ans1=-1,ans2=-1;
    for (int i=1;i<=n-1;i++){
        if (n0%i==0 && n1%(n-i)==0){
            if (n0/i==1 || n1/(n-i)==1)    continue;
            if (abs(n0/i-n1/(n-i))<m)    m=abs(n0/i-n1/(n-i)),ans1=i,ans2=n-i;
        }
    }
    if (ans1==-1 && ans2==-1)    printf("No Solution");
    else    cout<<ans1<<" "<<ans2;
}