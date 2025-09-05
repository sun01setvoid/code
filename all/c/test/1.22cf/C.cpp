//度数和连通分量的个数有关，但两个点有相邻和不相邻的问题，删除一个点，增加deg-1个连通分量
/*
因为难处在于可能选到的第一个点和其他的都相邻，但是在度最大的多个点中，可能有不相邻的点
从1个到2个到三个思考
假设这些顶点是 u 和 v，而第二个顶点选择为 𝑤
对于多个相同度数的情况，u,v,w三点，若u-v,w-v,则w-u不可能成立，没有三角树，至少有一对不相邻，所以找两个就行
*/
#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200010;
int h[N],e[N],ne[N],idx,fa[N];
struct Sz{
    int val;
    int order;
}Size[N];
bool cmp(Sz& a,Sz&b){
    return a.val>b.val;
}
set <int> ans;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
int find(int x){
    if (fa[x]!=x)   fa[x]=find(fa[x]);
    return fa[x];
}
void dfs(int x,int fa){
    for (int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if (j!=fa){
            dfs(j,x);
            Size[x].val++;
        }
    }
}
int main(){
    int t;
    int n,a,b;
    cin>>t;
    while (t--){
        ans.clear();
        cin>>n;
        memset(h,-1,sizeof(int)*(n+1));
        idx=0;
        for (int i=1;i<=n;i++)  Size[i].val=0,Size[i].order=i,fa[i]=i;
        for (int i=0;i<n-1;i++){
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
        dfs(1,1);
        sort(Size+1,Size+n+1,cmp);
        ans.insert(Size[1].order);
        ans.insert(Size[2].order);
        for (int i=1;i<=n;i++){
            for (int j=h[i];~j;j=ne[j]){
                int k=e[j];
                if (!ans.count(i) && !ans.count(k)){
                    int f1=find(i),f2=find(k);
                    if (f1!=f2) fa[f1]=f2;
                }
            }
        }
        int cnt=0;
        for (int i=1;i<=n;i++){
            if (fa[i]==i && !ans.count(i))   cnt++;
        }
        cout<<cnt<<endl;
    }
}