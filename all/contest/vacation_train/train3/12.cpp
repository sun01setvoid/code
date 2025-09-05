//夫妻只有一人在，刚好满足xi表示妻子在与!xi表示妻子不在，丈夫在
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=20,M=400;
int h[N],ne[M],e[M],idx;
int stk[N],top;
bool in_stk[N];
int dfn[N],low[N],ts;
int id[N],scc_cnt;
int n,m;
void add(int a,int b){
    e[idx]=b;ne[idx]=h[a],h[a]=idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++ts;
    stk[++top]=u,in_stk[u]=true;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
		if (!dfn[j])    {
			tarjan(j);
			low[u]=min(low[u],low[j]);
		}
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
int main()
{
	int n,m;
	memset(h,-1,sizeof h);
	while(~scanf("%d",&n)){
		scanf("%d",&m);
		for(int i = 0;i < m;i++){
			int a,b,x,y;
			scanf("%d%d%d%d",&a,&b,&x,&y);
			a = 2*a + x;	b = 2*b + y;
			add(a,b^1); add(b,a^1);			
		}
		for(int i = 0;i < 2*n;i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		bool f = true;
		for(int i = 0;i < n;i++){
			if(id[i*2] == id[i*2+1]){
				f = false;
				break;
			}
		}
		if(f){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
