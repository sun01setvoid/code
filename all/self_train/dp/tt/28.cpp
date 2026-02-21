//P2585 三色二叉树
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
const int maxn = 5e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, a[maxn];
vector<vii> adj(maxn);
string s;
int dfs1(int u, int pos) //直接全局变量tot（告知访问到哪个点）会方便一点
{
    a[u] = s[pos] - '0';
    int ne = pos + 1;
    for (int i = 1; i <= a[u]; i++)
    {
        adj[u].pb(ne);
        ne = dfs1(ne, ne);
    }
    return ne;
}
int dp1[maxn][3], dp2[maxn][3]; // r,g,b
void dfs2(int u)
{
    dp1[u][0] = dp1[u][2] = dp1[u][0] = dp1[u][2] = 0;
    dp1[u][1] = dp2[u][1] = 1;
    for (auto &v : adj[u])
        dfs2(v);
    if (adj[u].size() == 1)
    {
        int v = adj[u][0];
        dp1[u][0] = max(dp1[v][1], dp1[v][2]);
        dp1[u][1] = max(dp1[v][0], dp1[v][2]) + 1;
        dp1[u][2] = max(dp1[v][0], dp1[v][1]);
        dp2[u][0] = min(dp2[v][1], dp2[v][2]);
        dp2[u][1] = min(dp2[v][0], dp2[v][2]) + 1;
        dp2[u][2] = min(dp2[v][0], dp2[v][1]);
    }
    else if (adj[u].size() == 2)
    {
        int v1 = adj[u][0], v2 = adj[u][1];
        dp1[u][0] = max(dp1[v1][1] + dp1[v2][2], dp1[v1][2] + dp1[v2][1]);
        dp1[u][1] = max(dp1[v1][0] + dp1[v2][2], dp1[v1][2] + dp1[v2][0]) + 1;
        dp1[u][2] = max(dp1[v1][1] + dp1[v2][0], dp1[v1][0] + dp1[v2][1]);
        dp2[u][0] = min(dp2[v1][1] + dp2[v2][2], dp2[v1][2] + dp2[v2][1]);
        dp2[u][1] = min(dp2[v1][0] + dp2[v2][2], dp2[v1][2] + dp2[v2][0]) + 1;
        dp2[u][2] = min(dp2[v1][1] + dp2[v2][0], dp2[v1][0] + dp2[v2][1]);
    }
}
//-----------------------------------------------------//
void solve()
{
    cin >> s;
    n = s.size();
    dfs1(0, 0);
    dfs2(0);
    cout << max({dp1[0][0], dp1[0][1], dp2[0][2]}) << " ";
    cout << min({dp2[0][0], dp2[0][1], dp2[0][2]}) << endl;
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