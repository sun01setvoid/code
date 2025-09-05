//|E|-g|V|=(U*n-c[S,T])/2
//无向图（一般）
//如果加入了边权和点权的话变化式即可
//改变g取值可以算一些新式子
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
const int INF = 1e18;
const int maxn = 110;
const int maxm = (1000 + maxn * 2) * 2 + 10;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m, S, T;
int h[maxn], e[maxm], ne[maxm], idx;
double f[maxm];
int q[maxn], d[maxn], cur[maxn];
int dg[maxn], ans, st[maxn];
struct Edge
{
    int a, b;
} edges[maxm];
//-----------------------------------------------------//
void add(int a, int b, double c1, double c2)
{
    e[idx] = b, f[idx] = c1, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = c2, ne[idx] = h[b], h[b] = idx++;
}
void init(double x)
{
    rep(i, 0, n + 1) h[i] = -1;
    idx = 0;
    rep(i, 0, m - 1)
        add(edges[i].a, edges[i].b, 1, 1);
    rep(i, 1, n)
    {
        add(S, i, m, 0);
        add(i, T, m + x * 2 - dg[i], 0);
    }
}
bool bfs()
{
    int hh = 0, tt = -1;
    rep(i, 0, n + 1) d[i] = -1;
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
double find(int u, double limit)
{
    if (u == T)
        return limit;
    double flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i] > 0)
        {
            double t = find(ver, min(f[i], limit - flow));
            if (t <= 0)
                d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}
double dinic(double x)
{
    init(x);
    double r = 0, flow;
    while (bfs())
        while ((flow = find(S, INF)) > 0)
            r += flow;
    return r;
}
void dfs(int u) // 沿着容量大于0的边走，遍历到的点就是合法方案
{               // 这样求出来的就是最小割
    st[u] = true;
    if (u != S)
        ans++;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int ver = e[i];
        if (!st[ver] && f[i] > 0)
            dfs(ver);
    }
}
void solve()
{
    cin >> n >> m;
    S = 0, T = n + 1;
    rep(i, 0, n + 1) h[i] = -1;
    idx = 0;
    rep(i, 0, m - 1)
    {
        int a, b;
        cin >> a >> b;
        dg[a]++;
        dg[b]++;
        edges[i] = {a, b};
    }
    double l = 0, r = m;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        double t = dinic(mid);
        if (m * n - t > 0) // m设为U
            l = mid;
        else
            r = mid;
    }
    dinic(l);
    dfs(S);
    if (!ans) // 因为至少要选一名员工  4 0的时候会出错，max=0
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (st[i])
            cout << i << endl;
    }
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