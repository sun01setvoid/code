#include <iostream>
#include <algorithm>
using namespace std;
int dfn[20],low[20],stk[20],id[20],ts=-1,top=-1,scc_cnt;
bool in_stk[20];
int  h[20],e[20],ne[20],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void tarjan(int u){//tarjan无需顺序，从底到顶，已是topology,只需要遍历所有点
    dfn[u]=low[u]=++ts;
    stk[++top]=u,in_stk[u]=true;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if(in_stk[j])//一定要这样,防止横叉，也防止不从topo最高点tarjan
            low[u]=min(low[u],dfn[j]);
    }
    if (dfn[u]==low[u]){
        int y;
        ++scc_cnt;
        do{
           y=stk[top--],in_stk[y]=false,id[y]=scc_cnt;
        }while (y!=u);
    }
}
//这个scc是反拓扑序

