#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=1e5+10;
int dist[N],st[N],h[2*N],e[2*N],ne[2*N],idx=0,n,m;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
int bfs(int u){
    st[u]=1;
    dist[u]=0;
    queue <int> q;
    q.push(u);
    while (q.size()){
        int nod=q.front();
        q.pop();
        if (nod==n)
            return dist[n];
        for (int cur=h[nod];cur!=-1;cur=ne[cur]){
            int j=e[cur];
            if (!st[j]){
                st[j]=1;
                dist[j]=dist[nod]+1;
                q.push(j);
            }
        }
    }
    return -1;
}
int main(){
    int a,b;
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for (int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs(1);//bfs搜索按到这个点的步数排序，且走过的路无需再走，A<=B
}