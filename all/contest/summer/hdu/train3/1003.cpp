/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>
#include <map>
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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
using namespace std;
int fac[maxn], inv_fac[maxn];
int fpow(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int Cr(int i, int j)
{
    if (j == 0) return 1;
    return (fac[i] * (inv_fac[j] * inv_fac[i - j] % mod)) % mod;
}
void compute()
{
    fac[0] = 1;
    for (int i = 1; i <= maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv_fac[maxn] = fpow(fac[maxn], mod - 2, mod);
    for (int i = maxn - 1; i >= 0; i--)
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
}
int n, m,c,d;
//-----------------------------------------------------//
void solve()
{
    cin >> n >> m>>c>>d;
    int inv = fpow(c + d, mod - 2, mod);
    int a = c * inv % mod, b = d * inv % mod;
    vii powa(n + m + 2), powb(n + m + 2);
    powa[0] = 1, powb[0] = 1;
    for (int i = 1;i <= n + m + 1;i++)powa[i] = powa[i - 1] * a % mod, powb[i] = powb[i-1] * b % mod;
    if (m == 0) {
        cout << fpow(a, n + 1, mod) << endl;
    }
    else {
        int sum = 0;
        for (int i = 2;i <= n + m + 1;i += 2) {
            if (i / 2 > n+1 || i / 2 -1 > m - 1) break;
            int ci = Cr(n + 1, i / 2)*Cr(m - 1, i / 2 - 1) % mod;
            sum = (sum + ci * powa[n+m+1-i] % mod * powb[i] )% mod;
        }
        cout << sum << endl;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    compute();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
*/