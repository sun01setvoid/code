// 原图没负环的话，在流形成的过程中不会产生负环
// 最小费用找最短路，最大费用找最长路
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5010;
const int maxm = 1e5 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, m, S, T;
int h[maxn], e[maxm], f[maxm], w[maxm], ne[maxm], idx;
int q[maxn], d[maxn], pre[maxn], incf[maxn]; // incf是流量限制，d是最小费用
bool st[maxn];
void add(int a, int b, int c, int d)
{
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
}
bool spfa()
{
    int hh = 0, tt = 1; // 注意这里是 != 所以要开到后面
    for (int i = 1; i <= n; i++)
        d[i] = INF, incf[i] = 0;
    q[0] = S, d[S] = 0, incf[S] = INF;
    while (hh != tt)
    {
        int t = q[hh++];
        if (hh == maxn)
            hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (f[i] && d[ver] > d[t] + w[i])
            {
                d[ver] = d[t] + w[i];
                pre[ver] = i; // 正向的
                incf[ver] = min(f[i], incf[t]);
                if (!st[ver])
                {
                    q[tt++] = ver;
                    if (tt == maxn)
                        tt = 0;
                    st[ver] = true;
                }
            }
        }
    }
    return incf[T] > 0;
}
void EK(int &flow, int &cost)
{
    flow = cost = 0;
    while (spfa())
    {
        int t = incf[T];
        flow += t, cost += t * d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1])
        {
            f[pre[i]] -= t;     // 正向
            f[pre[i] ^ 1] += t; // 反向
        }
    }
}
void solve()
{
    cin >> n >> m >> S >> T;
    for (int i = 1; i <= n; i++)
        h[i] = -1;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
    }
    int flow, cost;
    EK(flow, cost);
    cout << flow << " " << cost << endl;
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