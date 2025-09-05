#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vii> adj(maxn);
void solve()
{
    int n;
    cin >> n;
    vii a(n + 1, 0);
    vii dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> a[i], adj[a[i]].pb(i);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (adj[a[i]].size() >= a[i])
        {
            int pos = lower_bound(adj[a[i]].begin(), adj[a[i]].end(), i) - adj[a[i]].begin();
            if (pos >= a[i] - 1)
            {
                pos = pos - a[i] + 1;
                dp[i] = max(dp[adj[a[i]][pos] - 1] + a[i], dp[i]);
            }
        }
    }
    cout << dp[n] << endl;
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