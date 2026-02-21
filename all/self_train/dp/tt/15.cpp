// P2946 Ccow Frisbee Team S
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
const int mod = 1e8;
const ld eps = 1e-7;
//-----------------------------------------------------//

void solve()
{
    int n, f;
    cin >> n >> f;
    vector<vii> dp(n + 1, vii(f));
    vector<vii> vis(n + 1, vii(f));
    dp[0][0] = 1,
    vis[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < f; j++)
            if (vis[i - 1][j])
                dp[i][j] = dp[i - 1][j], vis[i][j] = 1;
        int tmp;
        cin >> tmp;
        for (int j = 0; j < f; j++)
        {
            if (vis[i - 1][j])
                dp[i][(j + tmp) % f] = (dp[i][(j + tmp) % f] + dp[i - 1][j]) % mod, vis[i][(j + tmp) % f] = 1;
        }
    }
    cout << (dp[n][0] - 1 + mod) % mod << endl;
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