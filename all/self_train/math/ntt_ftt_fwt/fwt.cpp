#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int fast(int a, int b)
{
    if (b == 0)
        return 1;
    int ans = fast((a * a) % mod, b / 2);
    if (b & 1)
        ans = (ans * a) % mod;
    return ans;
}
int fac[maxn], inv[maxn], n, m, k;
void fwtor(vii &a, bool in) // in:0-正,1-逆
{
    int n = a.size();
    for (int len = 1; len < n; len <<= 1)
    {
        for (int i = 0; i < n; i += len << 1)
        {
            for (int j = 0; j < len; j++)
            {
                int &u = a[i + j], &v = a[i + j + len];
                if (!in)
                {
                    v = (v + u) % mod;
                }
                else
                {
                    v = (v - u + mod) % mod;
                }
            }
        }
    }
}
void fwtand(vector<int> &a, bool in)
{
    int n = a.size();
    for (int len = 1; len < n; len <<= 1)
    {
        for (int i = 0; i < n; i += len << 1)
        {
            for (int j = 0; j < len; j++)
            {
                int &u = a[i + j], &v = a[i + j + len];
                if (!in)
                    u = (u + v) % mod;
                else
                    u = (u - v + mod) % mod;
            }
        }
    }
}
void fwtxor(vector<int> &a, bool in) 
{
    int n = a.size();
    for (int len = 1; len < n; len <<= 1)
    {
        for (int i = 0; i < n; i += len << 1)
        {
            for (int j = 0; j < len; j++)
            {
                int u = a[i + j], v = a[i + j + len];
                a[i + j] = (u + v) % mod;
                a[i + j + len] = (u - v + mod) % mod;
                if (in)
                {
                    // 逆变换时都需乘 inv2
                    // 这里假设 mod 是质数，并预先算好 inv2
                    static int inv2 = (mod + 1) / 2;
                    a[i + j] = 1LL * a[i + j] * inv2 % mod;
                    a[i + j + len] = 1LL * a[i + j + len] * inv2 % mod;
                }
            }
        }
    }
}
// how to use?
// 自卷积例子
void Raze()
{
    
}
// 两个序列卷积：
/*
fwtor(A, 0); // A -> FWT(A)
fwtor(B, 0); // B -> FWT(B)
// 2. 点乘
for (int i = 0; i < n; i++) A[i] = 1LL * A[i] * B[i] % mod;
// 3. FWT 逆变换
fwtor(A, 1); // A -> 巻积结果
*/