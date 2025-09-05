#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
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
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vii a(n + 1), vis(n + 1, -1);
    // vii st(n+1,0);
    vector<vii> kit(k);
    vector<vector<pii>> G(n + 1);
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pq[n + 1];
    rep(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == 0)
            q.push(i);
    }
    for (int i = 0; i < k; i++)
    {
        int t, scj;
        cin >> t >> scj;
        kit[i].pb(t);
        while (scj--)
        {
            int tmp;
            cin >> tmp;
            kit[i].pb(tmp);
        }
    }
    sort(kit.begin(), kit.end());
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb({b, c});
    }
    int cur = 0, kit_cur = 0, cnt = 0;
    bool flag = 1;
    while (q.size() || kit_cur < k || flag)
    {
        flag = 0;
        if (q.size())
        {
            flag = 1;
            int u = q.front();
            q.pop();
            // st[u]=0;
            ++cnt;
            vis[u] = cur;
            for (auto &i : G[u])
            {
                int v = i.first, w = i.second;
                if (a[v] > 0)
                {
                    pq[v].push(cur + w);
                    // if (!st[v]) q.push(v),st[v]=1;
                }
            }
            continue;
        }
        if (kit_cur < k)
        {
            flag = 1;
            bool f = 0;
            for (int i = 1; i < kit[kit_cur].size(); i++)
            {
                if (a[kit[kit_cur][i]] > 0)
                {
                    while (pq[kit[kit_cur][i]].size())
                    {
                        int t = pq[kit[kit_cur][i]].top();
                        pq[kit[kit_cur][i]].pop();
                        if (t <= cur)
                            --a[kit[kit_cur][i]];
                        if (a[kit[kit_cur][i]] <= 0)
                        {
                            f = 1;
                            q.push(kit[kit_cur][i]);
                            vis[kit[kit_cur][i]] = t;
                            break;
                        }
                    }
                }
            }
            if (f)
                continue;
            cur = kit[kit_cur][0];
            for (int i = 1; i < kit[kit_cur].size(); i++)
            {
                if (a[kit[kit_cur][i]] <= 0)
                    continue;
                a[kit[kit_cur][i]] = 0;
                vis[kit[kit_cur][i]] = cur;
                q.push(kit[kit_cur][i]);
            }
            ++kit_cur;
            continue;
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                while (pq[i].size())
                {
                    int t = pq[i].top();
                    pq[i].pop();
                    --a[i];
                    if (a[i] <= 0)
                    {
                        flag=1;
                        q.push(i);
                        vis[i] = t;
                        break;
                    }
                }
            }
        }
        */
    }
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
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