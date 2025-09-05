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
const int maxn = 2e7 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int vis[maxn], mob[maxn];
int fac[maxn], inv_fac[maxn];
int n, m;
int primes[maxn];
int fpow(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res = res * a % p;
        }
        k >>= 1;
        a = (int)a * a % p;
    }
    return res;
}
int Cr(int i, int j)
{
    if (j > i || j < 0)
        return 0;
    if (i == j || j == 0)
        return 1;
    return (fac[i] * (inv_fac[j] * inv_fac[i - j] % mod)) % mod;
}
void compute(int val)
{
    fac[0] = 1;
    for (int i = 1; i <= val; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv_fac[val] = fpow(fac[val], mod - 2, mod);
    for (int i = val - 1; i >= 0; i--)
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
}
int cnt = 0;
void sieve(int val)
{
    vis[1] = 1, mob[1] = 1;
    for (int i = 2; i <= val; i++)
    {
        if (!vis[i])
            primes[cnt++] = i, mob[i] = -1;
        for (int j = 0; j < cnt && primes[j] * i <= val; j++)
        {
            int pm = primes[j];
            vis[pm * i] = 1;
            mob[pm * i] = (i % pm ? -mob[i] : 0);
            if (i % pm == 0)
                break;
        }
    }
}
void solve()
{
    cin >> n >> m;
    if (m == 1)
    {
        cout << n - 1 << endl;
        return;
    }
    sieve(n / m + 10);
    int ans = 0;
    for (int i = 2; i <= n / m; i++)
    {
        ans = ((ans - Cr(n / i, m) * mob[i]) % mod + mod) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    compute(maxn - 2);
    while (_--)
    {
        solve();
    }
    return 0;
}