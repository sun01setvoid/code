// P2607 骑士
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
// 基环树dp
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n;
bool st[maxn], ins[maxn], rm[maxn];
int f1[maxn][2], f2[maxn][2]; // 两次dp
int ans;
// 基环树拆环做dp
void dfs_f(int u, int ap, int f[][2]) // ap表示哪个点不能选
{
    f[u][1] = w[u];
    if (u == ap)
        f[u][1] = -INF;
    for (int i = h[u]; ~i; i = ne[i])
    {
        if (rm[i])
            continue;
        int j = e[i];
        dfs_f(j, ap, f);
        f[u][0] += max(f[j][1], f[j][0]);
        if (u != ap)
        {
            f[u][1] += f[j][0];
        }
    }
}
void dfs_c(int u)
{
    st[u] = ins[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
            dfs_c(j);
        else if (ins[j])
        {
            rm[i] = 1; // 删边
            dfs_f(j, -1, f1);
            dfs_f(j, u, f2);
            ans += max(f1[j][0], f2[j][1]); // 因为可能有多棵基环树
        }
    }
    ins[u] = 0;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        h[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        w[i] = a;
        add(b, i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            dfs_c(i);
    }
    cout << ans << endl;
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