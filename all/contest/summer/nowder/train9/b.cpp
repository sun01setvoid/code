#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
int fast(int a, int b = mod - 2)
{
    if (b == 0)return 1;
    int ans = fast((a * a) % mod, b / 2);
    if (b & 1)ans = ans * a % mod;
    return ans;
}

int n; string s; int cnt0[maxn]; int psum[maxn];
int fac[maxn], inv[maxn], suf[maxn][10], su[maxn];
int sday[maxn][4], smd[maxn][15], pr[maxn][10];
int p2[maxn], p3[maxn], p4[maxn];
int rp[maxn][10], rn[maxn], frn[maxn];
int C(int a, int b)
{
    if (a < b)return 0; int ans = fac[a] * inv[b] % mod; return ans * inv[a - b] % mod;
}
void solve()
{
    cin >> n >> s; s = " " + s;
    for (int i = 1; i <= n; i++)cnt0[i] = cnt0[i - 1] + (s[i] == '0');
    for (int i = 1; i <= n; i++)psum[i] = ((C(i, 4) - C(cnt0[i], 4)) % mod + mod) % mod;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < 10; j++)suf[i][j] = suf[i + 1][j];
        suf[i][s[i] - '0']++;
        for (int j = 0; j < 10; j++)su[i] = (su[i] + suf[i][j]) % mod;
    }
    for (int i = n; i >= 1; i--)
    {
        sday[i][0] = sday[i + 1][0];
        sday[i][1] = sday[i + 1][1];
        sday[i][2] = sday[i + 1][2];
        sday[i][3] = sday[i + 1][3];
        if (s[i] == '0')
        {
            int val = su[i + 1];
            sday[i][0] = (sday[i][0] + val) % mod;
            sday[i][1] = (sday[i][1] + val) % mod;
            sday[i][2] = (sday[i][2] + val) % mod;
            sday[i][3] = (sday[i][3] + val) % mod;
        }
        else if (s[i] == '1')
        {
            int val = su[i + 1];
            sday[i][0] = (sday[i][0] + val) % mod;
            sday[i][1] = (sday[i][1] + val) % mod;
            sday[i][2] = (sday[i][2] + val) % mod;
            sday[i][3] = (sday[i][3] + val) % mod;
        }
        else if (s[i] == '2')
        {
            int val1 = su[i + 1] - suf[i + 1][9];
            int val2 = su[i + 1];
            sday[i][0] = (sday[i][0] + val1) % mod;
            sday[i][1] = (sday[i][1] + val2) % mod;
            sday[i][2] = (sday[i][2] + val2) % mod;
            sday[i][3] = (sday[i][3] + val2) % mod;
        }
        else if (s[i] == '3')
        {
            int val1 = suf[i + 1][0], val2 = suf[i + 1][1];
            sday[i][2] = (sday[i][2] + val1) % mod;
            sday[i][3] = (sday[i][3] + val2 + val1) % mod;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        int val = s[i] - '0';
        for (int j = 1; j <= 13; j++)
            smd[i][j] = smd[i + 1][j];
        if (val == 0)
        {
            smd[i][1] = (smd[i][1] + sday[i + 1][3]) % mod;
        }
        else if (val == 1)
        {
            smd[i][2] = (smd[i][2] + sday[i + 1][2]) % mod;
            smd[i][3] = (smd[i][3] + sday[i + 1][3]) % mod;
        }
        else if (val == 2)
        {
            smd[i][4] = (smd[i][4] + sday[i + 1][0]) % mod;
            smd[i][5] = (smd[i][5] + sday[i + 1][1]) % mod;
            smd[i][6] = (smd[i][6] + sday[i + 1][3]) % mod;
        }
        else if (val == 4 || val == 6 || val == 9)
        {
            smd[i][val + 4] = (smd[i][val + 4] + sday[i + 1][2]) % mod;
        }
        else
        {
            smd[i][val + 4] = (smd[i][val + 4] + sday[i + 1][3]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)pr[i][j] = pr[i - 1][j];
        pr[i][s[i] - '0']++;
    }
    for (int i = 1; i <= n; i++)
    {
        p2[i] = p2[i - 1];
        if (s[i] == '4' || s[i] == '8')
        {
            p2[i] = (p2[i] + pr[i - 1][0] + pr[i - 1][2] + pr[i - 1][4] + pr[i - 1][6] + pr[i - 1][8]) % mod;
        }
        else if (s[i] == '2' || s[i] == '6')
        {
            p2[i] = (p2[i] + pr[i - 1][1] + pr[i - 1][3] + pr[i - 1][5] + pr[i - 1][7] + pr[i - 1][9]) % mod;
        }
        else if (s[i] == '0')
        {
            p2[i] = (p2[i] + pr[i - 1][2] + pr[i - 1][4] + pr[i - 1][6] + pr[i - 1][8]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        p3[i] = p3[i - 1];
        if (s[i] == '0')
        {
            p3[i] = (p3[i] + p2[i - 1]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        p4[i] = p4[i - 1];
        if (s[i] == '0')
        {
            p4[i] = (p4[i - 1] + p3[i - 1]) % mod;//到i闰年个数
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)rp[i][j] = rp[i - 1][j];
        rp[i][s[i] - '0'] = (rp[i][s[i] - '0'] + C(i - 1, 2)) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        rn[i] = rn[i - 1];
        if (s[i] == '4' || s[i] == '8')
        {
            rn[i] = (rn[i] + rp[i - 1][2] + rp[i - 1][4] + rp[i - 1][6] + rp[i - 1][8] + rp[i - 1][0]) % mod;
        }
        else if (s[i] == '2' || s[i] == '6')
        {
            rn[i] = (rn[i] + rp[i - 1][1] + rp[i - 1][3] + rp[i - 1][5] + rp[i - 1][7] + rp[i - 1][9]) % mod;
        }
        else if (s[i] == '0')
        {
            rn[i] = (rn[i] + rp[i - 1][2] + rp[i - 1][4] + rp[i - 1][6] + rp[i - 1][8]) % mod;
        }
    }
    //for (int i = 1; i <= n; i++)cout << rn[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++)rn[i] = (rn[i] + p4[i]) % mod;//闰年个数
    for (int i = 1; i <= n; i++)frn[i] = ((psum[i] - rn[i]) % mod + mod) % mod;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            ans = (ans + psum[i - 1] * smd[i + 1][1] % mod + psum[i - 1] * smd[i + 1][2] % mod + psum[i - 1] * smd[i + 1][6] % mod) % mod;
        }
        else if (s[i] == '0')
        {
            int val = smd[i + 1][3] + smd[i + 1][4] + smd[i + 1][7] + smd[i + 1][8] + smd[i + 1][9] + smd[i + 1][10] + smd[i + 1][11] + smd[i + 1][12] + smd[i + 1][13];
            val %= mod;
            ans = (ans + val * frn[i - 1] % mod) % mod;
            val -= smd[i + 1][4]; val += smd[i + 1][5];
            ans = (ans + val * rn[i - 1] % mod) % mod;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    fac[0] = 1; for (int i = 1; i < maxn; i++)fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = fast(fac[maxn - 1]); for (int i = maxn - 2; i >= 0; i--)inv[i] = inv[i + 1] * (i + 1) % mod;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
/*
8
20000229
*/