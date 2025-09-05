#include <iostream>
#include <queue>
#include <algorithm>
#define int long long 
using namespace std;
const int N=2e5+10;
int dist[N],p[N];
struct node{
    int x,y,z;
}v[N];
struct n1{
    int x,y,z;
    int id;
}a[N];
struct edge{
    int from,to,w;
}e[3*N];
int n,m,idx=1;
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
signed main(){
    int t;
    cin>>t;
    int t1,t2;
    while (t--){
        cin>>n>>m;
        idx=1;
        for (int i=1;i<=m;i++) p[i]=i;
        for (int i=1;i<=n;i++) cin>>v[i].x>>v[i].y>>v[i].z;
        for (int i=1;i<=m;i++) cin>>t1>>t2,a[i].x=v[t1].x+v[t2].x,a[i].y=v[t1].y+v[t2].y,a[i].z=v[t1].z+v[t2].z,a[i].id=i;
        sort(a+1,a+m+1,[&](n1& s,n1& t)->bool{return s.x<t.x;});
        for (int i=2;i<=m;i++) e[idx++]={a[i-1].id,a[i].id,abs(a[i].x-a[i-1].x)};
        sort(a+1,a+m+1,[&](n1& s,n1& t)->bool{return s.y<t.y;});
        for (int i=2;i<=m;i++) e[idx++]={a[i-1].id,a[i].id,abs(a[i].y-a[i-1].y)};
        sort(a+1,a+m+1,[&](n1& s,n1& t)->bool{return s.z<t.z;});
        for (int i=2;i<=m;i++) e[idx++]={a[i-1].id,a[i].id,abs(a[i].z-a[i-1].z)};
        sort(e+1,e+3*m-2,[&](edge& s,edge &t)->bool {return s.w<t.w;});
        int ans=0;
        for (int i=1;i<=3*m-3;i++){
            int fx=find(e[i].from),fy=find(e[i].to);
            if (fx!=fy){
                p[fx]=fy;
                ans+=e[i].w;
            }
        }
        cout<<ans<<"\n";
    }
}