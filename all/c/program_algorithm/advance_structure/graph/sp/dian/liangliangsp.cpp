//P5304 旅行者
//两两之间最短路最短，但不知道具体是那两条路之间
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pii pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
// 将物品分类，可以根据他们的二进制来分，这样的话可以保证不同
int dist[maxn];
int n, m, k;
bool st[maxn];
vector<vector<pii>> g(maxn);
void dij(vii &A)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto x : A)
        pq.push({0, x}), dist[x] = 0;
    while (pq.size())
    {
        auto [dis, u] = pq.top();
        pq.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto [v, w] : g[u])
        {
            if (!st[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
    }
    int mx = __lg(n);
    vii tmp;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        tmp.pb(x);
    }
    vii A, B;
    int ans = inf;
    for (int i = mx; i >= 0; i--)
    {
        A.clear(), B.clear();
        for (auto &x : tmp)
        {
            if (x >> i & 1)
                A.pb(x);
            else
                B.pb(x);
        }
        dij(A);
        for (auto x : B)
            ans = min(ans, dist[x]);
        dij(B);
        for (auto x : A)
            ans = min(ans, dist[x]);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}

