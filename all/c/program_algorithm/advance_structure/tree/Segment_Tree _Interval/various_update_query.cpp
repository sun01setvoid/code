//多种查找找其中转换关系，用多个元素记录
//多种标记，确定好下推等的前后顺序
//二叉树，每个结点维护范围，二分范围(在dfs（update,query）中lc,l,r二分范围)
//L,R是查找区间，l,r是lc范围,从根节点开始
//hdu 4578
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100010,mod=10007;
struct trnode{
    LL sum[3];
    LL change,add,multi;//change,multi,add,下推时ll能保证准确
}tr[maxn<<2];
void pushup(int lc){
    tr[lc].sum[2]=(tr[lc<<1].sum[2]+tr[lc<<1|1].sum[2])%mod;
    tr[lc].sum[1]=(tr[lc<<1].sum[1]+tr[lc<<1|1].sum[1])%mod;
    tr[lc].sum[0]=(tr[lc<<1].sum[0]+tr[lc<<1|1].sum[0])%mod;
}
void pushdown(int ll,int rl,int lc){//下推确保子节点准确
    trnode &p = tr[lc], &l = tr[lc << 1], &r = tr[lc << 1 | 1];
	if (p.change){
		LL d = p.change; 
		l.sum[2] = ll * d*d*d % mod; 	
		l.sum[1] = ll * d*d% mod; 	
		l.sum[0] = ll * d % mod; 
		r.sum[2] = rl * d*d*d % mod; 	
		r.sum[1] = rl * d*d% mod; 	
		r.sum[0] = rl * d % mod; 
		l.add = r.add = 0;
		l.multi= r.multi = 1;		
		l.change = r.change = d;
	} 
	if (p.multi != 1) {
		LL d = p.multi;
		l.sum[2] = d*d*d * l.sum[2] % mod;
		l.sum[1] = d*d * l.sum[1] % mod;
		l.sum[0] = d * l.sum[0] % mod;
		l.add = l.add * d % mod;
		l.multi = l.multi * d % mod;
		r.sum[2] = d*d*d * r.sum[2] % mod;
		r.sum[1] = d*d * r.sum[1] % mod;
		r.sum[0] = d * r.sum[0] % mod;
		r.add = r.add * d % mod;
		r.multi = r.multi * d % mod;
	}
	if (p.add) {
		LL d = p.add;
		l.sum[2] = (l.sum[2] + ll * d*d*d + 3 * d * l.sum[1] + 3 * d*d  * l.sum[0]) % mod;
		l.sum[1] = (l.sum[1] + 2 * d * l.sum[0] + ll * d*d) % mod;
		l.sum[0] = (l.sum[0] + ll * d) % mod;
		l.add = (l.add + d) % mod;
		r.sum[2] = (r.sum[2] + rl * d*d*d + 3 * d * r.sum[1] + 3 * d*d  * r.sum[0]) % mod;
		r.sum[1] = (r.sum[1] + 2 * d * r.sum[0] + rl * d*d) % mod;
		r.sum[0] = (r.sum[0] + rl * d) % mod;
		r.add = (r.add + d) % mod;
	}
	p.add = 0, p.multi = 1, p.change = 0;
}
void build(int l , int r, int lc) {
	tr[lc].sum[0] = tr[lc].sum[1] = tr[lc].sum[2] = tr[lc].change = tr[lc].add = 0;
	tr[lc].multi = 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build( l, mid,lc << 1);
	build(mid + 1, r,lc << 1 | 1); 
} 

void update(int L,int R,LL V,int l,int r,int lc,int p){//对大的区间做延迟标记
    int len=r-l+1;
    if (l>=L && r<=R){
        if (p==3){
            tr[lc].change=V;tr[lc].multi=1;tr[lc].add=0;
            tr[lc].sum[2] = len * V*V*V % mod; 
			tr[lc].sum[1] = len * V*V % mod; 
			tr[lc].sum[0] = len * V % mod;
        }
        else if(p==1){
            tr[lc].add=(tr[lc].add+V)%mod;
            tr[lc].sum[2]=(tr[lc].sum[2]+V*V*V*len+3*tr[lc].sum[1]*V+3*tr[lc].sum[0]*V*V)%mod;
            tr[lc].sum[1]=(tr[lc].sum[1]+V*V*len+2*tr[lc].sum[0]*V)%mod;
            tr[lc].sum[0]=(tr[lc].sum[0]+V*len)%mod;
        }
        else{
            tr[lc].multi=tr[lc].multi*V%mod;
            tr[lc].add=tr[lc].add*V%mod;
            tr[lc].sum[2] = V*V*V * tr[lc].sum[2] % mod;
			tr[lc].sum[1] = V*V * tr[lc].sum[1] % mod;
			tr[lc].sum[0] = V * tr[lc].sum[0] % mod;
        }
        return;
    }
    //if (r<L || l>R) return ;//与二分后区间是否要选取区间对应if
    int m=l+r>>1;
    pushdown(m-l+1,r-m,lc);//这是有需要的，因为子节点可能要用之前的状态，使子节点达到当前时间段状态，万一这一层有懒惰标记，要确保子节点不出错————和pushup配合保证不出错
    if (L<=m) update(L,R,V,l,m,lc<<1,p);
    if (R>=m+1) update(L,R,V,m+1,r,lc<<1|1,p);
    pushup(lc);
}//保证找到的区间及其上面是最新的,因为要用到这个区间的时候只可能用到他或者他以上的
LL query(int L,int R,int l,int r,int lc,int p){//使用区间更新下的q
    if (l>=L && R>=r)   return tr[lc].sum[p];
    if (r<L || l>R) return 0;
    int m=l+r>>1;
    pushdown(m-l+1,r-m,lc);
    return (query(L,R,l,m,lc<<1,p)+query(L,R,m+1,r,lc<<1|1,p))%mod;
}
int main(){
    int x,y,c,n,m,op;
	ios::sync_with_stdio(0);
	cin.tie(0);
    while (cin>>n>>m,n||m){
        build(1,n,1);
      	for (int i=1;i<=m;i++){
            cin>>op>>x>>y>>c;
			if (op!=4) update(x,y,c,1,n,1,op);
			else	cout<<query(x,y,1,n,1,c-1)<<endl;
        }
    }
}
