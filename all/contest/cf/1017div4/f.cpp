#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define int long long 
signed main(){
    int t;
    cin>>t;
    while (t--){
        int n,m,k;
        cin>>n>>m>>k;
        int cur;
        if (m%k==0){
            for (int i=1;i<=n;i++){
                if (i&1) cur=0;
                else cur=1;
                for (int j=1;j<=m;j++){
                    cout<<cur+1<<" ",cur=(cur+1)%k;
                }
                cout<<endl;
            }
        }
        else {
            cur=0;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                   cout<<cur+1<<" ",cur=(cur+1)%k;
                }
                cout<<endl;
            }
        }
    }
}