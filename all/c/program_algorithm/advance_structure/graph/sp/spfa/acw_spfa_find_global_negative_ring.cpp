//spfa
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1e5+10;
int h[N],w[N],e[N],ne[N],idx;
int dist[N],cnt[N],n,m;//判断负环dist多少都行，负环一定能一直入队；
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx,idx++;
}
void spfa(){
    queue <int > q;
    for (int i=1;i<=n;i++){
        q.push(i);
        st[i]=1;
    }
    while (q.size()){
        int t=q.front();
        q.pop();
        if (cnt[t]>=n){
            printf("Yes");
            return;
        }
        st[t]=0;
        for (int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if (!st[j]){
                    q.push(j);
                    st[j]=1;
                }
            }
        }
    }
    printf("No");
    return;
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    int a,b,c;
    for  (int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
}