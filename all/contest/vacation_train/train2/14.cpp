#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+10,M=110;
const int P=131;
typedef unsigned long long ULL;
int ans[N],w[N];
int vis[M];
ULL g[M];
ULL h[N],p[N];
int a[N];
int n,m,k;
ULL get (int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
bool dfs(int u,int en){
    if (en==n)    return true;
    for (int i=1;i<=m;i++){
        if (!vis[i] && g[i]==get(en,en+w[i]-1)){
            vis[i]=1;
            ans[u]=i;
            if (dfs(u+1,en+w[i]-1))    return true;
            ans[u]=0;
            vis[i]=0;
        }
    }
    return false;
}//给dfs(bool值)让他知道成功了，成功就一直返回,搜索完一个后恢复状态，因为后面可能通过别的再搜索到它，dfs是匹配一个长链
int main(){
    int temp;
    scanf("%d",&n);
    p[0]=1;
    for (int i=1;i<=n;i++)    cin>>a[i];
    for (int i=1;i<=n;i++){
        h[i]=h[i-1]*P+a[i];
        p[i]=p[i-1]*P;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d",&k);
        w[i]=k;
        for (int j=1;j<=k;j++){
            scanf("%d",&temp);
            g[i]=g[i]*P+temp;
        }
    }
    dfs(1,1);
    cout<<ans[1];
    for (int i=2;i<=m;i++)   cout<<" "<<ans[i];
}