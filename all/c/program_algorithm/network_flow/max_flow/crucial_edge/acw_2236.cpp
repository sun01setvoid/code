#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 510;
const int maxm = 10010;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m, S, T;
int h[maxn], e[maxm], f[maxm], ne[maxm], idx;
// f表示这条边在残余网络中最多能流多少
int q[maxn], d[maxn], cur[maxn];
bool vis_s[maxn],vis_t[maxn];
// d表示分层图的层数,cur表示当前所使用的边，当前弧优化
//-----------------------------------------------------//
void add(int a, int b, int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
bool bfs()
{
    int hh = 0, tt = -1;
    rep(i,0,n-1) d[i]=-1;
    q[++tt] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T)
                    return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}
int find(int u,int limit){
    if (u==T) return limit;
    int flow=0;
    for (int i=cur[u];~i && flow<limit;i=ne[i]){
        cur[u]=i;   // 当前弧优化
        int ver=e[i];
        if (d[ver]==d[u]+1 && f[i]){
            int t=find(ver,min(f[i],limit-flow));
            if (!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}
int dinic()
{
    int r=0,flow;
    while (bfs()) while (flow=find(S,INF)) r+=flow;
    return r; 
}
void  dfs(int u,bool st[],int t){
    st[u]=true;
    for (int i=h[u];~i;i=ne[i]){
        int j=i^t,ver=e[i];
        if (f[j] && !st[ver])
            dfs(ver,st,t);
    }
}
void solve()
{
    cin>>n>>m;
    rep(i,0,n-1) h[i]=-1;
    S=0,T=n-1;
    idx=0;
    rep(i,0,m-1){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dinic();
    dfs(S,vis_s,0); //S能到达的点
    dfs(T,vis_t,1); //V能到达的点
    int res=0;
    for (int i=0;i<m*2;i+=2){
        if (!f[i] && vis_s[e[i^1]] && vis_t[e[i]]) //且满流
            res++;
    }
    cout<<res<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}