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
    }
}
using namespace Poly::Public;