#include <iostream>
#include <vector>
using namespace std;
int ans[600];
int vis1[600];
int vis2[600];
int sz[600];
int n,m;
int st,en;
vector <int> G[600];
void dfs1(int u){
    if (vis1[u]) return;
    vis1[u]=1;
    if (u==en)  ans[u]=1;
    for (auto i:G[u]){
        dfs1(i);
        ans[u]+=ans[i];
    }
}
void dfs2(int u){
    if (vis2[u]) return;
    if (u==en)    {sz[u]=1;return;}//遇到en就不应该继续走下去了
    vis2[u]=1;
    if (G[u].size()==0)    {sz[u]=1;return;}
    for (auto i:G[u]){
        dfs2(i);
        sz[u]+=sz[i];
    }
}
int main(){
    cin>>n>>m;
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
    }
    cin>>st>>en;
    dfs1(st);
    dfs2(st);
    cout<<ans[st]<<" ";
    if (ans[st]==sz[st])    cout<<"Yes";
    else cout<<"No";
}