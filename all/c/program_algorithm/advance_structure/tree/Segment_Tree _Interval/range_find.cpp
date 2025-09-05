//gcd,max,sum
//线段树是求直接区间和（2logN)，而不用先求前缀和了，也就不用考虑i=0的情况
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=50010;
int n;
struct SegTreeNode{
    int sum;
    int lazy;
}SegTree[maxn<<2];
void pushup(int lc){
    SegTree[lc].sum=SegTree[lc<<1].sum+SegTree[lc<<1|1].sum;
}
void sUpdate(int L,int V,int l,int r,int lc){//L是区间
    if (l==r){
        SegTree[lc].sum+=V;
        return;
    }
    int mid=l+r>>1;
    if (L<=mid) sUpdate(L,V,l,mid,lc<<1);
    else sUpdate(L,V,mid+1,r,lc<<1|1);
    pushup(lc);
}//单点更新,二分查找;
int sQuery(int L,int R,int l,int r,int lc){
    if (r<L || l>R) return 0;//这行？对应注释中的return ......;
    if ( l>=L && r<=R)  return SegTree[lc].sum;//这一步是真正的组合，就是找被包含的区间；dfs形式二分搜索
    int mid=l+r>>1;
    int ans=0;
    if (L<=mid) ans+=sQuery(L,R,l,mid,lc<<1);//有重叠就要找
    if (R>=mid+1) ans+=sQuery(L,R,mid+1,r,lc<<1|1);//注意优先级
    return ans;
    //return sQuery(L,R,l,mid,lc<<1)+sQuery(L,R,mid+1,lc<<1|1);可取代后四行；
}
int main(){
    int a,b,suml,sumr,t,temp;
    string s;
    cin>>t;
    for (int j=0;j<t;j++){
        cin>>n;
        memset(SegTree,0,sizeof SegTree);
        for (int i=1;i<=n;i++){
            cin>>temp;
            sUpdate(i,temp,1,n,1);//建树      
        }
        while (cin>>s){
            if (s=="End")   {cout<<endl;break;}
            else {
                cin>>a>>b;
                if(s=="Add"){
                  sUpdate(a,b,1,n,1);      
                }
                else if (s=="Sub"){
                    sUpdate(a,-b,1,n,1);
                }
                else{
                    cout<<sQuery(a,b,1,n,1)<<endl;        
                }
            }
        }
    }
}
/*
一.用a[i]来构建segtree;
void pushup(int lc){
    SegTree[lc].sum=SegTree[lc<<1].sum+SegTree[lc<<1+1].sum;
}
void bulid (int l,int r,int lc){
    if (l==r){
        SegTree[lc].sum=A[l];
        return;
    }//叶子节点
    int mid=l+r>>1;
    build(l,mid,lc<<1);build(mid+1,r,lc<<1+1);
    pushup(lc);//非叶子节点
}//就是用单点更新
*/
