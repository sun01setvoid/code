#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
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
int ansl, ansr;
int n,k;
bool check(int x, vector<int> &a)
{
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + (a[i] >= x ? 1 : -1);
    int pos = 0, mi = 0;
    for (int i = k; i <= n; i++)
    {
        if (pre[i - k] < mi)
        {
            mi = pre[i - k];
            pos = i - k;
        }
        if (pre[i] - mi >= 0)
        {
            ansl = pos + 1,ansr=i;
            return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, a))l = mid + 1;
        else    r = mid - 1;
    }
    cout << r << ' ' << ansl << ' ' << ansr << '\n';
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