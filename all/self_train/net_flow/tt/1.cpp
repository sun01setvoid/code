// P5192  Shoot the Bullet
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
const int maxn = 1410;
const int maxm = (maxn + 365 * 300) * 2 + 10;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m, S, T, s, t;
int h[maxn], e[maxm], f[maxm], ne[maxm], idx;
int q[maxn], d[maxn], cur[maxn], A[maxn];
//-----------------------------------------------------//
void add(int a, int b, int c, int d)
{
    e[idx] = b, f[idx] = d - c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
bool bfs()
{
    int hh = 0, tt = -1;
    rep(i, 0, n + m + 3) d[i] = -1;
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
    s = 0, t = n + m + 1, S = n + m + 2, T = n + m + 3;
    rep(i, 0, m + n + 3) h[i] = -1,A[i]=0;
    idx = 0;
    rep(i, 1, m)
    {
        int w;
        cin >> w;
        add(s, i, w, INF);
        A[s] -= w, A[i] += w;
    }
    rep(i, 1, n)
    {
        int ci, di;
        cin >> ci >> di;
        rep(j, 1, ci)
        {
            int T, l, r;
            cin >> T >> l >> r;
            add(T + 1, m + i, l, r);
            A[T + 1] -= l, A[m + i] += l;
        }
        add(m + i, t, 0, di);
    }
    int tot = 0;
    for (int i = 0; i <= n + m + 1; i++)
    {
        if (A[i] > 0)
            add(S, i, 0, A[i]), tot += A[i];
        else
            add(i, T, 0, -A[i]);
    }
    add(t, s, 0, INF);
    int ans = dinic();
    if (ans != tot)
    {
        cout << -1 << endl
             << endl;
        return;
    }
    else
    {
        int flow = f[idx - 1];
        f[idx - 1] = f[idx - 2] = 0;
        S = s, T = t;
        flow += dinic();
        cout << flow << endl
             << endl;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (cin>>n>>m)
    {
        solve();
    }
    return 0;
}