#include <iostream>
using namespace std;
const int N=1e5+10;
int st[N],a[N],cnt;
void dfs(int u){
    st[u]=1;
    if (!st[a[u]])  dfs(a[u]);
    else{
        cnt++;
    }
}
int main(){
    int n,t;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;cnt=0;
        for (int j=1;j<=n;j++)  cin>>a[j],st[j]=0;
        for (int j=1;j<=n;j++){
            if (!st[j])
                dfs(j);
        }
        cout<<cnt-1<<endl;
    }
}