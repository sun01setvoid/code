#include <iostream>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],suf[N],ma[N];
signed main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)  cin>>a[i];
        suf[n+1]=0;
        for (int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
        ma[0]=0;
        for (int i=1;i<=n;i++) ma[i]=max(ma[i-1],a[i]);
        for (int i=n;i>=1;i--){
            cout<<max(ma[i-1]+suf[i+1],suf[i])<<" ";
        }
        cout<<"\n";
    }
}