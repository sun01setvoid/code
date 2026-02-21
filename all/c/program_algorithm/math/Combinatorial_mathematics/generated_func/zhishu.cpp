#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ull = unsigned long long;
using namespace std;
#define int long long
using ll = long long;
using poly = vector<ll>;
const int mod = 998244353;
const int Mod = mod - 1;
ll mpow(ll x, int y = mod - 2)
{
    ll ans = 1;
    while (y)
        (y & 1) && (ans = ans * x % mod), y >>= 1, x = x * x % mod;
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
        poly inve(poly A, int n = -1)
        {
            if (n == -1)
                n = A.size();
            if (n == 1)
                return poly({mpow(A[0])});
            poly A0 = inve(A % (n + 1 >> 1), n + 1 >> 1);
            return A0 * (poly({2}) - A * A0 % n) % n;
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
void solve()
{
    
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