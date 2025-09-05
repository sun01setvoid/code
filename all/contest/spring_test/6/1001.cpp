#include <iostream>
using namespace std;
typedef long long LL;
LL a[3],sum,k,ma;
void dfs(int x){
    if (sum>k)  return;
    if (x==3){
        if (sum>ma) ma=sum;
        return ;
    }
    dfs(x+1);
    sum+=a[x];
    dfs(x+1);
    sum-=a[x];
}
int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>k>>a[0]>>a[1]>>a[2];
        sum=ma=0;
        dfs(0);
        cout<<k-ma<<endl;
    }
}