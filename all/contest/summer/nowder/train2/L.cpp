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
const int maxn = 110;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 998244353;
//-----------------------------------------------------//
int p[maxn], sz[maxn], power[maxn];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) p[i] = i, sz[i] = 1;
    int tmp;
    rep(i, 1, n)
    {
        cin >> tmp;
        int fx = find(i), fy = find(tmp);
        if (fx != fy)
            p[fx] = fy, sz[fy] += sz[fx];
    }
    int cnt = 0, cnt2 = 0, oth = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int fx=find(i);
        if (fx == i)
        {
            if (sz[i] & 1)
                cnt++, ans = ans * sz[i] % mod;
            else if (sz[i] == 2)
                cnt2++;
            else
                oth++;
        }
    }
    // debug(cnt);
    if (cnt > 2)
        cout << 0 << endl;
    else if (cnt == 2)
        cout << ans * p[oth] % mod << endl;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (p[i]== i)
            {
                for (int j = 1; j <= sz[i] / 2; j += 2)
                {
                    int t = __gcd(sz[i], j);
                    int num = sz[i] / t;
                    if (num == 2)
                        cnt = (cnt + t * (sz[i] == 2 ? power[oth] : power[oth - 1]) % mod) % mod;
                    else{
                        cnt = (cnt + sz[i] * (sz[i] == 2 ? power[oth] : power[oth - 1]) % mod) % mod;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    power[0] = 1;
    for (int i = 1; i <= maxn; i++)
        power[i] = power[i - 1] * 2 % mod;
    while (_--)
    {
        solve();
    }
    return 0;
}