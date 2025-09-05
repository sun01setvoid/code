#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uint;
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
int n, q;
vector<pii> adj[maxn + 1];      // {nei, edge_cost}
vector<int> icd[maxn + 1]; // 边 ID 列表
int color[maxn + 1];
int tw[maxn + 1];
struct Edge
{
    int u, v, c;
};
vector<Edge> E;
int T;
vector<int> hvy;
int is[maxn + 1], id[maxn + 1];
vector<unordered_map<int, int>> hvy_map;

int ans;
void paint(int v, int new_col)
{
    int old = color[v];
    if (is[v])
    {
        int hid = id[v];
        int before = tw[v] - hvy_map[hid][old];
        int after = tw[v] - hvy_map[hid][new_col];
        ans += (after - before);
    }
    else
    {
        for (auto &pr : adj[v])
        {
            int u = pr.first, c = pr.second;
            if (color[u] != old)
                ans -= c;
            if (color[u] != new_col)
                ans += c;
        }
    }
    for (int eid : icd[v])
    {
        auto &e = E[eid];
        int u = e.u ^ e.v ^ v;
        int c = e.c;
        if (is[u])
        {
            int hid = id[u];
            hvy_map[hid][old] -= c;
            hvy_map[hid][new_col] += c;
        }
    }
    color[v] = new_col;
    cout<<ans<<endl;
}
void solve()
{
    E.clear();
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        icd[i].clear();
        cin >> color[i];
        tw[i] = 0;
        is[i] = 0;
    }
    for (int i = 1, u, v, c; i < n; i++)
    {
        cin >> u >> v >> c;
        int id = E.size();
        E.push_back({u, v, c});
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        icd[u].push_back(id);
        icd[v].push_back(id);
        tw[u] += c;
        tw[v] += c;
    }
    T = max(1ll, (int)(sqrt(2.0 * n)));
    hvy.clear();
    for (int i = 1; i <= n; i++)
    {
        if ((int)adj[i].size() > T)
        {
            id[i] = hvy.size();
            hvy.push_back(i);
            is[i] = 1;
        }
    }
    int sz = hvy.size();
    hvy_map.assign(sz, unordered_map<int, int>());
    for (int h_idx = 0; h_idx < sz; h_idx++)
    {
        int h = hvy[h_idx];
        for (auto &pr : adj[h])
        {
            int u = pr.first, c = pr.second;
            hvy_map[h_idx][color[u]] += c;
        }
    }
    ans = 0;
    for (auto &e : E)
    {
        if (color[e.u] != color[e.v])
            ans += e.c;
    }
    while (q--)
    {
        int v, x;
        cin >> v >> x;
        paint(v, x);
    }
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
