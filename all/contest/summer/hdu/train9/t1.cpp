#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e2 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-4;
//-----------------------------------------------------//
int fpow(int a, int k, int p)
{
    int ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return ans;
}
int n;
void solve()
{
    cin >> n;
    __int128 k = (n + 118) / 119;
    if (k <= 23)
    {
        __int128 tmp1 = 1, tmp2 = 1;
        for (__int128 i = 1; i <= k; i++)
        {
            tmp1 = tmp1 * 2;
        }
        for (__int128 i = 1; i <= 2 * k; i++)
            tmp2 = tmp2 * 2;
        __int128 ans = 0;
        for (__int128 i = 1; i <= n - 1; i++)
        {
            __int128 inv = fpow(i, n - 2, n);
            __int128 val = (inv + tmp1) * (i + tmp2);
            ans ^= val;
        }
        cout << (int)(ans % mod) << endl;
        return;
    }
    __int128 ans = (n - 1) % mod * ((n - 1) % mod) + 1;
    __int128 val = (fpow(2, k, mod) + fpow(4, k, mod)) % mod * ((n - (n % 4 == 1)) % mod) % mod;
    cout << (int)((ans % mod + val % mod) % mod) << endl;
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