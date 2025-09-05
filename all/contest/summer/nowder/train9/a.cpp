#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n,p[maxn];pii t[maxn<<2];
int fp(int a,int b){
    int res=1;
    while(b){
        if(b%2)res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
int f[2*maxn],inv[2*maxn];
void init(){
    f[0]=1;
    for(int i=1;i<=2*maxn-1;i++)f[i]=f[i-1]*i%mod;
    inv[2*maxn-1]=fp(f[2*maxn-1],mod-2);
    for(int i=2*maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int a,int b){
    if(b==0)return 1;
    return f[a]*inv[b]%mod*inv[a-b]%mod;
}
void build(int node,int l,int r)
{
    t[node]={INF,-1};if(l==r){t[node]={p[l],l};return ;}int mid=(l+r)>>1;
    build(node<<1,l,mid);build(node<<1|1,mid+1,r);
    auto p1=t[node<<1],p2=t[node<<1|1];
    if(p1.fi<p2.fi)
    {
        t[node]=p1;
    }
    else 
    {
        t[node]=p2;
    }
}
pii q(int node,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr)return t[node];int mid=(l+r)>>1;pii ans={INF,-1};
    if(mid>=ql)
    {
        auto it =q(node<<1,l,mid,ql,qr);
        if(it.fi<ans.fi)ans=it;
    }
    if(mid<qr)
    {
        auto it =q(node<<1|1,mid+1,r,ql,qr);
        if(it.fi<ans.fi)ans=it;
    }
    return ans;
}
int ans;
int get(int cnt,int p){
    return C(cnt+p,p);
}
void dfs(int l,int r,int mid,int cnt){
    if(l>r)return;
    if(l<=mid-1){
        pii t1=q(1,1,n,l,mid-1);
        ans=(ans+get(cnt+1,mid-l-1))%mod;
        dfs(l,mid-1,t1.se,cnt+1);
    }
    if(mid+1<=r){
        pii t2=q(1,1,n,mid+1,r);
        ans=(ans+get(cnt+1,r-mid-1))%mod;
        dfs(mid+1,r,t2.se,cnt+1);
    }
}
void solve()
{
    cin>>n;ans=n+1;
    for(int i=1;i<=n;i++)cin>>p[i];
    build(1,1,n);
    pii now=q(1,1,n,1,n);
    dfs(1,n,now.se,1);
    cout<<ans<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    init();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}