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
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a[maxn], b[maxn], c[maxn];
int n;
int calc(int x, int y)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(a[i] - x) + abs(b[i] - y) + abs(x + y - a[i] - b[i]);
    }
    return ans;
}
int findy(int x)
{
    vii tmp(2 * n + 1);
    for (int i = 1; i <= n; i++)
        tmp[i] = b[i], tmp[n + i] = a[i] + b[i] - x;
    nth_element(tmp.begin() + 1, tmp.begin() + n, tmp.end());
    return calc(x, tmp[n]);
}
int ts()
{
    int lx = -1e9, rx = 1e9;
    int ans = INF;
    while (lx <= rx)
    {
        int mid1 = lx + (rx - lx) / 3;
        int mid2 = rx - (rx - lx) / 3;
        int res1 = findy(mid1), res2 = findy(mid2);
        ans = min({ans, res1, res2});
        if (res1 > res2)
        {
            lx = mid1 + 1;
        }
        else
        {
            rx = mid2 - 1;
        }
    }
    return ans;
}
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i] >> b[i] >> c[i];
    int ans = ts();
    cout << ans / 2 << endl;
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
/*
sort(a + 1, a + n + 1);
sort(b + 1, b + n + 1);
sort(c + 1, c + n + 1);
int mid = (n + 1) / 2;
int ans = 0;
for (int i = 1; i <= n; i++)
{
    ans += abs(a[i] - a[mid]) + abs(b[i] - b[mid]) + abs(c[i] - c[mid]);
}
cout << ans / 2 << endl;
*/
// 主要还是从c[i]被a[i]和b[i]限制住了，所以不能直接找中位数