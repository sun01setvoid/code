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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> tmp;
    vector<pii> a(n + 1);
    int cnt = 0;
    rep(i, 1, n) cin >> a[i].fi;
    rep(i, 1, n)
    {
        cin >> a[i].se;
        cnt += abs(a[i].fi - a[i].se);
        tmp.pb({max(a[i].fi, a[i].se), n + i});
        tmp.pb({min(a[i].fi, a[i].se), i});
    }
    int mi = INF;
    sort(tmp.begin(), tmp.end());
    int sz = tmp.size();
    int num = 0;
    for (int i = 0; i <= sz - 2; i++)
    {
        if (tmp[i].se <= n)  //像这样其实考虑成区间更容易
            num++;
        else
            num--;
        if (num == 2)
        {
            mi = 0;
            break;
        }
        if (tmp[i].se > n && tmp[i + 1].se <= n)
            mi = min(mi, 2 * (tmp[i + 1].fi - tmp[i].fi));
    }
    cout << cnt + mi << endl;
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