//lg 3287方伯伯的玉米
#include <iostream>
using namespace std;
const int N=10010,K=510,A=5510;
int a[N],dp[N][K],t[K][A];
int n,k;
int lowbit(int x){
    return x&-x;
}
void update(int p,int v,int d){
    for (int i=p;i<=k+1;i+=lowbit(i)){
        for (int j=v;j<=5501;j+=lowbit(j)){
            t[i][j]=max(t[i][j],d);//长度一定越来越长，所以不需要用它的直接子节点来更新当前节点？？？？
        }
    }
}
int query(int p,int v){
    int ans=0;
    for (int i=p;i;i-=lowbit(i)){
        for (int j=v;j;j-=lowbit(j)){
            ans=max(t[i][j],ans);
        }
    }
    return ans;
}
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)  cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=k+1;j;j--){
            dp[i][j]=query(j,a[i]+j)+1;//把j'->j+1,即[0,k]->[1,k+1];
            update(j,a[i]+j,dp[i][j]);
        }
    }
    cout<<query(k+1,5501);//不能用dp[i][k+1];因为不一定以i结尾
    return 0;
}