#include <iostream>
using namespace std;
const int N = 3e5 + 10;
bool st[N];
int primes[N];
int cnt = 0;
/*initial*/
/*
bool isp(int x)
{
    if (x<=1)   return false;
    for (int i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}
    */
/*Decomposition of prime factors*/
// O(n**0.5)
void divide(int x)
{
    // 先检测一半的部分，剩下的再单独判断
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0)
                x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    if (x > 1)
        cout << x << ' ' << 1 << endl;
    cout << endl;
}
/*Eratosthenes' Sieve*/
/*
bool isp(int n){       //很多个数字
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]){    //用质数还筛合数，算数基本定理
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }

}
*/
/*Eratosthenes' Sieve 只是计数，就不用标记合数*/
// 偶数的质数只有2，2只会标记偶数是合数
// 奇数合数的筛都是被奇数筛的
// 从三开始遍历，每一步+=2，只看奇数
// j=i*i开始，每一步j+=2*i,只把是合数的“奇数”标记，数量--
// tip,一开始2，3是质数,所以cnt先记为(n+1)/2,算奇数的个数，且-1（1），+1（2），所以还是(n+1)/2
/*The sieve of Euler*/
void isp(int n) // 莫比乌斯和hash注释
{
    st[1] = 1;                   // Mob[1]=1;
    for (int i = 2; i <= n; i++) // 质数*i的都筛，所以每个i都要筛，而且线性筛要去重，每个都用最小的质因数筛
    {
        if (!st[i])
            primes[cnt++] = i;                   // Mob[i]=-1,hahs[i]=rnd();
        for (int j = 0; primes[j] <= n / i; j++) // 或者j<cnt,也可以
        {
            st[primes[j] * i] = true;
            // Mob[i*prime[j]]=(i%prime[j]?-Mob[i]:0);
            // hash[i*prime[j]]=hash[i]*hash[prime[j]];
            if (i % primes[j] == 0)
                break; // 用最小质数来筛
        }
    }
}

// 1~n上的质数大约有n/logn个
int main()
{
    isp(1000000000);
    cout << cnt << "\n";
    cout << "[";
    for (int i = 0; i < cnt; i++)
    {
        cout << primes[i] << ",";
    }
    cout << "]";
}
/*
#include <bits/stdc++.h>

namespace FastIO {
    int fastio_digit[67], fastio_len = 0;
    template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
    template <typename T> inline void write(T x) { if (!x) return (void)putchar('0'); while (x) fastio_digit[++fastio_len] = x % 10, x /= 10; while (fastio_len > 0) putchar(fastio_digit[fastio_len--] ^ '0'); }
    template <typename T> inline void print(T x) { if (x >= 0) write<T>(x); else putchar('-'), write<T>(-x); }
    template <typename T> inline void print(T x, char en) { print<T>(x), putchar(en); }
}; using namespace FastIO;

const int V = 5'000'000;
using uint = unsigned long long;

std::mt19937 eng(std::chrono::steady_clock::now().time_since_epoch().count());
uint rnd(uint l = 0ull, uint r = ~0ull) { return std::uniform_int_distribution<uint>(l, r)(eng); }

#define MAXN 1000001
#define MAXV ((V) + 1)
bool compose[MAXV]; uint hash[MAXV];
void sieve() {
    std::vector<int> prime;
    for (int i = 2; i <= V; ++i) {
        if (!compose[i]) prime.push_back(i), hash[i] = rnd();
        for (int j : prime) if (i * j <= V) {
            compose[i * j] = true, hash[i * j] = hash[i] ^ hash[j];
            if (i % j == 0) break;
        } else break;
    }
}

void solve() {
    int n = read<int>(); uint h = 0;
    if (n == 2) {
        int x = read<int>(), y = read<int>();
        return (void)puts(x == y ? "YES" : "NO");
    }
    for (int i = 1; i <= n; ++i)
        h ^= hash[read<int>()];
    puts((n & 1) || h == 0 ? "YES" : "NO");
}

int main() { int t = read<int>(); sieve(); while (t--) solve(); return 0; }
*/