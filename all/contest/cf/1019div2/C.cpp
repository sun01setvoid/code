#include <iostream>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL a[N],suf[N],minsuf[N];
int  n;LL k;
LL s;
bool check(){
    suf[n+1]=0,minsuf[n+1]=0;
    for (int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        suf[i]+=a[i];
        minsuf[i]=min(suf[i],minsuf[i+1]);
    }
    s=0;
    for (int i=1;i<=n-2;i++){
        s+=a[i];
        if (s>=0){
            if (suf[i+1]>=minsuf[i+2]){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    LL tmp;
    while (t--){
        cin>>n>>k;
        int cnt=0;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            if (a[i]<=k){
               a[i]=1;
               cnt++;
            }
            else a[i]=-1;
        }
        if (cnt<2) {cout<<"NO"<<"\n";continue;}
        s=0;
        int l=n+1,r=-1;
        for (int i=1;i<=n;i++){
            s+=a[i];
            if (s>=0)   {l=i;break;}
        }
        s=0;
        for (int i=n;i>=1;i--){
            s+=a[i];
            if (s>=0)    {r=i;break;}
        }
        if (l+1<=r-1) {
            cout<<"YES\n";
            continue;
        }
        if (check()){
            cout<<"YES"<<"\n";continue;
        }
        for (int i=1;i<=n/2;i++){
            swap(a[i],a[n+1-i]);
        };
        if (check()) {
            cout<<"YES\n";continue;
        }
        cout<<"NO\n";
    }
}