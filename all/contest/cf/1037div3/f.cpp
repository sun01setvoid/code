#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
vector<vector<pii>> adj(maxn);
vector<map<int, int>> S(maxn);
vii color(maxn), p(maxn), pc(maxn);
int ans = 0;
void dfs(int u, int fa)
{
    p[u] = fa;
    for (auto [v, c] : adj[u])
    {
        if (v == p[u])
            continue;
        pc[v] = c;
        S[u][color[v]] += c;
        if (color[u] != color[v])
            ans += c;
        dfs(v, u);
    }
}
void solve()
{
    ans = 0;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        adj[i].clear();
        S[i].clear();
    }
    int total = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    dfs(1, 0);
    while (q--)
    {
        int v, x;
        cin >> v >> x;
        if (color[v] == x)
        {
            cout << ans << endl;
            continue;
        }
        if (v != -1)
        {
            if (color[v] != color[p[v]])
            {
                if (x == color[p[v]])
                    ans -= pc[v];
                if ((S[p[v]][color[v]] -= pc[v]) == 0)
                    S[p[v]].erase(color[v]);
                S[p[v]][x] += pc[v];
            }
            else
            {
                if ((S[p[v]][color[v]] -= pc[v]) == 0)
                    S[p[v]].erase(color[v]);
                S[p[v]][x] += pc[v];
                ans += pc[v];
            }
        }
        if (S[v].count(color[v]))
            ans += S[v][color[v]];
        if (S[v].count(x))
            ans -= S[v][x];
        color[v] = x;
        cout << ans << endl;
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