//O(n+m)离线    acw1171距离
#include <iostream>
#include <vector>
using namespace std;
const int N=4e4+10;
int ans[N],vis[N],fa[N],dist[N];
int h1[N],e1[N],ne1[N],w1[N],idx1=1;
int h2[N],e2[N],ne2[N],w2[N],idx2=1;
void add1(int a,int b,int c){
    e1[idx1]=b,ne1[idx1]=h1[a],w1[idx1]=c,h1[a]=idx1,idx1++;
}
void add2(int a,int b,int c){
    e2[idx2]=b,ne2[idx2]=h2[a],w2[idx2]=c,h2[a]=idx2,idx2++;
}
int find(int x){
    if (fa[x]!=x)   fa[x]=find(fa[x]);
    return fa[x];
}
void dfs(int x,int f){
    for (int i=h1[x];i;i=ne1[i]){
        int j=e1[i];
        if (j!=f){
            dist[j]=dist[x]+w1[i];
            dfs(j,x);
        }//在树中用vis标记或者j!=fa是一样的,DAG图用vis比较多
    }
}//根左右
void tarjan(int x){
    vis[x]=1;
    for (int i=h1[x];i;i=ne1[i]){
        int j=e1[i];
        if (!vis[j]){
            tarjan(j);
            fa[j]=x;//回溯时连上边
        }
    }
    vis[x]=2;//本身与本身的祖先必须这么写
    for (int i=h2[x];i;i=ne2[i]){
        int j=e2[i];
        if (vis[j]==2){
            int lca=find(j);
            ans[w2[i]]=dist[j]+dist[x]-dist[lca]*2;
        }
    }
}//左右根
int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        fa[i]=i;
    }
    for (int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        add1(a,b,c),add1(b,a,c);
    }
    for (int i=0;i<m;i++){
        cin>>a>>b;
        if (a==b)   continue;//自己的lca就是自己,距离就是0
        add2(a,b,i),add2(b,a,i);
    }
    dfs(1,-1);
    tarjan(1);
    for (int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
}