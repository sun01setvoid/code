#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10,M=2*N;
int n;
int h[N],e[M],ne[M],idx;
int sz[N],mi;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    int ans=0;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dfs(j,u);
        ans=max(ans,sz[j]);
        sz[u]+=sz[j];
    }
    ans=max(ans,n-sz[u]);
    mi=min(ans,mi);
}
int main(){
    memset(h,-1,sizeof h);
    mi=0x3f3f3f3f;
    int a,b;
    cin>>n;
    for (int i=1;i<=n-1;i++){
        cin>>a>>b;
        add(a,b);add(b,a);
    }
    dfs(1,1);
    cout<<mi;
}

//

/*
int sz[MAXN],  // 这个节点的「大小」（所有子树上节点数 + 该节点）
    w[MAXN],  // 这个节点的「重量」，即所有子树「大小」的最大值
    g[2];  // 用于记录树的重心（存的是节点编号）

void dfs(int u, int fa) { 
  sz[u] = 1;
  w[u] = 0;
  for (int i = h[u]; i != -1; i = ne[i]) {
    if (e[i] != fa) { 
      dfs(e[i], u);
      sz[u] += sz[e[i]];
      w[u] = max(w[u], sz[e[i]]);
    }
  }
  w[u] = max(w[u], n - sz[u]);
  if (w[u] <= n / 2) {  // 依照树的重心的定义统计
    g[g[0] != 0] = u;
  }
}
  */


//centroid

//点权重心，把点权设为初始size

