#include <iostream>
#include <algorithm>
using namespace std;
int a[200010];
int main(){
    int t;
    int n,k;
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int res=n+1;
        if (n-k==0){
            int flag=0;
            for (int i=1;i<=n/2;i++){
                if (a[2*i]!=i){
                    cout<<i<<endl;
                    flag=1;
                    break;
                }  
            }
            if (!flag)  cout<<k/2+1<<endl;
            continue;
        }
        int l1,r1;
        for (int j=2;j<=n;j++){
            if (j-(n-k)-1<1)    l1=1;
            else    l1=j-(n-k)-1;
            r1=j-1;
            if (l1==a[j])    res=min(l1+1,res);
            else    res=min(res,l1);
        }
        cout<<res<<endl;
    }
}