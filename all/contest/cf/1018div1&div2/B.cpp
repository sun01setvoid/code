#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL a[N],b[N],c[N];
int main(){
    int t;
    cin>>t;
    int n,k;
    LL tmp;
    while (t--){
        cin>>n>>k;
        LL ans=0;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            cin>>b[i];
        }
        for (int i=1;i<=n;i++){
            ans+=max(a[i],b[i]);
            c[i]=min(a[i],b[i]);
        }
        sort(c+1,c+n+1,[](int x,int y){return x>y;});
        for (int i=1;i<=k-1;i++){
            ans+=c[i];
        }
        cout<<ans+1<<"\n";
    }
}