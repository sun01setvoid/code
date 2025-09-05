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
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int dist[maxn], last[maxn], diam[maxn], vis[maxn], maxdis[maxn];
int n, wi;
void solve()
{
    cin >> n >> wi;
    dist[1] = 0, dist[2] = wi, last[1] = -1, last[2] = 1, diam[1] = 1, diam[2] = 1;
    // 求距离
    vis[1] = 1, vis[2] = 2;
    int st = 1, en = 2;
    int l = st, r = en;
    int cnt = 3;
    rep(i, 1, n)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int val;
            cin >> val;
            last[cnt] = en;
            dist[cnt] = dist[en] + val;
            en = cnt;
            diam[cnt] = 1;
            vis[cnt] = cnt;
            maxdis[cnt] = 0;
            r = en;
            cnt++;
        }
        else if (op == 2)
        {
            int x, val;
            cin >> x >> val;
            vis[cnt] = vis[x];
            last[cnt] = x;
            dist[cnt] = dist[x] + val;
            maxdis[vis[cnt]] = max(dist[cnt] - dist[vis[cnt]], maxdis[vis[cnt]]);
            if (maxdis[vis[cnt]] == dist[vis[cnt]])
                l = max(l, vis[cnt]);
            if (maxdis[vis[cnt]] == dist[en] - dist[vis[cnt]])
                r = min(r, vis[cnt]);
            cnt++;
        }
        else
        {
            if (r <= l)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << dist[r] - dist[l] << endl;
            }
        }
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