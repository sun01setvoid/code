#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
struct node{
    int xl,yl,xr,yr;
    bool operator < (const node &a) const{
        return yl<a.yl;
    }
};
int n;
struct trnode{
    int hi;
    int lazy;
}tr[maxn<<2];
void pushdown(int lc,int ll,int rl){
    if (!tr[lc].lazy) return;
    tr[lc<<1].hi=max(tr[lc<<1].hi,tr[lc].hi);
    tr[lc<<1|1].hi=max(tr[lc<<1|1].hi,tr[lc].hi);
    tr[lc<<1].lazy=max(tr[lc<<1].lazy,tr[lc].lazy);
    tr[lc<<1|1].lazy=max(tr[lc<<1|1].lazy,tr[lc].lazy);
    tr[lc].lazy=0;
}
void pushup(int lc){
    tr[lc].hi=max(tr[lc<<1].hi,tr[lc<<1|1].hi);
}
void build(int lc,int l,int r){
	if(l==r){
        tr[lc].hi=0;
        tr[lc].lazy=0;
		return;
	}
	int m = (l+r)>>1;
    build(lc<<1,l,m);build(lc<<1|1,m+1,r);
	pushup(lc);
}
void update(int L,int R,int V,int lc,int l,int r){
    if (l>=L && r<=R){
        tr[lc].hi=max(tr[lc].hi,V);
        tr[lc].lazy=max(tr[lc].lazy,V);
        return;
    }
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    if (L<=m) update(L,R,V,lc<<1,l,m);
    if (R>=m+1) update(L,R,V,lc<<1|1,m+1,r);
    pushup(lc);
}
int query(int L,int R,int lc,int l,int r){
    if (l>=L && R>=r)   return tr[lc].hi;
    if (r<L || l>R) return 0;
    int m=l+r>>1;
    pushdown(lc,m-l+1,r-m);
    return max(query(L,R,lc<<1,l,m),query(L,R,lc<<1|1,m+1,r));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        int ma=1;
        vector <node> a;
        while (n--){
            int xl,yl,xr,yr;
            cin>>xl>>yl>>xr>>yr;
            ++xl,++xr,--xr;
            ma=max(ma,xr);
            a.push_back({xl,yl,xr,yr});
        }
        sort(a.begin(),a.end());
        build(1,1,ma);
        int ans=0;
        for (int i=0;i<a.size();i++){
            int xl=a[i].xl,yl=a[i].yl,xr=a[i].xr,yr=a[i].yr;
            //cout<<xl<<" "<<yl<<" "<<xr<<" "<<yr<<"\n";
            int xma=query(xl,xr,1,1,ma);
            ans+=(xr-xl+1)*(yr-yl)*(yl-xma);
            //cout<<xma<<" "<<ans<<"\n";
            update(xl,xr,xma+yr-yl,1,1,ma);
        }
        cout<<ans<<"\n";
    }
}