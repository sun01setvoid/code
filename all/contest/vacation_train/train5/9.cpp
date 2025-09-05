//acw396
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int N=510,M=10010;//无向边
int m,n,rt;
int vis[N];
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],ts;
int stk[N],top,dcc_cnt;
bool cut[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void tarjan(int u,int from){
    dfn[u]=low[u]=++ts;stk[++top]=u;
    int cnt=0;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (i==(from^1))  continue;
        if (vis[j]) continue;
        if (!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            if (low[j]>=dfn[u]){
                cnt++;
                if (u!=rt || cnt>1) cut[u]=true;
                int y;dcc_cnt++;
                do{
                    y=stk[top--];
                }while(y!=j); 
            }
        }
        else low[u]=min(low[u],dfn[j]);
    }
}
int main(){
    int a,b;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for (int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    int sum,sub;
    cin>>sum;
    int ori=sum;
    while (sum--){
        cin>>sub;
        dcc_cnt=idx=ts=top=0;
        memset(cut,false,sizeof cut);
        memset(dfn,0,sizeof dfn);
        for(rt=0;rt<=n-1;rt++){
            if (!dfn[rt] && !vis[rt]){
                tarjan(rt,-1);
            }
        }
        if (cut[sub])   printf("Red Alert: City %d is lost!\n",sub);
        else printf("City %d is lost.\n",sub);
        vis[sub]=1;
    }
    if (n==ori)    printf("Game Over.");
}