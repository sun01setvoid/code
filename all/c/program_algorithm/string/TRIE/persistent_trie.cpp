//P4735 persistent trie
//最大异或和
#include <iostream>
using namespace std;
const int N=6e5+10,M=N*25;//因为每个根节点都要占用一个块N+N*24
int root[N],tr[M][2];//每个版本都记录
int s[N],n,m,max_id[M],idx;//前缀异或和,最大id值
//至少存在一个数在l-r内等于在r内这个数的最大id值>=l
void insert(int i,int k,int p,int q){
    if (k<0){
        max_id[q]=i;
        return;
    }
    int v=s[i]>>k&1;
    if (p)  tr[q][v^1]=tr[p][v^1];
    tr[q][v]=++idx;
    insert(i,k-1,tr[p][v],tr[q][v]);
    max_id[q]=max(max_id[tr[q][0]],max_id[tr[q][1]]);//就是存在这样的数的最大id值
    //其实也就是max_id[q]=1;
}
int find(int rt ,int C,int L){
    int p=rt;
    for (int i=23;i>=0;i--){
        int v=C>>i&1;
        if (max_id[tr[p][v^1]]>=L)  p=tr[p][v^1];//贪心
        //max_id[0]=-1;若是查询l-1==0了，这样的话，就一定会走另一边,要走存在的一边，也就是&&tr[p][v^1];
        else p=tr[p][v];
    }
    return C^s[max_id[p]];
}
int main(){
    scanf("%d %d",&n,&m);
    max_id[0]=-1;
    root[0]=++idx;
    insert(0,23,0,root[0]);//因为要查root[0]里的数的,s[r-1]可等于s[0];存0
    for (int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=s[i-1]^s[i];
        root[i]=++idx;
        insert(i,23,root[i-1],root[i]);
    }
    char op[2];
    int x,l,r;
    for (int i=1;i<=m;i++){
        scanf("%s",op);
        if (*op=='A'){
            scanf("%d",&x);
            n++;
            s[n]=s[n-1]^x;
            root[n]=++idx;
            insert(n,23,root[n-1],root[n]);
        }
        else{
            scanf("%d %d %d",&l,&r,&x);
            printf("%d\n",find(root[r-1],s[n]^x,l-1));
        }
    }
}