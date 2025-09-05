#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=2e5+10;
struct node{
    int a;
    int b;
    LL w;
}e[N];
int ed[N],vx[N],p[N];
int find(int x){
    if (p[x]!=x)    p[x]=find(p[x]);
    return p[x];
}
void merge(int fx,int fy){
    p[fx]=fy;
    ed[fy]+=ed[fx]+1;
    vx[fy]+=vx[fx];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        int n,m;
        cin>>n>>m;
        int ai,bi;
        LL wi;
        for (int i=1;i<=m;i++){
            cin>>ai>>bi>>wi;
            e[i]={ai,bi,wi};
        }
        sort(e+1,e+m+1,[](node &x,node &y){return x.w>y.w;});
        for (int i=1;i<=n;i++)  p[i]=i,ed[i]=0,vx[i]=1;
        LL ans=0;
        for (int i=1;i<=m;i++){
            auto [u,v,q]=e[i];
            int fx=find(u),fy=find(v);
            if (fx==fy){
                if (vx[fx]>ed[fx]){
                    ans+=q;
                    ed[fx]++;
                }
            }
            else{
                if (ed[fx]<vx[fx]|| ed[fy]<vx[fy]){
                    merge(fx,fy);
                    ans+=q;
                }
            }
        }
        cout<<ans<<"\n";
    }
}