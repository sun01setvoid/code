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
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    vii prea(n + 1), preb(n + 1);
    vii pre1(n + 1), pre2(n + 1), d(n + 1);
    vector<pii> c(n + 1);
    string s1, s2;
    cin >> s1 >> s2;
    rep(i, 1, n) prea[i] = prea[i - 1] + (s1[i - 1] == '1');
    rep(i, 1, n) preb[i] = preb[i - 1] + (s2[i - 1] == '1');
    rep(i, 1, n)
    {
        c[i].fi = i - preb[i] - preb[i];
        c[i].se = i - preb[i];
    }
    sort(c.begin() + 1, c.begin() + n + 1);
    rep(i, 1, n) d[i] = c[i].fi;
    rep(i, 1, n)
    {
        pre1[i] = pre1[i - 1] + c[i].se;           // 变1
        pre2[i] = pre2[i - 1] + c[i].se - c[i].fi; // 变0
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = i - prea[i] - prea[i];
        int it = lower_bound(d.begin() + 1, d.begin() + n + 1, -t) - d.begin();
        if (it == n + 1)
        {
            ans += n * (i - prea[i]) + pre1[n];
        }
        else
            ans += (it - 1) * (i - prea[i]) + pre1[it - 1] + (n - it + 1) * (prea[i]) + pre2[n] - pre2[it - 1];
    }
    cout << ans << endl;
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