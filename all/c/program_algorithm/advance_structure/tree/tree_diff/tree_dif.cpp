//离线，差分

//这里的差分是从下往上差，因为这样只需要多设一个虚拟节点
//dfs从下往上后序遍历，即可更新完毕

//1.树上点差分
//x->y +v
//=
//x+v,y+v,lca-v,f[lca]+v;
//所以要设虚拟根连接真根

//2.树上边差分
//x+v,y+v,lca-2*v

//x表示他的祖先到他的距离
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10,M=2*N;
int d[N],f[N],son[N],sz[N],top[N];
int h[N],e[M],ne[M],idx;
int dif[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void dfs1(int x,int fa){
    sz[x]=1;
    d[x]=d[fa]+1,f[x]=fa;
    son[x]=0;
    int ans=0;
    for (int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs1(j,x);
        sz[x]+=sz[j];
        if (sz[j]>ans)    son[x]=j,ans=sz[j];
    }
}
void dfs2(int x,int topx){
    top[x]=topx;
    if (son[x]) dfs2(son[x],topx);//先走重链
    for (int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if (j!=f[x] && j!=son[x])   dfs2(j,j);
    }
}
void dfs3(int x,int fa){
    for (int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs3(j,x);
        dif[x]+=dif[j];
    }
}
int LCA(int x,int y){
    while (top[x]!=top[y]){
        if (d[top[x]]<d[top[y]])    swap(x,y);
        x=f[top[x]];
    }
    return d[x]<d[y]?x:y;
}
void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a,b;
    init();
    for (int i=1;i<=n-1;i++){
        cin>>a>>b;
        add(a,b);add(b,a);
    }
    dfs1(1,0);
    dfs2(1,1);
    for (int i=1;i<=k;i++){
        cin>>a>>b;
        int ans=LCA(a,b);
        dif[a]+=1,dif[b]+=1,dif[ans]-=1,dif[f[ans]]-=1;
    }
    dfs3(1,0);
    int ma=0;
    for (int i=1;i<=n;i++){
        ma=max(ma,dif[i]);
    }
    cout<<ma<<"\n";
}

