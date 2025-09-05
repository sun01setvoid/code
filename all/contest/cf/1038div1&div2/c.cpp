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
    int n;
    cin >> n;
    vector<pair<pii, int>> points(n); 
    int xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        points[i] = {{x, y}, i + 1}; 
        xmin = min(xmin, x);
        xmax = max(xmax, x);
        ymin = min(ymin, y);
        ymax = max(ymax, y);
    }
    vector<pair<int, int>> res(n); 
    for (int i = 0; i < n; ++i)
    {
        int x = points[i].first.first;
        int y = points[i].first.second;
        int dx = max(abs(x - xmin), abs(x - xmax));
        int dy = max(abs(y - ymin), abs(y - ymax));
        res[i] = {max(dx, dy), i}; 
    }
    sort(res.rbegin(), res.rend());

    vector<int> tmp;
    for (auto [g, idx] : res)
        tmp.push_back(points[idx].second);

    for (int i = 0; i < n / 2; ++i)
    {
        int a = tmp[i];
        int b = tmp[n - 1 - i];
        cout << a << " " << b << '\n';
    }
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