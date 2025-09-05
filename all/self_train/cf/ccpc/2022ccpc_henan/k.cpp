#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> scc[N];
int dfn[N],low[N],stk[N],id[N],ts=-1,top=-1,scc_cnt;
bool in_stk[N];
int  h[N],e[N],ne[N],idx;
int n,a[N];
int sz[N];
int num;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++ts;
    stk[++top]=u,in_stk[u]=true;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if(in_stk[j])
            low[u]=min(low[u],dfn[j]);
    }
    if (dfn[u]==low[u]){
        int y;
        ++scc_cnt;
        do{
           y=stk[top--],in_stk[y]=false,id[y]=scc_cnt,scc[scc_cnt].push_back(y);
        }while (y!=u);
    }
}
int dfs(int u){
    for (int i=h[u];~i;i=ne[i]){
        num++;
        dfs(e[i]);
    }
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n;
    int tmp;
    for (int i=1;i<=n;i++) cin>>a[i],add(i,a[i]);
    memset(h,-1,sizeof h);
    idx=0;
    for (int i=1;i<=n;i++) add(i,a[i]);
    for (int i=1;i<=n;i++){
        if (scc[id[i]].size()>1){
            num=0;
            dfs(i);
            //cnt[scc[id[i]].size()]+=num;
        }
    }
}
