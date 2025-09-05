//dijkstra算法
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair <int,int> PII;
const int N=1e6+10;
int h[N],e[N],w[N],ne[N],idx=0,n,m,st[N],dist[N];
int dijkstrapp(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue <PII,vector <PII> ,greater <PII> > heap;
    heap.push({0,1});
    while (heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second,dis=t.first;
        if (st[ver])    continue;//重边,冗余
        st[ver]=1;
        for (int cur=h[ver];cur!=-1;cur=ne[cur]){
            int j=e[cur];
            if (!st[j] && dist[j]>dis+w[cur]){
                dist[j]=dis+w[cur];
                heap.push({dist[j],j});
            }
        } 
    }
    if (dist[n]==0x3f3f3f3f)
        return -1;
    return dist[n];
}
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx,idx++;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    int a,b,c;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstrapp( );
}
/*
不更新也对，不过会有很多冗余情况考虑，同一个顶点x，可能在队列中有(dis1, x)、(dis2, x)存在，
而dis1<dis2，所以(dis1, x)先出队并更新x的邻接顶点，当(dis2, x)出队的时候，由于dis2>dis1，
所以x的邻接顶点此时都不会更新，那么(dis2, x)这一步也就冗余了
*/