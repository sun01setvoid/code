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
const int maxn = 5e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m, c, type, num;
//-----------------------------------------------------//
int a[maxn], cnt[maxn], cur[maxn];
vector<int> vc;
bool check(int k)
{
    rep(i, 0, type - 1)
    {
        cur[vc[i] % k] += cnt[vc[i]];
    }
    int sum = 0;
    rep(i, 0, type - 1)
    {
        if (cur[vc[i] % k] == num)
            sum++;
        cur[vc[i] % k] = 0;
    }
    return sum == c;
}
void solve()
{
    cin >> n >> m >> c;
    num = n / c;
    rep(i, 1, n)
    {
        cin >> a[i], cnt[a[i]]++;
    }
    rep(i, 0, m)
    {
        if (cnt[i] > 0)
           vc.pb(i);
    }
    type = vc.size();
    if (type < c)
    {
        cout << 0 << endl;
    }
    else if (type == c)
    {
        bool f = 1;
        rep(i, 0, type - 1)
        {
            if (cnt[vc[i]] != num)
            {
                f = 0;
                break;
            }
        }
        if (f)
            cout << -1 << endl;
        else
            cout << 0 << endl;
    }
    else
    {
        vii ans;
        for (int i = c; type <= (m / i + 1) * c; i++)
        {
            if (check(i))
                ans.pb(i);
        }
        cout << ans.size() <<" ";
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }
    vc.clear();
    rep(i, 0, m) cnt[i] = 0;
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