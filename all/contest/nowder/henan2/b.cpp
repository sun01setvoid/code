#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn = 100;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int fac[maxn];
//-----------------------------------------------------//
int fpow(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int count(int k, int x)
{
    return ((x + 1)/fac[k+1]) * fac[k] + max(0ll, (x + 1) % fac[k+1] - fac[k]);  //要除一个东西的话要用他的逆元，不要随便mod
}
void solve()
{
    int l, r, y;
    cin >> l >> r >> y;
    int inv = fpow(r - l + 1, mod - 2, mod);
    int ans = 0;
    for (int i = 0; i < 31; i++)
    {
        int cnt = count(i, r) - count(i, l - 1);
        if (y >> i & 1)
            ans = (ans + (r - l + 1 - cnt) * inv % mod) % mod;
        else
            ans = (ans + cnt * inv % mod) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    fac[0] = 1;
    for (int i = 1; i <= 31; i++)
        fac[i] = fac[i - 1] * 2;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}