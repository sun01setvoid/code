//有最重链，次重链，更次等，越往前top深度越低，但绝不相等，且只要有超过两个儿子，这个儿子的深度就必然有一条轻链
//轻链向上一步也就是到top的父节点，比他重的链上
////可以发现，当我们向下经过一条 轻边 时，所在子树的大小至少会除以二
//树链剖分是怎么想出来的？？？？
//最多有logn条链
#include <iostream>
using namespace std;
const int N=1e5+10;
const int M=2*N;
int d[N],f[N],son[N],size[N],top[N],dfn[N],rnk[N];
int h[N],e[M],ne[M],idx=1,mk;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void dfs1(int x,int fa){
    size[x]=1;//本身算一个
    d[x]=d[fa]+1,f[N]=fa;
    son[x]=0;//初始化，如果有多个测试样例
    int ans=-1;
    for (int i=h[x];i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs1(j,x);
        size[x]+=size[j];
        if (size[j]>ans)    son[x]=j,ans=size[j];
        //也可以写成size[j]>size[son[x]],因为son[x]有初始化，且size[son[x]]是不可能出现的值0
    }
}//做四个
void dfs2(int x,int topx){
    top[x]=topx;
    dfn[x]=++mk;//线段树重链编号连续，子树编号连续，直接维护线段树就行
    rnk[mk]=x;
    if (son[x]) dfs2(son[x],topx);//先走重链
    for (int i=h[x];i;i=ne[i]){
        int j=e[i];
        if (j!=f[x] && j!=son[x])   dfs2(j,j);
    }
}//做一个