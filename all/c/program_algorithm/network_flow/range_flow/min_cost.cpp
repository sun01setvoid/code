//NOI2008 志愿者招募
//区间操作，类似于差分，【2.4】,5->2 (这么连一条流)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 50010;
const int maxm = (125010 + maxn) * 2;
const int mod = 1e9 + 7;
const double eps = 1e-7;
int n, m, S, T, s, t;
int h[maxn], e[maxm], f[maxm], l[maxm], ne[maxm], idx;
int q[maxn], d[maxn], cur[maxn], A[maxn];
//-----------------------------------------------------//
void add(int a, int b, int c, int d)
{
    e[idx] = b, f[idx] = d - c, l[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
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
int find(int u, int limit)
{
    if (u == T)
        return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
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
void solve()
{

    cin >> n >> m >> s >> t;
    S = 0, T = n + 1;
    rep(i, 0, n + 1) h[i] = -1;
    idx = 0;
    rep(i, 0, m - 1)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
        A[a] -= c, A[b] += c;
    }
    int tot = 0;
    rep(i, 1, n)
    {
        if (A[i] > 0)
            add(S, i, 0, A[i]), tot += A[i];
        else if (A[i] < 0)
            add(i, T, 0, -A[i]);
    }
    add(t, s, 0, INF);
    int ans = dinic();
    if (ans != tot)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        int flow = f[idx - 1];
        f[idx - 2] = f[idx - 1] = 0;
        S = t, T = s;
        flow -= dinic();
        cout << flow << endl;
    }
    return;
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