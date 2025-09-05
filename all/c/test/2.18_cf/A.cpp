#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int t,n,temp;
    cin>>t;
    int a[110]={1};
    while (t--){
        memset(a,0,sizeof a);
        a[1]=1;
        int cur=1;
        cin>>n;
        bool flag=1;
        for (int i=2;i<=n-1;i++){
            cin>>temp;
            if (temp==0){
                if (a[i]){
                    if (a[i]==a[i-1])   a[i+1]=++cur;
                }
                else    a[i]=++cur;
            }
            else{
                if (a[i]){
                    if (a[i]!=a[i-1])   {flag=0;}
                    else    a[i+1]=a[i];
                }
                else    a[i]=cur,a[i+1]=cur;
            }
        }
        if (flag)   cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}