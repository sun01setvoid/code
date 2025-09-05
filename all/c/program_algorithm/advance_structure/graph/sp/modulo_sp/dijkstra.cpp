//求种类，等价类
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<ll,int> PII;
const int N=3e5+10;
int h[N],e[N],ne[N],w[N],idx,vis[N];
ll dist[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
ll ht;
int x,y,z;
void dijikstra(){
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
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
                dist[j]=dist[u]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof h);
    cin>>ht>>x>>y>>z;
    ht=ht-1;//令从0开始
    for (int i=0;i<x;i++){//任意一个就好
        add(i,(i+y)%x,y);
        add(i,(i+z)%x,z);
    }
    dijikstra();
    ll ans=0;
    for (int i=0;i<x;i++){
        if (ht>=dist[i]){   //ht小就到不了
            ans+=(ht-dist[i])/x+1;
        }
    }
    cout<<ans;
}