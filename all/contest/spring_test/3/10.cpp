#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
LL a[N],b[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m;
    LL x,y;
    cin>>t;
    while (t--){
        cin>>n>>m;
        LL d1max=-inf,d1min=inf,d2max=-inf,d2min=inf;
        for (int i=1;i<=n;i++){
            cin>>x>>y;
            d1max=max(x+y,d1max);
            d1min=min(x+y,d1min);
            d2max=max(x-y,d2max);
            d2min=min(x-y,d2min);
        }
        for (int i=1;i<=m;i++)  cin>>a[i]>>b[i];
        LL ans=inf;
        for (int i=1;i<=m;i++){
            LL d1=max(abs(d1max-a[i]-b[i]),abs(d1min-a[i]-b[i]));
            LL d2=max(abs(d2max-a[i]+b[i]),abs(d2min-a[i]+b[i]));
            ans=min(ans,max(d2,d1));
        }
        cout<<ans<<endl;
    }
}