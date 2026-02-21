#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e4 + 10;
const int maxm = 2e4 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int to, rev, cap;
};
vector<oo> g[maxn];
int level[maxn], iter[maxn];
int n, m, s, t;
void add(int from, int to, int cap)
{
    g[from].pb({to, (int)g[to].size(), cap});
    g[to].pb({from, (int)g[from].size() - 1, 0});
}
bool bfs(int s, int t)
{
    fill(level, level + 1 + n, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto &e : g[u])
        {
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}
int dfs(int u, int t, int up)
{
    if (u == t)
        return up;
    for (int &i = iter[u]; i < g[u].size(); i++)
    {
        oo &e = g[u][i];
        if (e.cap > 0 && level[u] + 1 == level[e.to])
        {
            int d = dfs(e.to, t, min(up, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int maxflow(int s, int t)
{
    int flow = 0;
    while (bfs(s, t))
    {
        fill(iter, iter + 1 + n, 0);
        int f;
        while ((f = dfs(s, t, INF)) > 0)
        {
            flow += f;
        }
    }
    return flow;
}
vii mp[maxn], stk;
int cnt;
int N, M, w[maxn], dis[maxn];
int tot;
int dfn[maxn], low[maxn], bel[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    stk.pb(u);
    for (int v : mp[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!bel[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        cnt++;
        int x;
        do
        {
            x = stk.back();
            bel[x] = cnt;
            stk.pop_back();
        } while (x != u);
    }
}
void init()
{
    for (int i = 0; i <= t; i++)
    {
        g[i].clear();
        mp[i].clear();
        dfn[i] = low[i] = bel[i] = 0;
    }
    stk.clear();
    tot = 0;
    cnt = 0;
}
void Raze()
{
    cin >> N >> M;
    s = 0;
    t = 2 * N + 1;
    init();
    n = t;
    vector<bool> has(N + 1, 0);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v + N, 1);
        has[u] = 1;
    }
    for (int i = 1; i <= N; i++)
        add(s, i, 1);
    for (int i = 1; i <= N; i++)
        add(N + i, t, 1);
    int res = maxflow(s, t);

    for (int i = 0; i <= t; i++)
    {
        for (auto it : g[i])
        {
            if (it.cap == 0)
            {
                mp[i].pb(it.to);
            }
        }
    }
    for (int i = 0; i <= t; i++)
        if (!dfn[i])
            tarjan(i);
    vector<bool> vis(n + 1);

    for (int i = 0; i <= t; i++)
        if (!dfn[i])
            tarjan(i);
    
    for (int i = 0; i <= t; i++)
    {
        for (auto it : g[i])
        {
            mp[i].pb(it.to);
        }
    }

    for (int i = 0; i <= t; i++)
        if (!dfn[i])
            tarjan(i);

    for (int u = 1; u <= N; u++)
    {

        if (bel[u] != bel[s] && has[u])
            vis[u] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        if (vis[i])
            cout << "Slavko" << endl;
        else
            cout << "Mirko" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        Raze();
    return 0;
}