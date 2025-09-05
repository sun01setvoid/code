#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=1e5+10;
int h[N],e[N],w[N],ne[N],idx,n,m,st[N],dist[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx,idx++;
}
void spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue <int> q;
    q.push(1);
    st[1]=1;
    while (q.size()){
        int t=q.front();
        q.pop();
        st[t]=0;
        for (int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                if (!st[j]){
                    q.push(j);
                    st[j]=1;
                }
            }
        }
    }
    if (dist[n]==0x3f3f3f3f){
        printf("impossible");
    }
    else 
    printf("%d",dist[n]);
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    int a,b,c;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
}