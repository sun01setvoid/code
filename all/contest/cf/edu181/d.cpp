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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int MOD = 998244353;
const ld eps = 1e-7;
int fpow(int a, int k, int p = MOD)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> a(m + 1);
    int st = 1;
    rep(i, 1, n)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int qp = (q - p + MOD) % MOD;
        st = st * qp % MOD * fpow(q, MOD - 2) % MOD;
        int inv = fpow(qp, MOD - 2), val = p % MOD * inv % MOD;
        a[r].pb({l, val});
    }
    vii dp(m + 1, 0);
    dp[0] = 1;
    rep(i, 1, m)
    {
        int t = 0;
        for (auto &u : a[i])
        {
            int l = u.fi, val = u.se;
            t = (t + dp[l - 1] * val) % MOD;
        }
        dp[i] = t;
    }

    int ans = dp[m] * st % MOD;
    cout << ans << endl;
}

signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}