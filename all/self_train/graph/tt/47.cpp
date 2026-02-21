// 3275 糖果
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vector<pii>> g(maxn), ng(maxn);
int dist[maxn];
int dfn[maxn], low[maxn], ts;
int stk[maxn], top;
bool ins[maxn];
int a[maxn], id[maxn], scc_cnt;
int d[maxn], ans[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++ts;
    ins[u] = 1;
    stk[++top] = u;
    for (auto &[v, w] : g[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        int y;
        ++scc_cnt;
        do
        {
            y = stk[top--], id[y] = scc_cnt, ins[y] = 0;
        } while (y != u);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        dist[i] = -inf;
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1)
        {
            g[a].pb({b, 0});
            g[b].pb({a, 0});
        }
        else if (x == 2)
        {
            g[a].pb({b, 1});
        }
        else if (x == 3)
        {
            g[b].pb({a, 0});
        }
        else if (x == 4)
        {
            g[b].pb({a, 1});
        }
        else
            g[a].pb({b, 0});
    }
    for (int i = 1; i <= n; i++)
        g[0].pb({i, 0});
    for (int i = 0; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 0; i <= n; i++)
    {
        for (auto &[v, w] : g[i])
        {
            if (id[i] == id[v])
            {
                a[id[i]] += w;
            }
            else
            {
                ng[id[i]].pb({id[v], w});
                d[id[v]]++;
            }
        }
    }
    bool f = 1;
    for (int i = 1; i <= scc_cnt; i++)
    {
        if (a[i] > 0)
        {
            f = 0;
            cout << -1 << endl;
            return;
        }
    }
    queue<int> q;
    q.push(id[0]);
    dist[id[0]] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto &[v, w] : ng[u])
        {
            d[v]--;
            dist[v] = max(dist[v], dist[u] + w);
            if (d[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sum += dist[id[i]];
    }
    cout << sum << endl;
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