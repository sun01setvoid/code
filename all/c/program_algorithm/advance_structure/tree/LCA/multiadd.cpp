//acw1172祖孙询问
#include <iostream>
#include <algorithm>
using namespace std;
const int N=4e4+10;;
int h[N],e[2*N],ne[2*N],idx=1;
int p[N][20],deep[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
void dfs(int x,int fa){
    for (int i=1;1<<i<=deep[x];i++){
        if (p[x][i-1]){
            p[x][i]=p[p[x][i-1]][i-1];
            //因为搜索的缘故，所以它的祖先一定都已经处理过p[anc][0]
        }
    }
    for (int i=h[x];i;i=ne[i]){
        int j=e[i];
        if (j!=fa){
            deep[j]=deep[x]+1;
            p[j][0]=x;
            dfs(j,x);
        }
    }
}
int lca(int a,int b){
    if (deep[a]<deep[b])    swap(a,b);
    for (int i=15;i>=0;i--){
        if (deep[a]-(1<<i)>=deep[b]){
            a=p[a][i];
        }
    }
    if (a==b)   return b;//这里保证有直接祖先的lca计算合理
    for (int i=15;i>=0;i--){
        if  (p[a][i] && p[a][i]!=p[b][i]){
            a=p[a][i],b=p[b][i];
        }
    }//到lca的下一层
    return p[a][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    int a,b,rt;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        if (b==-1)  rt=a;
        add(a,b),add(b,a);
    }
    dfs(rt,0);
    cin>>m;
    int res;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        res=lca(a,b);
        if (res==a) cout<<1<<endl;
        else if (res==b)    cout<<2<<endl;
        else    cout<<0<<endl;
    }
}
//或者先dfs存深度和记录父节点,然后进行区间dp求得st表