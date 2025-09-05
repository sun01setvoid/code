#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=6010,M=1e5+10;
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
    int a,b,c,t,m;
    while(~scanf("%d %d",&t,&m)){
      	memset(h,-1,sizeof h);
      	memset(dfn,0,sizeof dfn);
      	memset(low,0,sizeof low);
      	top=ts=scc_cnt=idx=0;
    	for (int i=0;i<t;i++){
        	cin>>a>>b>>c;
            a=2*a,b=2*b,c=2*c;
          	add(a,b^1),add(b,a^1),add(a^1,b),add(b^1,a);
          	add(a,c^1),add(c,a^1),add(a^1,c),add(c^1,a);
          	add(b,c),add(c,b),add(b^1,c^1),add(c^1,b^1);
    	}
      	for (int i=0;i<m;i++){
			cin>>a>>b;
            a=2*a,b=2*b;
          	add(a^1,b),add(b^1,a);
        }
    	for (int i=0;i<6*t;i++){
        	if (!dfn[i])    tarjan(i);//不一定从最高点开始tarjan
    	}
      	bool flag=1;
   	 	for (int i=0;i<3*t;i++){
        	if (id[2*i]==id[2*i+1]) {puts("no");flag=0;break;}
    	}
      	if (flag)
    	puts("yes");
    }
}