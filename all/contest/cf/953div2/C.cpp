#include <iostream>
using namespace std;
#define int long long
const int N=2e5+10;
int ans[N];
bool vis[N];
signed main(){
    int t;
    int n,k;
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=1;i<=n;i++) ans[i]=i;
        int ma=n*n/2;
        if (k>ma) cout<<"NO"<<"\n";
        else if (k&1) cout<<"NO"<<"\n";
        else{
            cout<<"YES"<<"\n";
            k=k/2;
            for (int i=1,j=n;i<=n/2;i++){
                if (k==0) break;
                if (k+i<=j) ans[i]=k+i,ans[k+i]=i,k=0;
                else {
                    ans[i]=j,ans[j]=i;
                    k-=j-i;
                    j--;
                }
            }
            for (int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
        }
    }
}