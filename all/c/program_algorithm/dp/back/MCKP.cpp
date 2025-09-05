//其实是从「在所有物品中选择一件」变成了「从当前组中选择一件」，于是就对每一组进行一次 0-1 背包就可以了。
//分组背包
#include <iostream>
using namespace std;
int V,N;
int w[110][1010],v[110][1100],cnt[110];
int dp[1010];
int main(){
    cin>>V>>N;
    int m=1;
    int a,b,c;
    for (int i=1;i<=N;i++){
        cin>>a>>b>>c;
        ++cnt[c];
        v[c][cnt[c]]=a;
        w[c][cnt[c]]=b;
        m=max(c,m);
    }
    for (int i=1;i<=m;i++)
        for (int j=V;j>=0;j--){
            for (int k=1;k<=cnt[i];k++)
                if (j>=v[i][k]){
                    dp[j]=max(dp[j],dp[j-v[i][k]]+w[i][k]);
                }
        }
    cout<<dp[V];
}