//acw396
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int N=1010;
int m,n,rt;
int h[N],e[N],ne[N],idx;
int dfn[N],low[N],ts;
int stk[N],top,dcc_cnt;
bool cut[N];
vector <int> dcc[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void tarjan(int u,int from){
    dfn[u]=low[u]=++ts;stk[++top]=u;
    if (u==rt && h[u]==-1){
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
    int cnt=0;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (i==(from^1))  continue;
        if (!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            if (low[j]>=dfn[u]){
                cnt++;
                if (u!=rt || cnt>1) cut[u]=true;
                int y;dcc_cnt++;
                do{
                    y=stk[top--];
                    dcc[dcc_cnt].push_back(y);
                }while(y!=j); 
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[j]);
    }
}
int main(){
    int a,b,t;
    t=0;
    while (cin>>m && m){
        for (int i=1;i<=dcc_cnt;i++)    dcc[i].clear();
        dcc_cnt=idx=ts=top=n=0;
        memset(h,-1,sizeof h);
        memset(cut,false,sizeof cut);
        memset(dfn,0,sizeof dfn);
        for (int i=0;i<m;i++){
            cin>>a>>b;
            n=max(n,a);n=max(n,b);
            add(a,b),add(b,a);
        }
        for(rt=1;rt<=n;rt++){
            if (!dfn[rt]){
                tarjan(rt,-1);
            }
        }
        int res=0;
        ULL num=1;
        for (int i=1;i<=dcc_cnt;i++){
            int cnt=0;
            for (int j=0;j<dcc[i].size();j++){
                if (cut[dcc[i][j]]) cnt++;
            }
            if (cnt==0) {
                if (dcc[i].size()>1)    res+=2,num*=dcc[i].size()*(dcc[i].size()-1)/2;//出口设两个
                else res++;//孤立点出口设一个
            }
            else if (cnt==1) res++,num*=dcc[i].size()-1;//出口设在内部
        }
        printf("Case %d: %d %llu\n",++t,res,num);
    }
}