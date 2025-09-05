#include <iostream>
using namespace std;
const int N=2e5+10,M=N*32;//O(个数*长度)
typedef long long LL;
int root[N],tr[M][2];
int n,m,max_id[M],idx;
LL s[N];
void insert(int i,int k,int p,int q){
    if (k<0){
        max_id[q]=i;
        return;
    }
    int v=s[i]>>k&1;
    if (p)  tr[q][v^1]=tr[p][v^1];
    tr[q][v]=++idx;
    insert(i,k-1,tr[p][v],tr[q][v]);
    max_id[q]=max(max_id[tr[q][0]],max_id[tr[q][1]]);
}
LL find(int rt ,LL  C,int L){
    int p=rt;
    for (int i=30;i>=0;i--){
        int v=C>>i&1;
        if (max_id[tr[p][v^1]]>=L)  p=tr[p][v^1];//max_id[0]=-1 和  tr[p][v^1] !=0取1即可
        else p=tr[p][v];
    }
    return C^s[max_id[p]];
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        idx=0;
        scanf("%d %d",&n,&m);
        max_id[0]=-1;
        root[0]=++idx;
        insert(0,30,0,root[0]);
        for (int i=1;i<=n;i++){
            scanf("%lld",&s[i]);
            root[i]=++idx;
            insert(i,30,root[i-1],root[i]);
        }
        LL x;
        int l,r;
        for (int i=1;i<=m;i++){
            scanf("%d %d %lld",&l,&r,&x);
            printf("%lld\n",find(root[r],x,l));
        }
        for (int i=1;i<=idx;i++) tr[i][0]=tr[i][1]=0,max_id[i]=0;
    }
}