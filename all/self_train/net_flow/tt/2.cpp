// P5192 Place the Robots
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
const int maxn = 5010;
const int maxm = 4 * maxn;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m, S, T;
int cnt, num;
int h[maxn], e[maxm], f[maxm], ne[maxm], idx;
int q[maxn], d[maxn], cur[maxn];
//-----------------------------------------------------//
void add(int a, int b, int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
bool bfs()
{
    int hh = 0, tt = -1;
    rep(i, S, T) d[i] = -1;
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
int mp[55][55];
int id1[55][55], id2[55][55];
// 每个点不能占用相同的列段，或者行段
// 考虑每个点占用的行段和列段
//把点转化成边，求最大匹配！！！！！！！！！！！！！！
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    for (int t = 1; t <= _; t++)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m;
        string s;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                if (s[j - 1] == 'o')
                    mp[i][j] = 0;
                else if (s[j - 1] == '*')
                    mp[i][j] = 1;
                else
                    mp[i][j] = 2;
            }
        }
        cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] == 0)
                {
                    id1[i][j] = cnt;
                }
                else if (mp[i][j] == 2)
                    cnt++;
            }
            cnt++;
        }
        int row = cnt - 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[j][i] == 0)
                {
                    id2[j][i] = cnt;
                }
                else if (mp[j][i] == 2)
                    cnt++;
            }
            cnt++;
        }
        int col = cnt - 1;
        S = 0, T = cnt;
        for (int i = 1; i <= row; i++)
        {
            add(S, i, 1);
        }
        for (int i = row + 1; i <= col; i++)
        {
            add(i, T, 1);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] == 0)
                    add(id1[i][j], id2[i][j], 1);
            }
        }
        int res = dinic();
        cout << "Case :" << t << endl
             << res << endl;
    }
    return 0;
}