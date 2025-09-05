#include <bits/stdc++.h>
using namespace std;
int h[2010];
int main(){
    int t=1;
    cin>>t;
    while (t--){
        memset(h,0,sizeof(h));
        int n;
        cin>>n;
        vector <vector<int>> mp(n+1,vector<int>(n+1));
        vector <int> ans(2*n+1);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                cin>>mp[i][j];
                ans[i+j]=mp[i][j];
                h[mp[i][j]]=1;
            }
        }
        for (int i=1;i<=2*n;i++){
            if (h[i]==0){
                cout<<i;
                break;
            }
        }
        for (int i=2;i<=2*n;i++) cout<<" "<<ans[i];
        cout<<endl;
    }
}