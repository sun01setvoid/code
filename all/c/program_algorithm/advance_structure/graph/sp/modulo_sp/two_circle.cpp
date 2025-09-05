//method
/*base*/
/*
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<ll,int> PII;
const int N=6e6+10;
int h[N],e[N],ne[N],w[N],idx,vis[N];
ll dist[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
ll l,r;
int a[20],n;
void dijikstra(){
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    vis[0]=0;
    priority_queue <PII,vector <PII> ,greater <PII> > heap;
    heap.push({0,0});
    while (heap.size()){
        auto t=heap.top();
        heap.pop();
        ll dis=t.first;
        int u=t.second;
        if (vis[u]) continue;
        if (dist[u]==inf)   continue;
        vis[u]=0;
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if (!vis[j] && dist[j]>dist[u]+w[i]){
                dist[j]=dis+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>l>>r;
    l=l-1;
    for  (int i=0;i<n;i++){
        cin>>a[i];        
    }
    for (int i=0;i<a[0];i++){//任意一个就好
        for (int j=1;j<n;j++){
            add(i,(i+a[j])%a[0],a[j]);
        }
    }
    dijikstra();
    ll ans=0;
    for (int i=0;i<a[0];i++){
        if (r>=dist[i]){   
            ans+=(r-dist[i])/a[0]+1;
        }
        if (l>=dist[i])
            ans-=(l-dist[i])/a[0]+1;
    }
    cout<<ans<<endl;
}
*/

//X=10(基准数)，加入Y边,形成的环有gcd(X,Y)个
//转两圈更新，因为子环的起点不一定是点权(距离）最小的点
//O(n*x)常数很小
//取最小的做可能更快一些？？
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3f
int a[20];
const int N=5e5+10;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
ll dist[N];
int main(){
    memset(dist,0x3f,sizeof dist);
    int n,tmp;
    ll l,r;
    int cnt=0;
    cin>>n>>l>>r;
    l=l-1;
    for (int i=0;i<n;i++)   {
        cin>>tmp;
        if (tmp!=0) a[cnt++]=tmp;
    }
    sort(a,a+cnt);
    dist[0]=0;
    for (int i=1;i<cnt;i++){
        int d=gcd(a[i],a[0]);
        for (int j=0;j<d;j++){
            for (int k=j,ne,circle=0;circle<2;circle+=k==j){
                ne=(k+a[i])%a[0];
                if (dist[k]!=inf){
                    dist[ne]=min(dist[ne],dist[k]+a[i]);
                }
                k=ne;
            }
        }
    }
    ll ans=0;
    for (int i=0;i<a[0];i++){
        if (r>=dist[i]) ans+=(r-dist[i])/a[0]+1;
        if (l>=dist[i]) ans-=(l-dist[i])/a[0]+1;
    }
    cout<<ans;
}