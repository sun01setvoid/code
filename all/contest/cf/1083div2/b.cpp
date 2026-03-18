#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<"="<<x<<endl
int main(){
    int t=1;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int res=n;
        int ans=1;
        for (int i=2;i*i<=res;i++){
            if (res%i==0){
                int cnt=0;
                while (res%i==0) cnt++,res/=i;
                int d=(cnt+n-1)/n;
                for (int j=1;j<=d;j++) ans*=i;
            }
        }
        if (res>1) ans*=res;
        cout<<ans<<endl;
    }
}