#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int fac[maxn], inv_fac[maxn], dg[maxn];
int fpow(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res = res * a % p;
        }
        k >>= 1;
        a = (int)a * a % p;
    }
    return res;
}
void compute()
{
    fac[0] = 1;
    for (int i = 1; i <= maxn - 1; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv_fac[maxn - 1] = fpow(fac[maxn - 1], mod - 2, mod);
    for (int i = maxn - 2; i >= 0; i--)
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
}
pii find(int st, vector<vii> &adj)
{
    vii dist(adj.size(), -1);
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    int far = st, ma = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > ma)
                {
                    ma = dist[v];
                    far = v;
                }
            }
        }
    }
    return {far, ma};
}
vii findd(vector<vii> &adj)
{
    int u = find(1, adj).first;
    int v = find(u, adj).first;
    vii fa(adj.size(), -1);
    queue<int> q;
    q.push(u);
    fa[u] = u;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int ne : adj[cur])
        {
            if (fa[ne] == -1)
            {
                fa[ne] = cur;
                q.push(ne);
            }
        }
    }
    vector<int> zhijin;
    while (v != u)
    {
        zhijin.push_back(v);
        v = fa[v];
    }
    zhijin.push_back(u);
    return zhijin;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
        dg[i] = 0;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dg[v]++, dg[u]++;
    }
    if (m != n - 1)
    {
        cout << 0 << endl;
        return;
    }
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (dg[i] == 1)
            q.push(i);
    }
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        dg[cur]--;
        for (auto ne : adj[cur])
            dg[ne]--;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dg[i] >= 3)
        {
            cout << 0 << endl;
            return;
        }
    }
    vii zhijin = findd(adj);
    int ans = 4, sz = zhijin.size(); 
    //实际上一直查每个点的叶节点数目就行
    //这样删掉的得出的如果不是一条路径，那就错误，是的话分类讨论一下
    for (int i = 1; i <= sz - 2; i++)
    {
        int cnt = adj[zhijin[i]].size() - 2;
        int val = 0;
        if (i == 1)
            val++;
        if (i == sz - 2)
            val++;
        if (i != 1 && i != sz - 2)
            ans = ans * fac[cnt] % mod;
        else
        {
            if (val == 1)
                ans = ans * fac[cnt + 1] % mod;
            else
            {
                ans = ans * fac[cnt + 2] * inv_fac[2] % mod;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    compute();
    while (_--)
    {
        solve();
    }
    return 0;
}