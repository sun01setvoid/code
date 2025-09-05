#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
const int L = 16;
//-----------------------------------------------------//
int n, k;
struct mat
{
    int a[17][17];
} A, B;
mat mul(mat am, mat bm)
{
    mat cm;
    memset(cm.a, 0, sizeof(cm.a));
    for (int k = 0; k <= L; k++)
        for (int i = 0; i <= L; i++)
            for (int j = 0; j <= L; j++)
                (cm.a[i][j] +=am.a[i][k] * bm.a[k][j] % mod) %= mod;
    return cm;
}
int qpow(int a, int k, int p)
{
    int ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ans;
}
int op(int i, int j, int o)
{
    if (o == 0)
        return i + j;
    if (o == 1)
        return i * j;
    if (o == 2)
        return i ^ j;
    if (o == 3)
        return i | j;
    if (o == 4)
        return i & j;
    return 0;
}
void solve()
{
    memset(B.a, 0, sizeof B.a);
    memset(A.a, 0, sizeof A.a);
    cin >> n >> k;
    int st = 0;
    for (int i = 1, x; i <= k; i++)
        cin >> x, st |= (1 << x);
    for (int j = 1; j <= 9; j++)
    {
        if (st >> j & 1)
            A.a[16][16] += 3 + j;
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (st >> j & 1)
            {
                A.a[i][16] += (i + j) / 16;
                A.a[i][(i + j) % 16]++;
                A.a[i][16] += i * j / 16;
                A.a[i][i * j % 16]++;
                A.a[i][i ^ j]++;
                A.a[i][i | j]++;
                A.a[i][i & j]++;
            }
        }
    }
    for (int j = 1; j <= 9; j++)
    {
        if (st >> j & 1)
            B.a[0][j] = 1;
    }
    int pw = qpow(5, n - 1,mod) * qpow(k, n,mod) % mod;
    pw = qpow(pw, mod - 2,mod);
    for (n--; n; n >>= 1)
    {
        if (n & 1)
            B = mul(B, A);
        A = mul(A, A);
    }
    int ans = 0;
    for (int i = 0; i <= 16; i++)
    {
        if (B.a[0][i])
            (ans += i * B.a[0][i] % mod) %= mod;
    }
    cout << ans * pw % mod << endl;
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