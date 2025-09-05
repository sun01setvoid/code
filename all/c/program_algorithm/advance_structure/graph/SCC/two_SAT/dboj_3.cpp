//夫妻只有一人在，刚好满足xi与!xi（有且只有一个，但一定要有）
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=4010,M=4e6+10;
int h[N],ne[M],e[M],idx;
int stk[N],top;
bool in_stk[N];
int dfn[N],low[N],ts;
int id[N],scc_cnt;
int n,m;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++ts;
    stk[++top]=u,in_stk[u]=true;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (!dfn[j])    tarjan(j),low[u]=min(low[u],low[j]);
        else if (in_stk[j]) low[u]=min(low[u],dfn[j]);
    }
    if (low[u]==dfn[u]){
        ++scc_cnt;
        int y;
        do{
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
        }while (y!=u);
    }
}
int main(){
    int i,j,a,b;
    while(~scanf("%d %d",&n,&m)){
      	memset(h,-1,sizeof h);
      	memset(dfn,0,sizeof dfn);
      	memset(low,0,sizeof low);
      	top=ts=scc_cnt=idx=0;
    	while (m--){
        	scanf("%d %d %d %d",&i,&j,&a,&b);
        	add(2*i+a,2*j+!b);add(2*j+b,2*i+!a);//2*i wife  +1 husband
    	}
    	for (int i=0;i<2*n;i++){
        	if (!dfn[i])    tarjan(i);//不一定从最高点开始tarjan
    	}
      	bool flag=1;
   	 	for (int i=0;i<n;i++){
        	if (id[2*i]==id[2*i+1]) {puts("NO");flag=0;break;}
    	}//然后有真假的前后关系（若连通），决定值
      	if (flag)
    	puts("YES");
    }
}