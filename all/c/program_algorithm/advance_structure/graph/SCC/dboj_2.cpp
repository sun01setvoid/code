//最大点权
//强连通+缩点(防止回到祖先，较麻烦，类似tarjan分类)+记忆化dfs
//kosaraju
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N=1e5+10,M=2*N;
int n,m;
int stk[N],top=-1;
int h[N],e[M],ne[M],idx;
int rh[N],re[M],rne[M],ridx;
bool vis[N],sccno[N],vvis[N];
int id[N],scc_cnt;
vector <int> scc[N];
vector <int> G[N];
int v[N];
int vG[N];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void radd(int a,int b){re[ridx]=b,rne[ridx]=rh[a],rh[a]=ridx++;}
void dfs1(int u){
    if (vis[u]) return;
    vis[u]=true;
    for (int i=h[u];~i;i=ne[i]){
            dfs1(e[i]);
    }
    stk[++top]=u;
}
void dfs2(int u){
    if (sccno[u])   return;
    sccno[u]=true;
    id[u]=scc_cnt;
    scc[scc_cnt].push_back(u);
    for (int i=rh[u];~i;i=rne[i]){
        dfs2(re[i]);
    }
}
void kosaraju(){
    memset(vis,false,sizeof vis);
    memset(sccno,false,sizeof sccno);
    for (int i=1;i<=n;i++)  dfs1(i);
    for (int i=n-1;i>=0;i--)    {
        if (!sccno[stk[i]])
            ++scc_cnt,dfs2(stk[i]);
    }
}
void dfs3(int u){
    if (vvis[u])    return;
    vvis[u]=true;
    for (auto i:G[u]){
      	dfs3(i);
        vG[u]=max(vG[u],vG[i]);
    }
}
int main(){
    int a,b,t;
    cin>>t;
    while (t--)
    {
        for (int i=1;i<=scc_cnt;i++)    scc[i].clear(),G[i].clear();
        memset(h,-1,sizeof h);
        memset(rh,-1,sizeof rh);
        idx=ridx=scc_cnt=0;
      	top=-1;
        cin>>n>>m;
        for (int i=1;i<=n;i++){cin>>v[i];}
        while (m--){
            cin>>a>>b;
            add(a,b),radd(b,a);
        }
        kosaraju();
        for (int i=1;i<=scc_cnt;i++){
            int m=v[scc[i][0]];
            for (int j=1;j<=scc[i].size()-1;j++)    m=max(m,v[scc[i][j]]);
            vG[i]=m;
        }
        memset(vvis,false,sizeof vvis);
        for (int i=1;i<=n;i++){
            for (int j=h[i];~j;j=ne[j]){
                int k=e[j];
                if (id[i]!=id[k])   G[id[i]].push_back(id[k]);//重边没影响
            }
        }
        for (int i=1;i<=scc_cnt;i++){
            if (!vvis[i])   dfs3(i);//是DAG,但不一定是树，所以要按拓扑序遍历节点，实现从上往下遍历
        }
        for (int i=1;i<=n;i++)  cout<<vG[id[i]]<<endl;
    }
}
