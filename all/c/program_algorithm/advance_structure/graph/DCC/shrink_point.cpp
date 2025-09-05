//e-dcc
//每个点都是一个边双连通，用id表示,桥是缩点之间的边
//只有一个点，不需要加边
//acw395
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=5010,M=20010;
int n,m;
int h[N],e[M],ne[M],idx;//如果要用反向边，最好从0开始，i与i^1
int ts,dfn[N],low[N];
int stk[N],top;
int id[N],dcc_cnt;
bool is_bridge[M];
int d[N];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;}
void tarjan(int u,int from){
    dfn[u]=low[u]=++ts;
    stk[++top]=u;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (i==(from^1))    continue;//防止搜反向边
        if (!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            if (low[j]>dfn[u])  is_bridge[i]=is_bridge[i^1]=1;
        }
        else {
            low[u]=min(low[u],dfn[j]);
        }
    }
    if (dfn[u]==low[u]){
        dcc_cnt++;
        int y;
        do{
            y=stk[top--];
            id[y]=dcc_cnt;
        }while (y!=u);
    }//y==u就退出来，但是这步也需要处理，就先处理一下
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    int x,y;
    for (int i=0;i<m;i++){
        cin>>x>>y;
        add(x,y),add(y,x);
    }
    tarjan(1,-1);
    for (int i=0;i<idx;i++){
        if (is_bridge[i])   d[id[e[i]]]++;  
    }
    int cnt=0;
    for (int i=1;i<=dcc_cnt;i++){
        if (d[i]==1)    cnt++;
    }
    cout<<(cnt+1)/2;
}
//第二种方法先dfs找割边，再dfs不经过割边求出边双连通分量的数量