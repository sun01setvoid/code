//dijkstra+线段树
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=1e5+10;
typedef unsigned long long ULL;
typedef pair <ULL,int> PII;
#define inf 0x3f3f3f3f3f3f3f3full
int n,m,q;
struct Node{
    int to;
    int w;
};
int ai[N];
vector <Node> G[N],rG[N];
ULL dist[N],rdist[N];
priority_queue <PII,vector<PII>,greater<PII> > heap,rheap;//根据前一个排序，再后一个
bool st[N],rst[N];
struct trNode{
    ULL m;
    int lazy;
}tr[N<<2];
void pushup(int lc){
    tr[lc].m=min(tr[lc<<1].m,tr[lc<<1|1].m);
}
void sUpdate(int L,ULL V,int l,int r,int lc){
    if (l==r){
        tr[lc].m=V;
        return;
    }
    int mid=l+r>>1;
    if (L<=mid) sUpdate(L,V,l,mid,lc<<1);
    else sUpdate(L,V,mid+1,r,lc<<1|1);
    pushup(lc);
}
int sQuery(int L,int R,int l,int r,int lc){
    if (r<L || l>R) return inf;
    if ( l>=L && r<=R)  return tr[lc].m;
    int mid=l+r>>1;
    int ans=inf;
    if (L<=mid) ans=min(ans,sQuery(L,R,l,mid,lc<<1));
    if (R>=mid+1) ans=min(ans,sQuery(L,R,mid+1,r,lc<<1|1));
    return ans;
}
void dijkstra(int u){
    dist[u]=0;
    heap.push({0,u});
    int cur;ULL d;
    while (heap.size()){
        auto t=heap.top();
        heap.pop();
        cur=t.second,d=t.first;
        if (st[cur])    continue;
        if (d==inf) break;
        st[cur]=true;
        for (auto i:G[cur]){
            if (!st[i.to] && dist[i.to]>d+i.w){
                    dist[i.to]=d+i.w;
                    heap.push({dist[i.to],i.to});
            }
        }
    }
}
void rdijkstra(int u){
    rdist[u]=0;
    rheap.push({0,u});
    int cur;ULL d;
    while (rheap.size()){
        auto t=rheap.top();
        rheap.pop();
        cur=t.second,d=t.first;
        if (rst[cur])    continue;
        if (d==inf) break;
        rst[cur]=true;
        for (auto i:rG[cur]){
            if (!rst[i.to] && rdist[i.to]>d+i.w){
                    rdist[i.to]=d+i.w;
                    rheap.push({rdist[i.to],i.to});
            }
        }
    }
}
int main(){
    cout<<inf;
    cin>>n>>m>>q;
    int a,b,c,d;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        G[a].push_back({b,c});
        rG[b].push_back({a,d});
    }
    memset(dist,0x3f,sizeof dist);
    memset(rdist,0x3f,sizeof rdist);
    memset(tr,0x3f,sizeof tr);
    dijkstra(1);
    rdijkstra(n);
    for (int i=1;i<=n;i++)  cin>>ai[i];
    ULL res;
    ULL mi=inf;
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (dist[i]!=inf && rdist[i]!=inf){
            res=dist[i]+(rdist[i]+ai[i]-1)/ai[i];
            sUpdate(i,res,1,n,1);
            if (res<mi) mi=res;
        }
        else    sUpdate(i,inf,1,n,1);
    }
    int xi,temp;
    while (q--){
        cin>>xi>>temp;
        ai[xi]=temp;
        if (dist[xi]!=inf && rdist[xi]!=inf){
            res=dist[xi]+(rdist[xi]+ai[xi]-1)/ai[xi];
            sUpdate(xi,res,1,n,1);
        }
        cout<<sQuery(1,n,1,n,1)<<endl;
    }
}
