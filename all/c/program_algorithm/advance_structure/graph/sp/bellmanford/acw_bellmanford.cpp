//每次迭代都不经过不超过k条边的最短路径
//bellmanford算法
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
struct Node{
    int a,b,w;
}arr[N];
int dist[510],backup[510],n,m,k;
void bellmanford(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    int a,b,w;
    for (int i=0;i<k;i++){
        memcpy(backup,dist,sizeof dist);
        for (int j=0;j<m;j++){
            a=arr[j].a,b=arr[j].b,w=arr[j].w;
            if (backup[a]!=0x3f3f3f3f)
                dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if (dist[n]==0x3f3f3f3f)
        printf("impossible");
    else
        printf("%d",dist[n]);
}
int main(){
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i]={a,b,c};
    }
    bellmanford();
}