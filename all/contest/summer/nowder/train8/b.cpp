#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
//#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 4e1 + 5;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};

int n, a, b, c, p[maxm], g[maxn], h[maxn], f[maxn];
void Raze() //一次对换奇偶性改变一次
{
    for (int i = 0; i <= 5; i++)
        f[i] = g[i] = h[i]  = 0;
    cin >> n >> a >> b >> c; int pre = 0;
    g[0] = (a ^ (a << 16)) & ((1 << 30) - 1);
    h[0] = g[0] ^ (g[0] >> 5);
    f[0] = h[0] ^ ((h[0] << 1) & ((1 << 30) - 1)) ^ b ^ c;
    g[1] = (b ^ (b << 16)) & ((1 << 30) - 1);
    g[2]= (c ^ (c << 16)) & ((1 << 30) - 1);
    h[1]= g[1] ^ (g[1] >> 5);
    f[1] = h[1] ^ ((h[1] << 1) & ((1 << 30) - 1)) ^ c ^ f[0];
    h[2]= g[2] ^ (g[2] >> 5);
    f[2] = h[2] ^ ((h[2] << 1) & ((1 << 30) - 1)) ^ f[0] ^ f[1];
    int l = 0, r = 0 + f[0] % (n - 0);
    if (n > 1)
    {
        if (abs(r - l) > 0)pre ^= 1;
        l = 1, r = 1 + f[1] % (n - 1);
    }
    if (n > 2)
    {
        if (abs(r - l) > 0)pre ^= 1;
        l = 2, r = 2 + f[2] % (n - 2);
    }
    if (abs(r - l) > 0)pre ^= 1;
    for (int i = 3; i < n; i++)
    {
        int id = i % 4;
        g[id] = (f[(id - 3 + 4) % 4] ^ (f[(id - 3 + 4) % 4] << 16)) & ((1 << 30) - 1);
        h[id] = g[id] ^ (g[id] >> 5);
        f[id]= h[id] ^ ((h[id] << 1) & ((1 << 30) - 1)) ^ f[(id - 2+4)%4] ^ f[(i - 1+4)%4];
        l = i, r = i + f[id] % (n - i);
        if (abs(r - l) > 0)pre ^= 1;
    }
    cout << pre;
    for (int i = n; i <= 4 * n-3; i++)
    {
        int id = i % 4;
        g[id] = (f[(id - 3 + 4) % 4] ^ (f[(id - 3 + 4) % 4] << 16)) & ((1 << 30) - 1);
        h[id] = g[id] ^ (g[id] >> 5);
        f[id] = h[id] ^ ((h[id] << 1) & ((1 << 30) - 1)) ^ f[(id - 2 + 4) % 4] ^ f[(i - 1 + 4) % 4];
        if ((i - n) % 3 == 2)
        {
            int l= min(f[(id-2+4)%4] % n, f[(id-1+4)%4] % n);
            int r= max(f[(id - 2+4)%4] % n, f[(id - 1+4)%4] % n);
            int d = f[id] % n + 1;
            int len = r - l + 1;
            if (len % 2 == 0 && d % 2 == 1)pre ^= 1;
            cout << pre;
        }
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}
