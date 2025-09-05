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
const int inv2 = (mod + 1) / 2;
const ld eps = 1e-7;
//-----------------------------------------------------//
int fac[maxn], inv_fac[maxn];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vii suf(n + 2), pre(n + 2), sum(n + 2);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i - 1] == '(' ? 1 : 0);
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + (s[i - 1] == ')' ? 1 : 0);
    int j = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        j = max(i, j);
        while (j <= n && sum[j] > 1)
            j++;
        if (s[i - 1] == '(')
            ans = (ans + fac[pre[i - 1]] * fac[suf[j + 1]] % mod) % mod;
    }
    ans = (ans + fac[n / 2]) % mod;
    cout << ans * inv_fac[n] % mod << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    fac[0] = 1;
    inv_fac[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        fac[i] = fac[i - 1] * 2 % mod, inv_fac[i] = inv_fac[i - 1] * inv2 % mod;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}