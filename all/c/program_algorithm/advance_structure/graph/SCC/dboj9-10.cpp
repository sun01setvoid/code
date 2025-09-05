//点权统计
//kosaraju
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N=1e5+10,M=2*N;
int n,m;
int stk[N],top=-1;
int h[N],e[M],ne[M],idx;
int rh[N],re[M],rne[M],ridx;
bool vis[N],sccno[N];
int scc_cnt;
vector <int> scc[N];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void radd(int a,int b){re[ridx]=b,rne[ridx]=rh[a],rh[a]=ridx++;}
void dfs1(int u){
    if (vis[u]) return;
    vis[u]=true;
    for (int i=h[u];~i;i=ne[i]){
            dfs1(e[i]);
    }
    stk[++top]=u;
}
void dfs2(int u){
    if (sccno[u])   return;
    sccno[u]=true;
    scc[scc_cnt].push_back(u);
    for (int i=rh[u];~i;i=rne[i]){
        dfs2(re[i]);
    }
}
void kosaraju(){
    memset(vis,false,sizeof vis);
    memset(sccno,false,sizeof sccno);
    for (int i=1;i<=n;i++)  dfs1(i);
    for (int i=n-1;i>=0;i--)    {
        if (!sccno[stk[i]])
            ++scc_cnt,dfs2(stk[i]);
    }
}
//这个scc是正拓扑序
int main(){
    int a,b,t;
    cin>>t;
    while (t--)
    {
        for (int i=1;i<=scc_cnt;i++)    scc[i].clear();
        memset(h,-1,sizeof h);
        memset(rh,-1,sizeof rh);
        idx=ridx=scc_cnt=0;
      	top=-1;
        cin>>n>>m;
        while (m--){
            cin>>a>>b;
            add(a,b),radd(b,a);
        }
        kosaraju();
        long long sum=0;
        for (int i=1;i<=scc_cnt;i++){
            sum+=(long long)scc[i].size()*(scc[i].size()-1)/2;
        }
        cout<<sum<<endl;
    }
}
