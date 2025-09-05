//hdu 1542
//没有懒信息下发，懒信息是为了防止子节点信息不准确
//但这里删除表示前面一定有这样一段y长度,且查询只要查根节点，所以没有懒信息下发
#include <iostream>
using namespace std;
const int maxn=1000010;
int n;
struct trnode{
    int sum;
    int lazy;
}tr[maxn<<2];
void pushup(int lc){
    tr[lc].sum=tr[lc<<1].sum+tr[lc<<1|1].sum;
}
void pushdown(int lc,int ll,int rl){
    tr[lc<<1].lazy+=tr[lc].lazy,tr[lc<<1|1].lazy+=tr[lc].lazy;
    tr[lc<<1].sum+=tr[lc].lazy*ll,tr[lc<<1|1].sum+=tr[lc].lazy*rl;
    tr[lc].lazy=0;
}
void build(int lc,int l,int r){
	if(l==r){
		cin>>tr[lc].sum;
		return;
	}
	int m = (l+r)>>1;
    build(lc<<1,l,m);build(lc<<1|1,m+1,r);
	pushup(lc);
}
void update(int L,int R,int V,int lc,int l,int r){
    if (l>=L && r<=R){
        tr[lc].sum+=(r-l+1)*V;
        tr[lc].lazy+=V;
        return;
    }
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    if (L<=m) update(L,R,V,lc<<1,l,m);
    if (R>=m+1) update(L,R,V,lc<<1|1,m+1,r);
    pushup(lc);
}
int query(int L,int R,int lc,int l,int r){
    if (l>=L && R>=r)   return tr[lc].sum;
    if (r<L || l>R) return 0;
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    return query(L,R,lc<<1,l,m)+query(L,R,lc<<1|1,m+1,r);
}
int main(){

}