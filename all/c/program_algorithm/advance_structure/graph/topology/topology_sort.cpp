//拓扑排序
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int d[N],n,m,topo[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
int toposort(){
    queue <int> q;
    int i,j=0;
    for (i=1;i<=n;i++){
        if (d[i]==0)    q.push(i);
    }
    while (q.size()){
        int t=q.front();
        q.pop();
        topo[j]=t,j++;
        for (int k=h[t];k!=-1;k=ne[k]){
            int v=e[k];
            d[v]--;
            if (d[v]==0)    q.push(v);
        }
    }
    if(j!=n)    return 0;
    return 1;
}
/*
bool dfs(int u){    
    vis[u]=1;      
    for (int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==1) return false; 
        if(!vis[v]&&!dfs(v)) return false; 
    }
    vis[u]=2;
    //可建反拓扑序
    j++;
    return true;
}//dfs版
*/
int main(){
    cin>>n>>m;
    int a,b;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b);
        d[b]++;//这里的入度一定是对的，重边不影响，在删边时重边会删除多次
    }
    if (toposort())
        for (int i=0;i<n;i++)   cout<<topo[i]<<" ";
    else cout<<-1;
    system("pause");
}
