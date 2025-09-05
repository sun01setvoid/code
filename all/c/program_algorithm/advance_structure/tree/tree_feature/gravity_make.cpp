//CF708C
//sz[i],maxsub[i](i的最小子树)，inner1[i]：内部，<=n/2且第一大的子树大小，
//inner2[i]：内部，<=n/2且第二大的的子树大小，choose[i]：拥有inner1[i]的儿子
//outer[i]：外部,<=n/2且最大的子树大小（3种情况）
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