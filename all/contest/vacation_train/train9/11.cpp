#include <iostream>
#include <vector>
using namespace std;
const int N=1e5+10;
int n,rt;
int d[N],vis[N];
vector <int> G[N];
bool f=1;
void dfs1(int u){
    int sum=0;
    if (u!=rt)    sum++;
    for (auto i:G[u])    sum++,dfs1(i);
    d[u]=sum;
    if (G[u].size()==0)    vis[u]=1;
}
void dfs2(int u){
    if (u==rt)    cout<<u;
    else    cout<<" "<<u;
    for (auto i:G[u])    dfs2(i);
}
int main(){
    cin>>n;
    int a,b;
    for (int i=1;i<=n;i++){
        cin>>a;
        if (a==0)    rt=i;
        else    G[a].push_back(i);
    }
    dfs1(rt);
    int ans=0;
    for (int i=1;i<=n;i++){
        if (d[i]!=d[rt] && !vis[i])    {f=0;break;}
    }
    cout<<d[rt]<<" "<<(f?"yes":"no")<<endl;
    dfs2(rt);
}