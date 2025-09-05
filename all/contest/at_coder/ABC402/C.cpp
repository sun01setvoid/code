#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt=0;
    int k,tmp;
    vector <vector<int> > G(n+1);
    vector <int> vis(m+1,0);
    for (int i=1;i<=m;i++){
        cin>>k;
        for (int j=1;j<=k;j++){
            cin>>tmp;
            G[tmp].push_back(i);
        }
        vis[i]+=k;
    }
    for (int i=1;i<=n;i++){
        cin>>tmp;
        for (auto it:G[tmp]){
            vis[it]--;
            if (!vis[it])   cnt++;
        }
        cout<<cnt<<"\n";
    }
}