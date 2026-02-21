#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
//#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 4e5 + 5;
const int maxm = 1e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    
};
/*
构筑bfs序的2-SAT,方便线段树优化建图
*/
int n,fa[maxn],m,in[maxn],out[maxn];
int bfn[maxn],dfn,tot,rev[maxn];
vii g[maxn];int dep[maxn];
struct TwoSAT
{
    int vars,sz;
    vector<vii>g;vii tid;
    vii comp,order,used;
    TwoSAT(int n=0){init(n);}
    void init(int n)
    {
        vars=n;g.assign(10*n,{});
        order.clear();sz=n;
        used.clear();comp.clear();
        tid.resize(4*n);
    }
    int lit(int var,bool val)
    {
        return 2*var+(val?0:1);
    }
    int neg(int x){return x^1;}
    void add_imp(int a,int b){g[a].pb(b);}
    void add_or(int A,bool vala,int B,bool valb)
    {
        int a=lit(A,vala),b=lit(B,valb);
        add_imp(neg(a),b);add_imp(neg(b),a);
    }
    int newnode(){return vars++;}
    void build(int node,int l,int r)
    {
        tid[node]=newnode();
        if(l==r)
        {
            add_imp(lit(tid[node],1),lit(l-1,0));
            add_imp(lit(l - 1, true), lit(tid[node], false));
            return ;
        }
        int mid=(l+r)>>1;
        build(node<<1,l,mid);build(node<<1|1,mid+1,r);
        add_imp(lit(tid[node], true), lit(tid[node<<1], true));
        add_imp(lit(tid[node], true), lit(tid[node<<1|1], true));
        add_imp(lit(tid[node<<1], false), lit(tid[node], false));
        add_imp(lit(tid[node<<1|1], false), lit(tid[node], false));
    }
    void upd(int node,int l,int r,int ql,int qr,int from)
    {
        if(l>qr||r<ql)return;
        if(l>=ql&&r<=qr)
        {
            add_imp(lit(from, true), lit(tid[node], true));
            add_imp(lit(tid[node], false), lit(from, false));
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=ql)upd(node<<1,l,mid,ql,qr,from);
        if(mid<qr)upd(node<<1|1,mid+1,r,ql,qr,from);
    }
    void dfs1(int u)
    {
        used[u]=1;
        for(int v:g[u])if(!used[v])dfs1(v);
        order.pb(u);
    }
    void dfs2(int u,int cl,const vector<vii>&gr)
    {
        comp[u]=cl;
        for(int v:gr[u])if(comp[v]==-1)dfs2(v, cl, gr);
    }
    pair<bool,vii>solve()
    {
        int N = 2*vars;used.assign(N,0);
        order.clear();vector<vii>gr(N);
        for(int i=0;i<N;i++)if(!used[i])dfs1(i);
        for(int v=0;v<N;v++)
        {
            for(int to:g[v])
            {
                gr[to].pb(v);
            }
        }
        comp.assign(N,-1);
        int j=0;
        for(int i=N-1;i>=0;i--)
        {
            int v=order[i];
            if(comp[v]==-1)dfs2(v,j++,gr);
        }
        vii assign(vars,0);
        for(int i=0;i<vars;i++)
        {
            if(comp[2*i]==comp[2*i+1])return {false,{}};
            assign[i]=comp[2*i]>comp[2*i+1];
        }
        return {true,assign};
    }
}sat;
void init()
{
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    dfn=0;tot=0;
}
void dfs(int u)
{
    in[u]=++dfn;
    for(int v:g[u])
    {
        dep[v]=dep[u]+1;dfs(v);
    }
    out[u]=dfn;
}
void Raze()
{
    cin>>n;init();sat.init(n);int mx=0;
    vii cnt(n+1,0),pre(n+1,0);
    for(int i=2;i<=n;i++)
    {
        cin>>fa[i];g[fa[i]].pb(i);
    }
    cin>>m;
    queue<int>q;q.push(1);
    while(q.size())
    {
        int u=q.front();
        q.pop();bfn[u]=++tot;rev[tot]=u;
        for(int v:g[u])
        {
            q.push(v);
        }
    }
    dep[1]=1;dfs(1);sat.build(1,1,n);
    for(int i=1;i<=n;i++)cnt[dep[i]]++,mx=max(mx,dep[i]);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+cnt[i];
    for(int i=1;i<=n;i++)
    {
        for(int j:g[i])
        {
            sat.add_or(bfn[i]-1,1,bfn[j]-1,1);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        int dis=dep[x]+y;
        if(dis>mx)continue;
        int l = pre[dis-1] + 1, r = pre[dis];
        if (l > r) continue;
        int lo = l, hi = r;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (in[rev[mid]] < in[x]) lo = mid + 1;
            else hi = mid;
        }
        if (!(in[rev[lo]] >= in[x] && in[rev[lo]] <= out[x])) continue; 
        int L = lo;
        lo = l; hi = r;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) >> 1;
            if (in[rev[mid]] > out[x]) hi = mid - 1;
            else lo = mid;
        }
        if (!(in[rev[lo]] >= in[x] && in[rev[lo]] <= out[x])) continue;
        int R = lo;
        if(L<=R)
        {
            sat.upd(1,1,n,L,R,bfn[x]-1);
        }
    }
    auto it =sat.solve();
    if(!it.fi){NO;return;}
    YES;vii ans(n+1,0);
    for(int i=1;i<=n;i++)
    {
        ans[rev[i]] = it.so[i-1];
    }
    vii vec;
    for(int i=1;i<=n;i++)if(ans[i])vec.pb(i);
    cout<<vec.size()<<endl;
    for(int j:vec)cout<<j<<" ";cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}