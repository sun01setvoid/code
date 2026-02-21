#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 6e6 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
int n, m, S, T;
int h[maxn], e[maxm], f[maxm], ne[maxm], idx;
int q[maxn], d[maxn], cur[maxn];
//-----------------------------------------------------//
void add(int a, int b, int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = c, ne[idx] = h[b], h[b] = idx++;
}
bool bfs()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= m * (n - 1) + m; i++)
        d[i] = -1;
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
        while (flow = find(S, inf))
            r += flow;
    return r;
}
int get(int i, int j)
{
    return m * (i - 1) + j;
}
void solve()
{
    memset(h, -1, sizeof h);
    idx = 0;
    cin >> n >> m;
    S = get(1, 1), T = get(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            int x;
            cin >> x;
            add(get(i, j), get(i, j + 1), x);
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            add(get(i, j), get(i + 1, j), x);
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            int x;
            cin >> x;
            add(get(i, j), get(i + 1, j + 1), x);
        }
    }
    cout << dinic() << endl;
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