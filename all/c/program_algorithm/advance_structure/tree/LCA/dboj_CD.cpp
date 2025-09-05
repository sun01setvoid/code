//映射一下
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int M=10;
map <string,int> mp;
int st[M];
int f[M][18],h[M],e[M],ne[M],idx=1,cnt=0,top=-1,vis[M],d[M];
void add(int x,int y){
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
void topo(int a){
    vis[a]=1;
    for (int i=h[a];i;i=ne[i]){
        int j=e[i];
        if (!vis[j]){
            topo(j);
        }
    }
    st[++top]=a;
}
void dfs(int x){
    for (int i=1;1<<i<=d[x];i++){
        if (f[x][i-1])  f[x][i]=f[f[x][i-1]][i-1];
    }
    for (int i=h[x];i;i=ne[i]){
        int j=e[i];
        d[j]=d[x]+1;
        f[j][0]=x;
    }
}
int LCA(int a,int b){
    if (d[a]<d[b])  swap(a,b);
    for (int i=17;i>=0;i--){
        if (d[a]-1<<i>=d[b])
            a=f[a][i];
    }
    if (a==b)   return b;
    for (int i=17;i>=0;i--){
        if (f[a][i]!=f[b][i])
            a=f[a][i],b=f[b][i];
    }
    return f[a][0];
}
int main(){
    int t;
    int n,m;
    string x,y;
    cin>>t;
    while (t--){
        idx=1;
        top=-1;
        cnt=0;
        cin>>n>>m;
        mp.clear();
        for (int i=0;i<n-1;i++){
            cin>>x>>y;
            if (!mp.count(x))
                mp[x]=++cnt;
            if (!mp.count(y))
                mp[y]=++cnt;
            add(mp[y],mp[x]);
        }
        for (int i=1;i<=cnt;i++){
            if (!vis[i])  topo(i);
        }
        dfs(st[top]);
        for (int i=0;i<m;i++){
            cin>>x>>y;
            int anc=LCA(mp[x],mp[y]);
            if (anc==mp[x]) cout<<1<<endl;
            else if (anc==mp[y]) cout<<d[mp[x]]-d[mp[y]]<<endl;
            else{
            cout<<d[mp[x]]-d[anc]+1<<endl;
            }
        }
    }
}