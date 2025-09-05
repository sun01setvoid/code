#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
int h[N],e[N*2],ne[N*2],w[N*2],ans=N,st[N],n;//注意双向边两倍内存
int dfs(int x){
    st[x]=1;
    int dot=0,sum=1;
    for (int cur=h[x];cur!=-1;cur=ne[cur]){
        int j=e[cur];
        if (!st[j]){
            int s=dfs(j);
            dot=max(dot,s);
            sum+=s;//不要回溯，每个点只走一次
        }
    }//无向图但是走过的不能走，所以变成树了
    dot=max(dot,n-sum);
    ans=min(ans,dot);
    return sum;
}
int main(){
    int idx=1,a,b;
    cin>>n;
    memset(h,-1,sizeof(h));
    for (int i=0;i<n-1;i++){
        cin>>a>>b;
        e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
        e[idx]=a,ne[idx]=h[b],h[b]=idx,idx++;//双向边
    }//必定没有重边
    dfs(1);//树一定连通且n-1条边无环，且这道题从哪开始都可以
    cout<<ans;
    system("pause");
}