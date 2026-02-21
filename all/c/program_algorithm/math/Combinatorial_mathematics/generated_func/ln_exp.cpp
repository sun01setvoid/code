//置换群
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ull = unsigned long long;
#define debug(x) cerr << #x << '=' << (x) << endl
using namespace std;
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
    int tr[N], k;
    ll a[N], b[N], pw[N];

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

    void ntt(ll *A, int k, int flag)
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
                    ll x = a[h + i / 2] * e[h - j] % mod;
                    a[h + i / 2] = a[h] + mod - x;
                    a[h] += x;
                }
            }
            if (i == (1 << 18))
                for (int j = 0; j < k; j++)
                    a[j] %= mod;
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
                a[i] = a[i] * b[i] % mod;
            ntt(a, k, 0);
            return poly(a, a + lim);
        }

        poly &operator*=(poly &A, const poly &B) { return A = A * B; }

        poly operator*(const poly &A, const int B)
        {
            poly C = A;
            for (int i = 0; i < C.size(); i++)
                C[i] = C[i] * B % mod;
            return C;
        }

        poly &operator*=(poly &A, const int &B) { return A = A * B; }

        poly operator+(const poly &A, const poly &B)
        {
            poly C(max(A.size(), B.size()));
            for (int i = 0; i < A.size(); i++)
                C[i] = A[i];
            for (int i = 0; i < B.size(); i++)
                C[i] = (B[i] + C[i]) % mod;
            return C;
        }

        poly &operator+=(poly &A, const poly &B) { return A = A + B; }

        poly operator-(const poly &A, const poly &B)
        {
            poly C(max(A.size(), B.size()));
            for (int i = 0; i < A.size(); i++)
                C[i] = A[i];
            for (int i = 0; i < B.size(); i++)
                C[i] = (C[i] + mod - B[i]) % mod;
            return C;
        }

        poly &operator-=(poly &A, const poly &B) { return A = A - B; }

        poly operator%(const poly &A, const int &B)
        {
            poly C = A;
            if (C.size() > B)
                C.resize(B);
            return C;
        }

        poly &operator%=(poly &A, const int B) { return A = A % B; }

        poly inve(poly A, int n = -1)
        {
            if (n == -1)
                n = A.size();
            if (n == 1)
                return poly({mpow(A[0])});
            poly A0 = inve(A % ((n + 1) >> 1), (n + 1) >> 1);
            return (A0 * 2 - A * A0 % n * A0) % n;
        }

        poly der(poly A)
        {
            poly B(A.size() - 1);
            for (int i = 1; i < A.size(); i++)
                B[i - 1] = A[i] * i % mod;
            return B;
        }

        poly integ(poly A)
        {
            poly B(A.size() + 1);
            static ll inv[N];
            inv[1] = 1;
            for (int i = 2; i <= A.size(); i++)
                inv[i] = (mod - mod / i) * inv[mod % i] % mod;
            for (int i = 0; i < A.size(); i++)
                B[i + 1] = A[i] * inv[i + 1] % mod;
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
            poly A0 = exp(A % ((n + 1) >> 1), (n + 1) >> 1);
            return A0 * (poly({1}) - ln(A0, n) + A) % n;
        }
    }
}
using namespace Poly::Public;
const int maxn = 200010;
int t, k;
ll fac_k[maxn], inv_fac_k[maxn]; // (n!)^(k+1) 和 逆
ll inv_nk[maxn];                 // inv(n)^(k+1)
ll inv[maxn];
poly F, G, S, H;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> k;
    inv[1] = 1;
    for (int i = 2; i < maxn; i++)
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    fac_k[0] = inv_fac_k[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        inv_nk[i] = mpow(inv[i], k + 1);                // inv(i)^(k+1)
        fac_k[i] = fac_k[i - 1] * mpow(i, k + 1) % mod; // i^(k+1)
        inv_fac_k[i] = inv_fac_k[i - 1] * inv_nk[i] % mod;
    }
    F.resize(maxn);
    for (int j = 0; j < maxn; j++)
        F[j] = inv_fac_k[j];
    G = ln(F);
    S.assign(maxn, 0);
    for (int j = 1; j < maxn; j++)
    {
        ll gj = G[j];
        for (int i = 1; i * j < maxn; i++)
        {
            int m = i * j;
            ll w = mpow(inv_nk[i], j);
            S[m] = (S[m] + gj * w) % mod;
        }
    }
    H = exp(S);
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = H[n] * fac_k[n] % mod;
        cout << (ans + mod) % mod << '\n';
    }
    return 0;
}