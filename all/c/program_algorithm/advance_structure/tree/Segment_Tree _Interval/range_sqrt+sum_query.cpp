#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
//要知道开方后下取整，直到1，最少多少次，将他转换成2的幂次
//k= floor(1 + log2(log2(n)))
const int maxn=100010;
int n;
vector<ll> E(maxn);
struct trlc{
    ll sum;
    int lazy;//这是向上的标记
}tr[maxn<<2];
void pushup(int lc){
    tr[lc].sum=tr[lc<<1].sum+tr[lc<<1|1].sum;
    tr[lc].lazy=tr[lc<<1].lazy && tr[lc<<1|1].lazy;
}
void build(int l,int r,int lc){//建树
	if(l==r){
		tr[lc].sum=E[l];
        tr[lc].lazy=(tr[lc].sum<=1);
		return;
	}
	int m = (l+r)>>1;
    build(l,m,lc<<1);build(m+1,r,lc<<1|1);
	pushup(lc);
}
void update(int L,int R,int l,int r,int lc){//对大的区间做延迟标记
    if (tr[lc].lazy) return;
    if (l == r) {
        tr[lc].sum = sqrt(tr[lc].sum);
        tr[lc].lazy = (tr[lc].sum <= 1);
        return;
    }
    int m=l+r>>1;
    if (L<=m) update(L,R,l,m,lc<<1);
    if (R>=m+1) update(L,R,m+1,r,lc<<1|1);
    pushup(lc);
}//保证找到的区间及其上面是最新的,因为要用到这个区间的时候只可能用到他或者他以上的
ll query(int L,int R,int l,int r,int lc){//使用区间更新下的q
    if (l>=L && R>=r)   return tr[lc].sum;
    if (r<L || l>R) return 0;
    int m=l+r>>1;
    return query(L,R,l,m,lc<<1)+query(L,R,m+1,r,lc<<1|1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,tmp,op,x,y,cnt=0;
    while (cin>>n){
        cnt++;
        cout<<"Case #"<<cnt<<":"<<endl;
        for (int i=1; i<=n; i++) {
            cin >> E[i];
        }//单点建树每次要初始化,一起建树不用初始化
        build(1, n, 1); // 新的build函数，递归构建线段树
        cin>>m;
        for (int i=1;i<=m;i++) {
            cin>>op>>x>>y;
            if (x>y)    swap(x,y);
            if (op==1){
                cout<<query(x,y,1,n,1)<<endl;
            }
            else{
                update(x,y,1,n,1);
            }
        }
        cout<<endl;
    }
}