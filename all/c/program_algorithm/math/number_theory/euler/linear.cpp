//约为O(n)
//lg P2158
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int vis[N],prime[N],phi[N],sum[N];
//phi欧拉函数，sum求前缀和
void get_phi(){
    phi[1]=1;
    int cnt=0;
    for (int i=2;i<N;i++){
        if (!vis[i]){
            vis[i]=i;//vis[i]=1;前者用于记录每个数的最小质因数，后者记录是否被筛
            prime[cnt++]=i;
            phi[i]=i-1;
        }
        for (int j=0;j<cnt;j++){
            if (i*prime[j]>N) break;
            vis[i*prime[j]]=prime[j];
            if (i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];//i与prime[j]互素
        }
    }
}
signed main(){
    get_phi();
    sum[1]=1;
    for (int i=2;i<=N;i++) sum[i]=sum[i-1]+phi[i];
    int n;
    cin>>n;
    if (n==1) cout<<0<<"\n";
    else cout<<2*sum[n-1]+1<<"\n";
}