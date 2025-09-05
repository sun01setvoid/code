//强连通:u可以到达v,v可以到达u
//强连通分量:极大的连通子图（互相到达）
//有向图转换为有向无环图（拓扑图）
//树枝边、前向边、后向边、横叉边
//kosaraju
//边反向,拓扑限制从前面开始做（最小限制条件），他之前的一定先被搜索到，反边限制不能到达他之后的（除非既在他之后又在它之前）
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N=1e5+10;
int n,m;
int stk[N],top=-1;
int h[N],e[N],ne[N],idx;
int rh[N],re[N],rne[N],ridx;
int din[N],dout[N];
bool vis[N],sccno[N];
int id[N],scc_cnt;
vector <int> scc[N];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void radd(int a,int b){re[ridx]=b,rne[ridx]=rh[a],rh[a]=ridx++;}
void dfs1(int u){  //进行dfs,后序遍历，环的部分一定放在一起
    if (vis[u]) return;
    vis[u]=true;
    for (int i=h[u];~i;i=ne[i]){
            dfs1(e[i]);
    }
    stk[++top]=u;
}
void dfs2(int u){ //强连通分量的部分才能互相访问
    if (sccno[u])   return;
    sccno[u]=true;
    scc[scc_cnt].push_back(u);
    id[u]=scc_cnt;
    for (int i=rh[u];~i;i=rne[i]){
        dfs2(re[i]);
    }
}
void kosaraju(){
    //memset(vis,false,sizeof vis);
    //memset(sccno,false,sizeof sccno);
    for (int i=1;i<=n;i++)  dfs1(i);
    for (int i=n-1;i>=0;i--)    {
        if (!sccno[stk[i]])
            ++scc_cnt,dfs2(stk[i]);
    }
}
//这个scc是正拓扑序
int main(){
    int a,b;
    //for (int i=1;i<=scc_cnt;i++)    scc[scc_cnt].clear();
    memset(h,-1,sizeof h);
    memset(rh,-1,sizeof rh);
    idx=ridx=0;
    cin>>n>>m;
    while (m--){
        cin>>a>>b;
        add(a,b),radd(b,a);
    }
    kosaraju();
    /*
    for (int i=1;i<=n;i++){
        for (int j=h[i];~j;j=ne[j]){
            int k=e[i];
            if (id[i]!=id[k])   dout[id[i]]++,din[id[k]]++;
        }
    }
    */
}
