#include <bits/stdc++.h>
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
// 如何使用？
int main()
{
    // 卷积乘法
    poly a = {1, 2, 3}; // 表示 f(x) = 1 + 2x + 3x^2
    poly b = {4, 5};    // 表示 g(x) = 4 + 5x
    poly C = a * b;     // 得到 C = f(x) * g(x)
    for (ll c : C)
        cout << c << ' '; // 输出: 4 13 22 15
    // 截断除法
    poly A = {1, 4, 6, 8};
    poly B = {1, 2};
    poly c = A / B;
    // 满足A(X)=B(x)*C(x)+R(x)
    // 多项式平移与截断
    poly a = {1, 2, 3}; // 1 + 2x + 3x^2
    auto b = a << 2;    //  B(x) = A(x) * x² = x² + 2x³ + 3x⁴
    auto c = a >> 1;    // 得到 2 + 3x
    auto d = a % 2;     // 截断为前 2 项：1 + 2x
    poly A = {1, 2, 3}; // 表示 f(x) = 1 + 2x + 3x^2
    auto B = der(A);    // 求导：2 + 6x
    auto C = integ(B);  // 积分：0 + 2x + 3x^2
    poly A = {1, 2, 1};
    auto B = ln(A);  // ln(1 + 2x + x^2)
    poly A = {0, 1}; // 期望 exp(x) = 1 + x + x^2/2! + x^3/3! + ...
    auto B = exp(A); // 得到近似的 exp(x)
    // 计算 A(x)^k 的前 n 项，mPow(A, n, k)
    poly A = {0, 1};        // A(x) = x
    auto B = mPow(A, 5, 3); // A(x)^3 = x^3，B = {0, 0, 0, 1, 0}
    // 如果 A[0] != 0，你可以构造 B(x) 使得 A(x) * B(x) ≡ 1 (mod x^n)：
    poly A = {2, 0, 0};
    auto B = inve(A); // 得到 A 的逆元
    // 多项式开方 sqrt(A)
    poly A = {1, 2, 1}; // A = (1 + x)^2
    auto B = sqrt(A);   // B = {1, 1}，因为 (1 + x)^2 = A
}
/*
double f(double x){
    double res=0,xx=1;
    for(int i=0;i<=m-1;i++){res+=aa[i]*xx;xx*=x;}
    return sqrtl(res*res+1L);
}
double simpson(double l, double r) {
  double mid = (l + r) / 2;
  return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;
}
double asr(double l, double r, double eps, double ans, int step) {
  double mid = (l + r) / 2;
  double fl = simpson(l, mid), fr = simpson(mid, r);
  if (abs(fl + fr - ans) <= 15 * eps && step < 0)
    return fl + fr + (fl + fr - ans) / 15; 
  return asr(l, mid, eps / 2, fl, step - 1) +
         asr(mid, r, eps / 2, fr, step - 1);
}
double calc(double l, double r, double eps) {
  return asr(l, r, eps, simpson(l, r), 12);//12这个是step（可调），step越大时间越长，精度越好
}
//使用时用calc函数
*/