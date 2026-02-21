// P1091  合唱队形
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    vii a(n + 1), pre(n + 1), suf(n + 1);
    rep(i, 1, n) cin >> a[i];
    vii q(n + 1);
    int len = 0;
    q[0] = -1e9;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = len;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (q[mid] < a[i])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        q[r + 1] = a[i];
        len = max(r + 1, len);
        pre[i] = r + 1;
    }
    q.resize(n + 1, 0);
    q[0] = -1e9;
    len = 0;
    for (int i = n; i >= 1; i--)
    {
        int l = 0, r = len;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (q[mid] < a[i])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        q[r + 1] = a[i];
        len = max(r + 1, len);
        suf[i] = r + 1;
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, i - pre[i] + n - i + 1 - suf[i]);
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