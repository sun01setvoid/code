//lg P2015
//这里直接采用多叉树写法,<O(n3)
#include <iostream>
#include <vector>
using namespace std;
const int N=110;
struct node{
    int v,w;
};
vector <node> G[N];
int dp[N][N],sum[N];
int n,q;

void dfs(int u,int fa){
    for (auto t:G[u]){
        int v=t.v,w=t.w;
        if (v==fa)  continue;
        dfs(v,u);
        sum[u]+=sum[v]+1;
        for (int j=min(q,sum[u]);j>=0;j--){
            for (int k=0;k<=min(sum[v],j-1);k++){
                dp[u][j]=max(dp[u][j],dp[u][j-k-1]+dp[v][k]+w);
            }       //后面一个节点用0条边时就默认dp[u][j],因为从后往前，所以是dp[i-1][u][j]
        }
    }
}

int main(){
    int a,b,c;
    cin>>n>>q;
    n--;
    while (n--){
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs(1,0);
    printf("%d",dp[1][q]);
    return 0;
}