#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
    repn(i, st, en) cerr << a[i] << ' '; \
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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e6 + 7;
const ld eps = 1e-7;
unordered_map<int, int> dist, st;
int n, m;
//-----------------------------------------------------//
int dijkstra(vector<vector<pii>> &G)
{
    dist[1*mod+0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    heap.push({0, 1, 0});
    while (heap.size())
    {
        auto [d, u, c] = heap.top();
        heap.pop();
        if (st[u*mod+c])
            continue;
        if (u == n)
        {
            return d;
        }
        st[u*mod+c] = 1;
        for (auto &i : G[u])
        {
            int x = i.fi, y = i.se;
            if (c == y)
            {
                if (dist[x*mod+y] > dist[u*mod+c])
                {
                    dist[x*mod+y] = dist[u*mod+c];
                    heap.push({dist[x*mod+y], x, y});
                }
            }
            else
            {
                if (dist[x*mod+y] > dist[u*mod+c] + 1)
                {
                    dist[x*mod+y] = dist[u*mod+c] + 1;
                    heap.push({dist[x*mod+y], x, y});
                }
            }
        }
    }
    return -1;
}
void solve()
{
    cin >> n >> m;
    vector<vector<pii>> G(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        dist[v*mod+c] = INF;
        dist[u*mod+c] = INF;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    cout << dijkstra(G) << endl;
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