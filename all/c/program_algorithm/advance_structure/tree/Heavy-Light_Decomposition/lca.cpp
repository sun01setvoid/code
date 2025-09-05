//dboj最近公共祖先
//O(mlogn+n)但logn常数通常比倍增法小
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
const int M=2*N;
int d[N],f[N],son[N],sz[N],top[N];
int h[N],e[M],ne[M],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void dfs1(int x,int fa){
    sz[x]=1;//本身算一个
    d[x]=d[fa]+1,f[x]=fa;
    son[x]=0;//初始化，如果有多个测试样例
    int ans=0;
    for (int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs1(j,x);
        sz[x]+=sz[j];
        if (sz[j]>ans)    son[x]=j,ans=sz[j];
        //也可以写成sz[j]>sz[son[x]],因为son[x]有初始化，且sz[son[x]]是不可能出现的值0
    }
}//做四个
void dfs2(int x,int topx){
    top[x]=topx;
    if (son[x]) dfs2(son[x],topx);//先走重链
    for (int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if (j!=f[x] && j!=son[x])   dfs2(j,j);
    }
}//做一个
int LCA(int x,int y){
    while (top[x]!=top[y]){
        if (d[top[x]]<d[top[y]])    swap(x,y);
        x=f[top[x]];
    }//为了使他们在一条链上，越往上在一条链上的可能性更大
    //且应该是top的深度大的轻链往上,这样是较轻的重链
    //且轻链转成较重链，是向他top的父亲操作，是他的祖先
    return d[x]<d[y]?x:y;
}
int main(){
    memset(h,-1,sizeof  h);
    int n,m,x,y;
    cin>>n>>m;
    for (int i=0;i<n-1;i++){
        cin>>x>>y;
        add(x,y),add(y,x);
    }
    dfs1(1,0);
    dfs2(1,1);
    for (int i=0;i<m;i++){
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}