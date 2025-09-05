#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+10;
int n;
int size[N],dp[N],sum[N];
int e[2*N],ne[2*N],h[N],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main(){
    int t=1;
    //cin>>t;
    while (t--){
        memset(h,-1,sizeof h);
        idx=0;
        cin>>n;
        int a,b;
        for (int i=1;i<=n;i++){
            cin>>a>>b;
            add(a,b);add(b,a);
        }
    }
}