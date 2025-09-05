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
typedef unsigned long long ull;
ull ans = 0;
ull p[64];
int n;
vector<ull> a(55);
vector<bool> bz(55);
void insert(ull x)
{
    for (int i = 60; i >= 0; --i)
    {
        if (!((x >> i)&1))
            continue;
        if (!p[i])
        {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}
ull ask(ull x)
{
    for (int i = 60; i >= 0; i--)
    {
        if (!((x >> i)&1))
            x ^= p[i];
    }
    return x;
}
void dfs(int x, ull s)
{
    for (int i = 0; i <= 60; i++)
        p[i] = 0;
    for (int i = x; i <= n; i++)
        insert(a[i]);
    if (ask(s) <= ans)
        return;
    if (x == n + 1)
    {
        ans = max(ans, s);
        return;
    }
    if (!bz[x - 1])
        bz[x] = 1, dfs(x + 1, s ^ a[x]);
    bz[x] = 0, dfs(x + 1, s);
}
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ans = 0;
    dfs(1, 0);
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