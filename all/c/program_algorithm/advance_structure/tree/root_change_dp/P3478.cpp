#include <iostream>
#include <cstring>
using namespace std;
#define int long long
const int N=1e6+10;
int n;
int sz[N],dp[N],sum[N];
int e[2*N],ne[2*N],h[N],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs1(int u,int fa){
    sz[u]=1;
    sum[u]=0;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (j==fa) continue;
        dfs1(j,u);
        sz[u]+=sz[j];
        sum[u]+=sum[j]+sz[j];
    }
}
void dfs2(int u,int fa){
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (j==fa)  continue;
        dp[j]=dp[u]-sz[j]+n-sz[j];
        dfs2(j,u);
    }
}
signed main(){
    memset(h,-1,sizeof h);
    cin>>n;
    int a,b;
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        add(a,b);add(b,a);
    }
    dfs1(1,0);
    dp[1]=sum[1];
    dfs2(1,0);
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}