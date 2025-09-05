#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
// #define int long long
#define ld long double
// #define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e3 + 5;
// const int mod = 998244353;
const ld eps = 1e-7;
#define all(x) x.begin(), x.end()
using ull = unsigned long long;
using namespace std;
using ll = long long;
using poly = vector<ll>;
const int mod = 998244353;
const int Mod = mod - 1;
ll mpow(ll x, int y = mod - 2)
{
    ll ans = 1;
    while (y)
        y & 1 && (ans = ans * x % mod), y >>= 1, x = x * x % mod;
    return ans;
}
namespace Poly
{
    const int N = 1 << 21, g = 3;
    int tr[N], k, a[N], b[N];
    ll pw[N];
    void init(int n)
    {
        for (k = 2; k <= n; k <<= 1)
            ;
        for (int i = 0; i < k; i++)
            tr[i] = (tr[i >> 1] >> 1) | (i & 1 ? k / 2 : 0);
        pw[k / 2] = 1;
        pw[k / 2 + 1] = mpow(g, (mod - 1) / k);
        for (int i = k / 2 + 2; i < k; i++)
            pw[i] = pw[i - 1] * pw[k / 2 + 1] % mod;
        for (int i = k / 2 - 1; i; i--)
            pw[i] = pw[i << 1];
    }
    void ntt(int *A, int k, int flag)
    {
        static ull a[N];
        for (int i = 0; i < k; i++)
            a[tr[i]] = A[i];
        for (int i = 2; i <= k; i <<= 1)
        {
            ll *e = pw + i / 2;
            for (int j = 0; j < k; j += i)
            {
                for (int h = j; h < j + i / 2; h++)
                {
                    int x = a[h + i / 2] * e[h - j] % mod;
                    a[h + i / 2] = a[h] + mod - x;
                    a[h] += x;
                }
            }
            if (i == (1 << 18))
            {
                for (int j = 0; j < k; j++)
                    a[j] %= mod;
            }
        }
        for (int i = 0; i < k; i++)
            A[i] = a[i] % mod;
        if (flag)
            return;
        reverse(A + 1, A + k);
        ll iv = mpow(k);
        for (int i = 0; i < k; i++)
            A[i] = A[i] * iv % mod;
    }
    namespace Public
    {
        poly operator*(const poly &A, const poly &B)
        {
            if (A.empty() || B.empty())
                return poly({});
            int n = A.size(), m = B.size(), lim = n + m - 1;
            init(lim);
            copy(A.begin(), A.end(), a);
            fill(a + n, a + k, 0);
            copy(B.begin(), B.end(), b);
            fill(b + m, b + k, 0);
            ntt(a, k, 1);
            ntt(b, k, 1);
            for (int i = 0; i < k; i++)
                a[i] = 1ll * a[i] * b[i] % mod;
            ntt(a, k, 0);
            return poly(a, a + lim);
        }
        poly &operator*=(poly &A, const poly &B)
        {
            return A = A * B;
        }
        poly operator/(const poly &A, const poly &B)
        {
            poly C = A, D = B;
            reverse(D.begin(), D.end());
            C *= D;
            return poly(C.begin() + int(D.size()) - 1, C.end());
        }
        poly &operator/=(poly &A, const poly &B)
        {
            return A = A / B;
        }
        poly operator*(const poly &A, const int B)
        {
            poly C = A;
            for (int i = 0; i < C.size(); i++)
                C[i] = 1ll * C[i] * B % mod;
            return C;
        }
        poly &operator*=(poly &A, const int &B)
        {
            return A = A * B;
        }
        poly operator+(const poly &A, const poly &B)
        {
            poly C(max(A.size(), B.size()));
            for (int i = 0; i < A.size(); i++)
                C[i] = A[i];
            for (int i = 0; i < B.size(); i++)
                C[i] = (B[i] + C[i]) % mod;
            return C;
        }
        poly &operator+=(poly &A, const poly &B)
        {
            return A = A + B;
        }
        poly operator-(const poly &A, const poly &B)
        {
            poly C(max(A.size(), B.size()));
            for (int i = 0; i < A.size(); i++)
                C[i] = A[i];
            for (int i = 0; i < B.size(); i++)
                C[i] = (C[i] + mod - B[i]) % mod;
            return C;
        }
        poly &operator-=(poly &A, const poly &B)
        {
            return A = A - B;
        }
        poly operator%(const poly &A, const int &B)
        {
            poly C = A;
            if (C.size() > B)
                C.resize(B);
            return C;
        }
        poly &operator%=(poly &A, const int B)
        {
            return A = A % B;
        }
        poly operator<<(const poly &A, const int &B)
        {
            poly C(A.size() + B);
            copy(all(A), C.begin() + B);
            return C;
        }
        poly &operator<<=(poly &A, const int &B)
        {
            return A = A << B;
        }
        poly operator>>(const poly &A, const int &B)
        {
            if (B >= A.size())
                return poly({});
            return poly(A.begin() + B, A.end());
        }
        poly &operator>>=(poly &A, const int &B)
        {
            return A = A >> B;
        }
        poly inve(poly A, int n = -1)
        {
            if (n == -1)
                n = A.size();
            if (n == 1)
                return poly({mpow(A[0])});
            poly A0 = inve(A % (n + 1 >> 1), n + 1 >> 1);
            return A0 * (poly({2}) - A * A0 % n) % n;
        }
        poly sqrt(poly A, int n = -1)
        {
            if (n == -1)
                n = A.size();
            if (n == 1)
                return poly({1});
            poly A0 = sqrt(A % (n + 1 >> 1), n + 1 >> 1);
            return (A0 * A0 % n + A) * inve(A0, n) % n * (mod + 1 >> 1);
        }
        poly der(poly A)
        {
            poly B(A.size() - 1);
            for (int i = 1; i < A.size(); i++)
                B[i - 1] = 1ll * A[i] * i % mod;
            return B;
        }
        poly integ(poly A)
        {
            poly B(A.size() + 1);
            static ll inv[N];
            inv[1] = 1;
            for (int i = 2; i <= A.size(); i++)
                inv[i] = (mod - inv[mod % i]) * (mod / i) % mod;
            for (int i = 0; i < A.size(); i++)
                B[i + 1] = inv[i + 1] * A[i] % mod;
            return B;
        }
        poly ln(poly A, int n = -1)
        {
            if (n == -1)
                n = A.size();
            return integ(der(A) * inve(A, n) % n) % n;
        }
        poly exp(poly A, int n = -1)
        {
            if (n == -1)
                n = A.size();
            if (n == 1)
                return poly({1});
            poly A0 = exp(A % (n + 1 >> 1), n + 1 >> 1);
            return A0 * (poly({1}) - ln(A0, n) + A) % n;
        }
        poly mPow(poly A, int n, ll k)
        {
            auto p = find_if(A.begin(), A.end(), [](ll x)
                             { return x; }) -
                     A.begin();
            if (p == A.size())
                return A;
            poly B(A.size() - p);
            for (int i = p; i < A.size(); i++)
                B[i - p] = A[i];
            ll v = mpow(B[0], k % Mod), iv = mpow(B[0]);
            for (ll &i : B)
                i = i * iv % mod;
            B = ln(B, n);
            for (ll &i : B)
                i = k % mod * i % mod;
            B = exp(B, n);
            for (ll &i : B)
                i = i * v % mod;
            for (int i = n - 1; ~i; i--)
                B[i] = (i >= 1ll * k * p ? B[i - k * p] : 0);
            return B;
        }
    }
}
using namespace Poly::Public;
// 对多项式 C 取模 P(X) 并返回结果
poly pmod(const poly &C, const poly &P)
{
    int k = P.size() - 1;
    poly R = C;
    while ((int)R.size() > k)
    {
        ll coef = R.back();
        R.pop_back();
        if (!coef)
            continue;
        int d = R.size();
        for (int i = 0; i < k; i++)
        {
            R[d - 1 - i] = (R[d - 1 - i] - coef * P[k - 1 - i] % mod + mod) % mod;
        }
    }
    R.resize(k);
    return R;
}
// 计算 X^n mod P(X) 的函数（省略实现细节）
poly pfast(ll n, const poly &P)
{
    int k = P.size() - 1;
    poly res(k, 0), base(k, 0);
    res[0] = 1;
    if (k > 1)
        base[1] = 1;
    else
        base[0] = (mod + P[0]) % mod;
    while (n)
    {
        if (n & 1)
            res = pmod(res * base, P);
        base = pmod(base * base, P);
        n >>= 1;
    }
    return res;
}
//-----------------------------------------------------//
struct oo
{
};
string a, b;
void Raze()
{
    cin >> a >> b;
    poly x, y;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        x.pb(a[i] - '0');
    }
    for (int i = b.size(); i >= 0; i--)
    {
        y.pb(b[i] - '0');
    }
    poly ans = x * y;
    int len = ans.size();
    ans.resize(len << 2);
    debug(len);
    for (int i = 0; i < len; i++)
        cout << a[i];
    // len <<= 2;
    // int mx = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     if (ans[i] == 1)
    //         mx = i;
    //     if (ans[i] <= 1)
    //         continue;
    //     int t = ans[i] / 2;
    //     ans[i] %= 2;
    //     ans[i + 2] += t;
    //     ans[i + 4] += t;
    // }
    // for (int i = mx; i >= 0; i--)
    //     cout << ans[i];
    // cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}