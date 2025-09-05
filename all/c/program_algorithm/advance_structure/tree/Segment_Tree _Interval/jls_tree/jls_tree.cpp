//lg 6242
//将Ai加上k会增加的标签数量为logn
//代价为logn,势能增加为最多（mlognlogn）
//分开max增量和其他值增量
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define LOWEST -2020
typedef  long long LL;
const int maxn=500010;
struct trnode{
    LL sum,ma,num,se;//将区间最值和更新和结合起来,num记录最大值个数
    //要知道更新后的最大值,节点的se值也要知道,每次只更新ma
    //ma可做懒标记
}tr[maxn<<2];
LL ls(LL lc){return lc<<1;}
LL rs(LL lc){return lc<<1|1;}
void pushup(int lc){
    trnode &p=tr[lc],&l=tr[ls(lc)],&r=tr[rs(lc)];
    p.sum=l.sum+r.sum;
    p.ma=max(l.ma,r.ma);
    if (l.ma==r.ma){
        p.se=max(l.se,r.se);
        p.num=l.num+r.num;
    }
    else {
        p.se=max(min(l.ma,r.ma),max(l.se,r.se));
        p.num=l.ma>r.ma?l.num:r.num;
    }
}
void lazy(int lc,int x){  //只有situation1,situation2才会处理
    trnode &p=tr[lc];
    if (x>=p.ma)   return;
    p.sum-=p.num*(p.ma-x);
    p.ma=x;//p.num并没有变，只是p.ma的值变成了x
}
void pushdown(int lc){//下推确保子节点准确
    trnode &p =tr[lc];
    lazy(ls(lc),p.ma);
    lazy(rs(lc),p.ma);
    //不会颠覆孩子的次大值，因为孩子次大值不超过父亲的次大值，如果懒标记，那么下推不可能更改孩子se
}
void build(int lc,int l,int r){//建树
    trnode &p=tr[lc];
	if (l==r){
        cin>>p.sum;
        p.ma=p.sum;p.se=LOWEST;p.num=1;
        return ;
    }
    int m=l+r>>1;
    build (ls(lc),l,m);build(rs(lc),m+1,r);
    pushup(lc);
}
void update(int L,int R,int V,int lc,int l,int r){//对大的区间做延迟标记
    trnode & p=tr[lc];
    if (V>=p.ma)    return ;//situation1
    if (L<=l && r<=R && p.se<V) {lazy(lc,V);return;}  //situation2,更改时的条件，也是pushdown,和pushup需要注意的，懒住，剪枝
    pushdown(lc);
    //if (r<L || l>R) return ;//与二分后区间是否要选取区间对应
    int m=l+r>>1;
    if (L<=m) update(L,R,V,lc<<1,l,m);
    if (R>=m+1) update(L,R,V,lc<<1|1,m+1,r);
    pushup(lc);
}//保证找到的区间及其上面是最新的,因为要用到这个区间的时候只可能用到他或者他以上的
LL querySum(int L,int R,int lc,int l,int r){//使用区间更新下的q
    if (l>=L && R>=r)   return tr[lc].sum;
    if (r<L || l>R) return 0;
    pushdown(lc);
    int m=l+r>>1;
    return querySum(L,R,ls(lc),l,m)+querySum(L,R,rs(lc),m+1,r);
}
LL queryMax(int L,int R,int lc,int l,int r){//使用区间更新下的q
    if (l>=L && R>=r)   return tr[lc].ma;
    if (r<L || l>R) return 0;
    pushdown(lc);
    int m=l+r>>1;
    return max(queryMax(L,R,ls(lc),l,m),queryMax(L,R,rs(lc),m+1,r));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        build (1,1,n);
        while (m--){
            int q,l,r,x;
            cin>>q>>l>>r;
            if(q==0)    cin>>x,update(l,r,x,1,1,n);
            else if (q==1)  cout<<queryMax(l,r,1,1,n)<<endl;
            else    cout<<querySum(l,r,1,1,n)<<endl;
        }
    }
}
