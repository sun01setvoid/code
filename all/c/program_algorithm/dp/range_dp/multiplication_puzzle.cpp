//区间dp poj1651
#include <iostream>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int n;
int dp[110][110];
int p[110];
int main(){
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    for (int i=0;i<n;i++)   cin>>p[i];
    for (int i=1;i<=n-1;i++)    dp[i][i]=0;//矩阵本省不需要运算步骤
    for (int len=2;len<=n-1;len++){
        for (int i=1;i<=n-len;i++){
            int j=i+len-1;
            for (int k=i;k<j;k++)
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
        }
    }
    cout<<dp[1][n-1];
}