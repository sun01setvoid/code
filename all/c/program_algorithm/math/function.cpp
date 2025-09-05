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
struct Mint
{
    int val;
    static const int MOD = 1e9 + 7;
    Mint(int x = 0) : val(x % MOD) {}
    Mint operator+(Mint b) const { return val + b.val; }
    Mint operator-(Mint b) const { return val - b.val + MOD; }
    Mint operator*(Mint b) const { return 1LL * val * b.val; }
    Mint operator/(Mint b) const { return *this * b.inv(); }
    Mint inv() const { return fpow((*this).val, MOD - 2, MOD); }
    friend ostream &operator<<(ostream &os, Mint x) { return os << x.val; }
};
int fac[maxn], inv_fac[maxn];
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
    if (j == 0)
        return 1;
    return (fac[i] * (inv_fac[j] * inv_fac[i - j] % mod)) % mod;
}
void compute()
{
    fac[0] = 1;
    for (int i = 1; i <= maxn - 1; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv_fac[maxn - 1] = fpow(fac[maxn - 1], mod - 2, mod);
    for (int i = maxn - 2; i >= 0; i--)
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
    // inv[1]=1;  for (int i=2;i<=n;i++)    inv[i]=(mod-mod/i*inv[mod%i])%mod;     //不用正负吗
    /* 组合数递推
    for (int i=0;i<M;i++){
        for (int j=0;j<=i;j++){
            if (!j) C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    */
}