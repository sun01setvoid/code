/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int dist[N],st[N],h[N],e[N],ne[N],w[N],idx=0,n,m;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx,idx++;
}
int bfs(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    st[1]=1;
    int t=1;
    while (t!=n){
        int min=N-1;
        for (int cur=h[t];cur!=-1;cur=ne[cur]){
            int j=e[cur];
            if (!st[j]){
                 if (dist[j]>dist[t]+w[cur]){
                     dist[j]=dist[t]+w[cur];
                 }//重边也没关系，会取到最小的
            }
        }
        //下一个点不一定能更新距离也不一定能由该点走到，所以要在外面判断
        for (int i=1;i<=n;i++){
            if (!st[i] && dist[i]<dist[min]) 
                min=i;
        }
        if (min==N-1)
            return -1;
        t=min;
        st[t]=1;
    }
    return dist[n];
}
int main(){
    cin>>n>>m;
    int a,b,c;
    memset(h,-1,sizeof(h));
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<bfs();
    system("pause");
}
*/
/*
自写
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+1;
int g[510][510],dist[N],st[N],n,m;
int dijkstra(){
    int now=1;
    dist[now]=0,st[now]=1;
    dist[N-1]=0x3f3f3f3f;
    while (now!=n){
        int imin=N-1;
        for (int i=1;i<=n;i++){
            if (g[now][i]!=0x3f3f3f3f && !st[i]){
                dist[i]=min(dist[i],dist[now]+g[now][i]);
            }
            if (!st[i] && dist[i]<dist[imin])
                imin=i;
        }
        if (imin==N-1)
            return -1;
        now=imin;
        st[now]=1;
    }
    return dist[n];
}
int main(){
    cin>>n>>m;
    int a,b,c;
    memset(g,0x3f,sizeof(g));
    memset(dist,0x3f,sizeof dist);
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        if (g[a][b]>c)
            g[a][b]=c;
    }
    cout<<dijkstra();
}
*/
//另一版本;
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
int dist[N],st[N],n,m,g[510][510];
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for  (int i=1;i<=n;i++){
        int t=-1;
        for (int j=1;j<=n;j++){
            if (!st[j] && (t==-1 || dist[t]>dist[j]))
                t=j;
        }
        if (dist[t]==0x3f3f3f3f)
            break;
        st[t]=1;
        for (int j=1;j<=n;j++){
            if (!st[j] && g[t][j]!=0x3f3f3f3f)
                dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    if (dist[n]==0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main(){
    cin>>n>>m;
    int a,b,c;
    memset(g,0x3f,sizeof g);
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
     cout<<dijkstra();
}
