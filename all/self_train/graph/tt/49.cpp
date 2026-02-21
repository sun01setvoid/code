//倍杀测量者
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define pb push_back
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
double dist[maxn];
bool st[maxn];
struct node
{
    int v;
    double w;
};
vector<vector<node>> g(maxn);
int c[maxn];
int to[maxn];
vector<array<int, 4>> ed;
int n, s, t;
void init(double mid)
{
    for (int i = 0; i <= n; i++)
        g[i].clear();
    for (int i = 0; i <= n + 1; i++)
        dist[i] = -inf, to[i] = 0, st[i] = 0;
    for (int i = 1; i <= n; i++)
        if (c[i])
            g[0].pb({i, log(c[i])}), g[i].pb({0, -log(c[i])});
    for (auto &[o, a, b, k] : ed)
    {
        if (o == 1)
        {
            g[b].pb({a, (double)log(k - mid)});
        }
        else
            g[b].pb({a, -log(k + mid)});
    }
}
bool spfa()
{
    dist[n + 1] = 0.;
    queue<int> q;
    q.push(n + 1);
    st[n + 1] = 1;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        st[u] = 0;
        for (auto &[v, w] : g[u])
        {
            if (dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
                to[v] = to[u] + 1;
                if (to[v] >= n + 1)
                    return 1;
                if (!st[v])
                    q.push(v), st[v] = 1;
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> s >> t;
    int mx = 0;
    for (int i = 1; i <= s; i++)
    {
        int o, a, b, k;
        cin >> o >> a >> b >> k;
        mx = max(k, mx);
        ed.pb({o, a, b, k});
    }
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        c[a] = b;
    }
    for (int i = 0; i <= n; i++)
        g[n + 1].pb({i, 0});
    double l = 0. + eps, r = (double)mx - eps;
    double ans = -1;
    while ((r - l) > eps)
    {
        double mid = (l + r) / 2;
        init(mid);
        bool f = spfa();
        if (f)
            l = (ans = mid);
        else
            r = mid;
    }
    if (ans < 0)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(8) << ans << endl;
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