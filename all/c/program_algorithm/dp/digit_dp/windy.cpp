//lg P2657
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int num[15];
int dp[15][15][2][2];
//lead前导0，或者有没有选过数字，所以0是排除在外的
int dfs(int pos,int last,bool lead,bool limit){
    if (pos==0 && last==-2 && lead==true && limit==true)    return 0;
    if (dp[pos][last][lead][limit]!=-1) {return dp[pos][last][lead][limit];}//奇怪的dp[0][-2][1][1]=0;?
    if (pos==0) {return 1;}
    int ans=0;  
    int up=(limit?num[pos]:9);
    for (int i=0;i<=up;i++){
        if (abs(i-last)<2)  continue;
        if (i==0 && lead)   ans+=dfs(pos-1,-2,true,limit && i==up);
        else ans+=dfs(pos-1,i,false,limit && i==up);
    }
    dp[pos][last][lead][limit]=ans;
    return ans;
}
//后0~9完成后0~99只要记忆化就好,所以O(n*10),n为长度；
int solve(int x){
    if (!x) return 0;
    int len=0;
    while(x)    {num[++len]=x%10;x/=10;}
    memset(dp,-1,sizeof dp);
    return dfs(len,-2,true,true);//0不算，不在范围内，所以一开始true,也没问题
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1);
}