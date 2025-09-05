#include <iostream>
#include <algorithm>
using namespace std;
int a[60];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int c1=-1,c2=-1,d1=-1,d2=-1;
        if ((a[1]+a[n])%2==0) cout<<0<<endl;
        else{
            int ans=INT_MAX;
            for (int i=1;i<=n;i++){
                for (int j=n;j>=i;j--){
                    if ((a[i]+a[j])%2==0){
                        ans=min(i-1+n-j,ans);
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}