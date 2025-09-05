#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int P=65536;
struct  trnode{
    ll sum;
    ll lazy;
}tr[N<<2];
int h[N],e[2*N],ne[2*N],idx=1;
int son[N],f[N],dfn[N],rnk[N],d[N],size[N],top[N],cnt;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;}
void dfs1(int x,int fa){
    f[x]=fa,d[x]=d[fa]+1,son[x]=0,size[x]=1;
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs1(j,x);
        size[x]+=size[j];
        if (size[son[x]]<size[j])   son[x]=j;
    }     
}
void dfs2(int x,int topx){
    top[x]=topx,dfn[x]=++cnt,rnk[cnt]=x;
    if (son[x]) dfs2(son[x],topx);
    for (int i=h[x];i;i=ne[i]){
        int j=e[i];
        if (j==f[x] || j==son[x])  continue;
        dfs2(j,j);
    }
}
void pushup(int lc){
    tr[lc].sum=(tr[lc<<1].sum+tr[lc<<1|1].sum);
}
void pushdown(int lc,int ll,int rl){
    tr[lc<<1].lazy=(tr[lc<<1].lazy+tr[lc].lazy),tr[lc<<1|1].lazy=(tr[lc<<1|1].lazy+tr[lc].lazy);
    tr[lc<<1].sum=(tr[lc<<1].sum+tr[lc].lazy*ll),tr[lc<<1|1].sum=(tr[lc<<1|1].sum+tr[lc].lazy*rl);
    tr[lc].lazy=0;
}
void rch(int L,int R,int V,int l,int r,int lc){
    if (l>=L && r<=R){
        tr[lc].sum=(tr[lc].sum+(r-l+1)*V);
        tr[lc].lazy=(tr[lc].lazy+V);
        return;
    }
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    if (L<=m) rch(L,R,V,l,m,lc<<1);
    if (R>=m+1) rch(L,R,V,m+1,r,lc<<1|1);
    pushup(lc);
}
int rq(int L,int R,int l,int r,int lc){
    if (L<=l && r<=R)   return tr[lc].sum;
    if (r<L || l>R) return 0;
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    return (rq(L,R,l,m,lc<<1)+rq(L,R,m+1,r,lc<<1|1));
}
int main(){
    int n,m;
    int x,y,z,id;
    int temp;
    cin>>n>>m;
    for (int i=0;i<n-1;i++){cin>>x>>y;add(x,y),add(y,x);}
    dfs1(1,0);
    dfs2(1,1);
    for (int i=1;i<=n;i++){cin>>temp;rch(i,i,temp,1,n,1);}
    for (int i=0;i<m;i++){//树上操作logn(链数)*logn(线段树操作)
        cin>>id;
        if (id==1){
            cin>>x>>y>>z;
            while (top[x]!=top[y]){
                if(d[top[x]]<d[top[y]]) swap(x,y);
                rch(dfn[top[x]],dfn[x],z,1,n,1);
                x=f[top[x]];
            }
            if (d[x]<d[y])  swap(x,y);
            rch(dfn[y],dfn[x],z,1,n,1);  
        }
        else if(id==2){
            cin>>x>>z;
            rch(dfn[x],dfn[x]+size[x]-1,z,1,n,1);
        }
        else if (id==3){
            cin>>x>>y;
            ll ans=0;
            while (top[x]!=top[y]){
                if(d[top[x]]<d[top[y]]) swap(x,y);
                ans=(ans+rq(dfn[top[x]],dfn[x],1,n,1));
                x=f[top[x]];
            }
            if (d[x]<d[y])  swap(x,y);
            ans=(ans+rq(dfn[y],dfn[x],1,n,1));
            cout<<ans<<endl;
        }
        else{
            cin>>x;
            cout<<rq(dfn[x],dfn[x]+size[x]-1,1,n,1)<<endl;
        }
    }
}