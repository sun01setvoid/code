#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
//****************************************************************
// Miller_Rabin 算法进行素数测试
// 速度快，而且可以判断 <2^63的数
//****************************************************************
const int mod = 998244353;
const int S = 20; // 随机算法判定次数，S越大，判错概率越小
// 计算 (a*b)%c.   a,b都是int的数，直接相乘可能溢出的
//   a,b,c <2^63
int mult_mod(int a, int b, int c)
{
    a %= c;
    b %= c;
    int ret = 0;
    while (b)
    {
        if (b & 1)
        {
            ret += a;
            ret %= c;
        }
        a <<= 1;
        if (a >= c)
            a %= c;
        b >>= 1;
    }
    return ret;
}
// 计算  x^n %c
int pow_mod(int x, __int128 n, int mod) // x^n%c
{
    if (n == 1)
        return x % mod;
    x %= mod;
    int tmp = x;
    int ret = 1;
    while (n)
    {
        if (n & 1)
            ret = mult_mod(ret, tmp, mod);
        tmp = mult_mod(tmp, tmp, mod);
        n >>= 1;
    }
    return ret;
}
bool check(int a, int n, int x, int t)
{
    int ret = pow_mod(a, x, n);
    int last = ret;
    for (int i = 1; i <= t; i++)
    {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1)
            return true; // 合数
        last = ret;
    }
    if (ret != 1)
        return true;
    return false;
}
bool Miller_Rabin(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false; // 偶数
    int x = n - 1;
    int t = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        t++;
    }
    for (int i = 0; i < S; i++)
    {
        int a = rand() % (n - 1) + 1; // rand()需要stdlib.h头文件
        if (check(a, n, x, t))
            return false; // 合数
    }
    return true;
}
//************************************************
// pollard_rho 算法进行质因数分解
//************************************************
int factor[100]; // 质因数分解结果（刚返回时是无序的）
int tol;         // 质因数的个数。数组小标从0开始
int gcd(int a, int b)
{
    if (a == 0)
        return 1;
    if (a < 0)
        return gcd(-a, b);
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int Pollard_rho(int x, int c)
{
    int i = 1, k = 2;
    int x0 = rand() % x;
    int y = x0;
    while (1)
    {
        i++;
        x0 = (mult_mod(x0, x0, x) + c) % x;
        int d = gcd(y - x0, x);
        if (d != 1 && d != x)
            return d;
        if (y == x0)
            return x;
        if (i == k)
        {
            y = x0;
            k += k;
        }
    }
}
// 对n进行素因子分解
void findfac(int n)
{
    if (Miller_Rabin(n)) // 素数
    {
        factor[tol++] = n;
        return;
    }
    int p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p);
    findfac(n / p);
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = gcd(a, b);
    findfac(t);
    sort(factor, factor + tol);
    int ans = 1, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < tol; i++)
    {
        cnt1 = 0;
        cnt2 = 0;
        while (a % factor[i] == 0)
        {
            a /= factor[i];
            cnt1++;
        }
        while (c % factor[i] == 0)
        {
            c /= factor[i];
            cnt2++;
        }
        __int128 exp1 = (__int128)cnt1 * b;
        __int128 exp2 = (__int128)cnt2 * d;
        __int128 exp = min(exp1, exp2);
        ans = (ans * pow_mod(factor[i], exp, mod)) % mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
