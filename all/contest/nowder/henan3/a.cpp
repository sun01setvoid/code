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
int n, l;
//-----------------------------------------------------//
bool check(double x, vector<int> &a)
{
    vector<double> pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i] - x;//先减一遍mid,这样取多少就会减多少
    double mi = 0;
    for (int i = l; i <= n; i++)
    {
        mi = min(pre[i - l], mi);
        if (pre[i] >= mi)
            return true;
    }
    return false;
}
void solve()
{
    cin >> n >> l;
    vii a(n + 1);
    rep(i, 1, n) cin >> a[i];
    cout << fixed << setprecision(5);
    double L = -1e4, R = 1e4;
    while (R - L > eps)
    {
        double mid = (L + R) / 2;
        if (check(mid, a))
        {
            L = mid;
        }
        else
            R = mid;
    }
    cout << (L + R) / 2 << endl;
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