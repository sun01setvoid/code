// 正反走两次，算没走，所以可以直接建边
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
const int maxn = 410;
const int maxm = 8e4+10;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m, k, S, T;
int h[maxn], e[maxm], f[maxm], ne[maxm],w[maxm],idx;
// f表示这条边在残余网络中最多能流多少
int q[maxn], d[maxn], cur[maxn];
// d表示分层图的层数,cur表示当前所使用的边，当前弧优化
//-----------------------------------------------------//
void add(int a, int b,int c)
{
    e[idx] = b,w[idx]=c, ne[idx] = h[a], h[a] = idx++; //实际是由四条边合并成两条边
    e[idx] = a,w[idx]=c,ne[idx] = h[b], h[b] = idx++;//正向边反向边都走了的话，其实相当于没走
}
bool bfs()
{
    int hh = 0, tt = -1;
    rep(i, 0, n) d[i] = -1;
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
int find(int u, int limit)
{
    if (u == T)
        return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i; // 当前弧优化
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = find(ver, min(f[i], limit - flow));
            if (!t)
                d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}
int dinic()
{
    int r = 0, flow;
    while (bfs())
        while (flow = find(S, INF))
            r += flow;
    return r;
}
bool check(int mid){
    for (int i=0;i<idx;i++)
        if (w[i]>mid) f[i]=0;
        else f[i]=1;
    return dinic()>=k;
}
void solve()
{
    cin >> n >> m >> k;
    S=1,T=n;
    rep(i, 0, n) h[i] = -1;
    idx = 0;
    rep(i, 0, m - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b,c);
    }
    int l=1,r=1e6;
    while (l<=r){
        int mid=l+r>>1;
        if (check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}