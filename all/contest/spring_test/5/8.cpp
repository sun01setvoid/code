//每个方案都不同，但有部分相交的位置是没关系的，所以就是选[n/2]个都不同则无解
#include <iostream>
#include <cstring>
using namespace std;
const int N=2e5+10,M=5e6+10;
int a[N],f[M];
int sum,T,flag,n,m;
void dfs(int x,int l){
    if (flag)   return ;
    if (!l){
        if (f[sum]) {flag=true;return;}
        f[sum]=1;
        return;
    }
    if (x>n)    return;
    dfs(x+1,l);
    sum+=a[x];
    dfs(x+1,l-1);
    sum-=a[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++)  cin>>a[i];
        if (n>=24)  cout<<"YES\n";
        else{
            memset(f,false,sizeof f);
            flag=false;
            dfs(1,n/2);
            if (flag)   cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}