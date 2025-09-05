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
//-----------------------------------------------------//
void solve()
{
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vii vis(n + 1, 0), dist(n + 1, 0);
    vector<pii> pre(n + 1);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        if (cur == t)
            break;
        for (int i = 0; i <= cur; i++)
        {
            if (k - i > n - cur)
                continue;
            int ne = cur + k - 2 * i;
            if (ne < 0 || ne > n)
                continue;
            if (!vis[ne])
            {
                q.push(ne), pre[ne] = {cur, i}, vis[ne] = 1, dist[ne] = dist[cur] + 1;
            }
        }
    }
    if (!vis[t])
    {
        cout << -1 << endl;
        return;
    }
    cout << dist[t] << endl;
    /*
    vector<pii> path;
    int cur = t;
    while (cur != s)
    {
        path.pb(pre[cur]);
        cur = pre[cur].fi;
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i].fi << " reverse " << path[i].se << " "<<endl;
    cout << endl;
    */
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