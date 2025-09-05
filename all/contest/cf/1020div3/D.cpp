#include <iostream>
using namespace std;
const int N=2e5+10;
int a[N],b[N],pre[N],suf[N];
int main(){
    int t;
    int n,m;
    cin>>t;
    while (t--){
        cin>>n>>m;
        int cnt=1;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=m;i++)  cin>>b[i];
        pre[0]=0,suf[n+1]=0;
        for (int i=1;i<=n;i++){
            pre[i]=pre[i-1];
            if (a[i]>=b[cnt]){
                pre[i]=cnt;
                cnt++;
            }
        }
        cnt=m;
        for (int i=n;i>=1;i--){
            suf[i]=suf[i+1];
            if (a[i]>=b[cnt]){
                suf[i]=m-cnt+1;
                cnt--;
            }
        }
        int vis=0;
        int ans=0x3f3f3f3f;
        for (int i=0;i<=n;i++){
            if (pre[i]+suf[i+1]>=m){
                vis=2;break;
            }
            else if (pre[i]+suf[i+1]==m-1){
                ans=min(ans,b[pre[i]+1]);
                vis=1;
            }
        }
        if (vis==0) cout<<-1<<"\n";
        else if (vis==1)    cout<<ans<<"\n";
        else cout<<0<<"\n";
    }
}