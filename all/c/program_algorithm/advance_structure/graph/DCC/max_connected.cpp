//v-dcc
//acw1183
//下列后继前驱均在dfs生成树的基础上
//删去割点连通块数量，看后继和前驱，树可简化看度
//无重边的用处？？？
//先分连通块,再分析每个连通块
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=10010,M=30010;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],ts;
int ans,rt,n,m;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;}
void tarjan(int u){
    dfn[u]=low[u]=++ts;
    int cnt=0;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if (low[j]>=dfn[u]) cnt++;//树根时即使不为割点，求一下它的cnt(即为生成树子节点个数)
        }
        else   low[u]=min(low[u],dfn[j]);
        //即使到父亲的也没事，不影响low[j]>=dfn[u]这件事，舍去父亲的也行，见注释
    }
    //因为是无向图dfs出的dfn，所以遍历的情况时一棵深度优先生成树，每个点只有一个父亲
    if (u!=rt)   cnt++;//不为树根时，若非割点本身算一个（除了树根），若割点，会多出来一个
    //树根时，（若为割点），一定增加了他的后继个
    //若不为割点(即有0或1个子节点)，cnt即为生成树子节点数量
    //所以若树根不为割点的情况无需特殊考虑
    ans=max(ans,cnt);
}
/*
5 6
0 1
0 2
0 3
0 4
1 2
3 4
这种情况出现不是双环，因为无向图dfs是一棵生成树
*/
int main(){
    int x,y;
    while(cin>>n>>m && (n || m)){
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        idx=ts=ans=0;
        for (int i=0;i<m;i++){
            cin>>x>>y;
            add(x,y),add(y,x);
        }
        int cnt=0;
        for (rt=0;rt<n;rt++){
            if (!dfn[rt]){
                cnt++;
                tarjan(rt);
            }
        }
        cout<<ans+cnt-1<<endl;
    }
}
/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=10010,M=30010;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],ts;
int ans,rt,n,m;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;}
void tarjan(int u,int from){
    dfn[u]=low[u]=++ts;
    int cnt=0;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (i==from^1) continue;
        if (!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            if (low[j]>=dfn[u]) cnt++;
        }
        else   low[u]=min(low[u],dfn[j]);
    }
    if (u!=rt)   cnt++;
    ans=max(ans,cnt);
}
int main(){
    int x,y;
    while(cin>>n>>m && (n || m)){
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        idx=ts=ans=0;
        for (int i=0;i<m;i++){
            cin>>x>>y;
            add(x,y),add(y,x);
        }
        int cnt=0;
        for (rt=0;rt<n;rt++){
            if (!dfn[rt]){
                cnt++;
                tarjan(rt,-1);//可以加入不走反向边
            }
        }
        cout<<ans+cnt-1<<endl;
    }
}
*/