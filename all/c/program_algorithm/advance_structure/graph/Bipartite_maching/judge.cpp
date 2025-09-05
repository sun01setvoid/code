#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10;
int h[N],e[2*N],ne[2*N],idx;
int color[N],n,m;
void add(int a,int b){
    e[idx]=b;ne[idx]=h[a],h[a]=idx,idx++;
}
int dfs(int u,int x){
    color[u]=x;
    for (int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if (!color[j]){
            if(!dfs(j,3-x)) return 0;
            }
        else{
            if (color[j]==color[u]) return 0;
        }
    }
    return 1;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    int flag=1;
    for (int i=1;i<=n;i++){
        if (!color[i]){
            if (!dfs(i,1))  {flag=0;break;}
        }
    }
    if (flag)   cout<<"Yes";
    else cout<<"No";
}