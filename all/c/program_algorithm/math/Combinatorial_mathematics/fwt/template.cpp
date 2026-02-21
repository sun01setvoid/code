#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 1 << 18;
int n;
int A[N], B[N];
int a[N], b[N];
void init()
{
    for (int i = 0; i < n; i++)
        a[i] = A[i], b[i] = B[i];
}
void Or(int *a, int type)
{
    for (int x = 2; x <= n; x <<= 1)
    {
        int k = x >> 1;
        for (int i = 0; i < n; i += x)
        {
            for (int j = 0; j < k; j++)
            {
                (a[i + j + k] += a[i + j] * type) %= mod;
            }
        }
    }
}
void And(int *a, int type)
{
    for (int x = 2; x <= n; x <<= 1)
    {
        int k = x >> 1;
        for (int i = 0; i < n; i += x)
        {
            for (int j = 0; j < k; j++)
            {
                (a[i + j] += a[i + j + k] * type) %= mod;
            }
        }
    }
}
void Xor(int *a, int type)
{
    for (int x = 2; x <= n; x <<= 1)
    {
        int k = x >> 1;
        for (int i = 0; i < n; i += x)
        {
            for (int j = 0; j < k; j++)
            {
                (a[i + j] += a[i + j + k]) %= mod;
                (a[i + j + k] = a[i + j] - a[i + j + k] * 2) %= mod;
                (a[i + j] *= type) %= mod;
                (a[i + j + k] *= type) %= mod;
            }
        }
    }
}
void calc()
{
    for (int i = 0; i < n; i++)
        (a[i] *= b[i]) %= mod;
}
void print()
{
    for (int i = 0; i < n; i++)
        cout << (a[i] % mod + mod) % mod << " ";
    cout << endl;
}
signed main()
{
    cin >> n;
    n = 1 << n; //要2的幂次
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    init();
    Or(a, 1);
    Or(b, 1);
    calc();
    Or(a, mod - 1);
    print();
    init();
    And(a, 1);
    And(b, 1);
    calc();
    And(a, mod - 1);
    print();
    init();
    Xor(a, 1);
    Xor(b, 1);
    calc();
    Xor(a, 499122177);
    print();
}