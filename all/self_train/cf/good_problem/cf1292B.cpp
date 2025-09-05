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
int xg, yg, ax, ay, bx, by, xs, ys, t;
void solve()
{
    cin >> xg >> yg >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    vector<int> x(1), y(1);
    x[0] = xg, y[0] = yg;
    int limit = (1LL << 62) - 1;
    while ((limit - bx) / ax >= x.back() && (limit - by) / ay >= y.back())
    {
        x.push_back(ax * x.back() + bx);
        y.push_back(ay * y.back() + by);
    }

    int n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int length = x[j] - x[i] + y[j] - y[i];
            int dist2Left = abs(xs - x[i]) + abs(ys - y[i]);
            int dist2Right = abs(xs - x[j]) + abs(ys - y[j]);
            if (length <= t - dist2Left || length <= t - dist2Right)
                ans = max(ans, j - i + 1);
        }
    }

    cout << ans << endl;
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