#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
};
bool vis[N];
int din[N];
int deep[N];
int n,k;
void dfs(int u,int fa){
    deep[u]=deep[fa]+1;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)    continue;
        dfs(j,u);
    }
}
int main(){
    cin>>n;
    int temp;
    memset(h,-1,sizeof h);
    for (int i=1;i<=n;i++){
        cin>>k;
        for (int j=0;j<k;j++){
            cin>>temp;
            add(i,temp);
            din[temp]++;
        }
    }
    int rt=-1;
    for (int i=1;i<=n;i++){
        if (!din[i])    {rt=i;break;}
    }
    dfs(rt,0);
    int id=0;
    for (int i=1;i<=n;i++){
        if (deep[i]>deep[id])    id=i;
    }
    cout<<id;
}