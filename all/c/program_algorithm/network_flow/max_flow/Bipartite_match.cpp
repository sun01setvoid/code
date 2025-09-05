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
const int maxn = 110;
const int maxm = 5210;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n,m,S,T;
int h[maxn],e[maxm],f[maxm],ne[maxm],idx;
int q[maxn],d[maxn],cur[maxn];
void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}
bool bfs(){
    int hh=0,tt=-1;
    rep(i,0,n+1) d[i]=-1;
    q[++tt]=S,d[S]=0,cur[S]=h[S];
    while (hh<=tt){
        int t=q[hh++];
        for (int i=h[t];~i;i=ne[i]){
            int ver=e[i];
            if (d[ver]==-1 && f[i]){
                d[ver]=d[t]+1;
                cur[ver]=h[ver];
                if (ver==T) return true;
                q[++tt]=ver;
            }
        }
    }
    return false;
}
int find(int u,int limit){
    if (u==T) return limit;
    int flow=0;
    for (int i=cur[u];~i && flow<limit;i=ne[i]){
        cur[u]=i;
        int ver=e[i];
        if (d[ver]==d[u]+1 && f[i]){
            int t=find(ver,min(f[i],limit-flow));
            if (!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}
int dinic(){
    int r=0,flow;
    while (bfs()) while (flow=find(S,INF)) r+=flow;
    return r;
}
void solve()
{
    cin>>m>>n;
    S=0,T=n+1;
    rep(i,0,n+1) h[i]=-1;
    idx=0;
    rep(i,1,m) add(S,i,1);
    rep(i,m+1,n) add(i,T,1);
    int a,b;
    while (cin>>a>>b,a!=-1) add(a,b,1);
    cout<<dinic()<<endl;
    for (int i=0;i<idx;i+=2){
        if (e[i]>m && e[i]<=n && !f[i]) cout<<e[i^1]<<" "<<e[i]<<endl;
    }
    return ;
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