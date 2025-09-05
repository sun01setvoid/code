//二叉树，每个结点维护范围，二分范围(在dfs（update,query）中lc,l,r二分范围)
//L,R是查找区间，l,r是lc范围,从根节点开始
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1000010;
int n;
struct trnode{
    int sum;
    int lazy;
}tr[maxn<<2];
vector <int> E(maxn);
void pushup(int lc){
    tr[lc].sum=tr[lc<<1].sum+tr[lc<<1|1].sum;
}
void pushdown(int lc,int ll,int rl){//下推确保子节点准确
    tr[lc<<1].lazy+=tr[lc].lazy,tr[lc<<1|1].lazy+=tr[lc].lazy;
    tr[lc<<1].sum+=tr[lc].lazy*ll,tr[lc<<1|1].sum+=tr[lc].lazy*rl;
    tr[lc].lazy=0;//清除标记
}
void build(int lc,int l,int r){//建树
	if(l==r){
		tr[lc].sum=E[l];
        tr[lc].lazy=(tr[lc].sum<=1);
		return;
	}
	int m = (l+r)>>1;
    build(lc<<1,l,m);build(lc<<1|1,m+1,r);
	pushup(lc);
}
void update(int L,int R,int V,int lc,int l,int r){//对大的区间做延迟标记
    if (l>=L && r<=R){
        tr[lc].sum+=(r-l+1)*V;
        tr[lc].lazy+=V;
        return;
    }
    //if (r<L || l>R) return ;//与二分后区间是否要选取区间对应
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);//这是有需要的，因为子节点可能要用，万一这一层有懒惰标记，要确保子节点不出错————和pushup配合保证不出错
    if (L<=m) update(L,R,V,lc<<1,l,m);
    if (R>=m+1) update(L,R,V,lc<<1|1,m+1,r);
    pushup(lc);
}//保证找到的区间及其上面是最新的,因为要用到这个区间的时候只可能用到他或者他以上的
int query(int L,int R,int lc,int l,int r){//使用区间更新下的q
    if (l>=L && R>=r)   return tr[lc].sum;
    if (r<L || l>R) return 0;
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    return query(L,R,lc<<1,l,m)+query(L,R,lc<<1|1,m+1,r);
}
int main(){
    int a,b;
    while (cin>>n && n){
        for (int i=1;i<=4*n;i++){
        	tr[i]={0,0};
        }//四倍肯定包含所有了,线段树的memset更容易TLE
        for (int i=1;i<=n;i++){
            cin>>a>>b;
            update(a,b,1,1,1,n);
        }
      	cout<<query(1,1,1,1,n);
        for (int i=2;i<=n;i++){
            cout<<" "<<query(i,i,1,1,n);
        }
        cout<<endl;
    }
}
