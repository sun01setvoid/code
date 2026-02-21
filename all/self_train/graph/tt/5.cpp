// P2811 Protect the school
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a[maxn];
int n, m;
int dfn[maxn], low[maxn], ts;
int stk[maxn], top;
bool ins[maxn];
int id[maxn], scc_cnt;
vector<vii> adj(maxn), nadj(maxn);
int w[maxn], cnt[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++ts;
    stk[++top] = u, ins[u] = 1;
    for (auto v : adj[u])
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
            if (a[y] < w[scc_cnt])
            {
                w[scc_cnt] = a[y], cnt[scc_cnt] = 1;
            }
            else if (a[y] == w[scc_cnt])
                cnt[scc_cnt]++;
        } while (y != u);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], w[i] = inf;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    int ans1 = 0, ans2 = 1;
    for (int i = 1; i <= scc_cnt; i++)
    {
        ans1 += w[i], ans2 *= cnt[i];
    }
    cout << ans1 << " " << ans2;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}