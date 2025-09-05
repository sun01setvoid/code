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
const int maxn = 20;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
vector<pii> a(maxn);
int fac[maxn];
int cnt;
//-----------------------------------------------------//
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int ts = 0;
    for (int i = cnt; i >= 0; i--)
    {
        ts += n / fac[i] % 3;
    }
    if (k < ts)
    {
        cout << -1 << endl;
        return;
    }
    int r = 0;
    for (int i = cnt; i >= 0; i--)
    {
        int val = r + n / fac[i] % 3;
        if (i == 0)
        {
            ans += val * a[i].se;
            continue;
        }
        int num = min((k - ts) / 2, val);
        r = num * 3;
        ts += num * 2;
        ans += (val - num) * a[i].se;
        //cout << i << " " << val << " " << num << endl;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    int st = -1;
    for (int i = 1, j = 0; i <= 1e9; i = i * 3, j++)
    {
        cnt = j;
        a[j].fi = i;
        a[j].se = 3 * i + j * st;
        st = i;
    }
    fac[0] = 1;
    for (int i = 1; i <= cnt; i++)
    {
        fac[i] = fac[i - 1] * 3;
    }
    while (_--)
    {
        solve();
    }
    return 0;
}