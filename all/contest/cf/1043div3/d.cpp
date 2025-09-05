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
int a[15];
int cnt[15], val[15];
pii dfs(int x, int lim, int pos) //前导0的那些数同样只会出现一次
{
    if (pos == 0)
        return {0, 1};
    if (!lim)
        return {val[pos], cnt[pos]};
    int d = lim ? x / cnt[pos - 1] % 10 : 9;
    int ans = 0, num = 0;
    for (int i = 0; i <= d; i++)
    {
        pii t = dfs(x, lim && i == d, pos - 1);
        ans += t.fi + t.se * i;
        num += t.se;
    }
    return {ans, num};
}
void solve()
{
    int n;
    cin >> n;
    int pos = lower_bound(a + 1, a + 15, n) - a;
    int dif = n - a[pos - 1];
    int d = dif / pos, r = dif % pos;
    int num = cnt[pos - 1] - 1 + d;
    // cout << num << endl;
    vii tmp;
    int res = num + 1;
    while (res)
    {
        tmp.pb(res % 10);
        res /= 10;
    }
    int ans = 0;
    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < r; i++)
    {
        ans += tmp[i];
    }
    ans += dfs(num, 1, pos).fi;
    cout << ans << endl;
}
signed main()
{
    IOS;
    int st = 9;
    cnt[0] = 1;
    for (int i = 1; i <= 14; i++)
    {
        a[i] = a[i - 1] + st * i;
        cnt[i] = cnt[i - 1] * 10;
        st *= 10;
    }
    val[1] = 45;
    for (int i = 2; i <= 14; i++)
        val[i] = i * val[i - 1] / (i - 1) * 10;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}