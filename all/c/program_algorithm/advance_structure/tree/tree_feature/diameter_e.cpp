//很难得到沿途的路径
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],w[N],idx;
int dp[N],f[N];
int n,diam;
//dp[u]是以u为根的子树中的点的最远距离
//f[u]是经过u这个点的最长路径
//一定有一条路径以一个点为中心
//且若向上的路可以走，那么上面的的点可以作为根
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs(j,u);
        f[u]=max(dp[u]+dp[j]+w[i],f[u]);
        dp[u]=max(dp[j]+w[i],dp[u]);
        diam=max(diam,f[u]);
    }
}
int main(){
    memset(h,-1,sizeof h);
    int a,b,c;
    cin>>n;
    for (int i=1;i<=n-1;i++){
        cin>>a>>b>>c;
        add(a,b,c);add(b,a,c);
    }
    dfs(1,-1);
    cout<<diam<<"\n";
}

//另一种
//如果需要求出一条直径上所有的节点，
//则可以在 DP 的过程中，
//记录下每个节点能向下延伸的最长路径与次长路径（定义同上）所对应的子节点
//在求 d 的同时记下对应的节点 u，使得 d = d1[u] + d2[v]
//即可分别沿着从 u 开始的最长路径的次长路径对应的子节点一路向某个方向
//（对于无根树，虽然这里指定了 1 为树的根，但仍需记录每点跳转的方向；对于有根树，一路向上跳即可），
//遍历直径上所有的节点。
//其实就是求最长路径和次长路径