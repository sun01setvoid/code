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
const int maxm = 5e5 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int tr[maxn];
int n;
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] += val;
    }
}
int qry(int x)
{
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}
void solve()
{
    cin >> n;
    vii ans(n + 1);
    vii a(n + 1), b(n + 1), res(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i], res[b[i]] = i;
    rep(i, 1, n) tr[i] = 0;
    for (int i = n; i >= 1; i--)
    {
        int cnt = i - 1;
        int ex = qry(res[a[i]] - 1);
        ans[a[i]] = cnt + ex;
        add(res[a[i]], 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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