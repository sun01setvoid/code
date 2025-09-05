#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
// #define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
ll a[maxn], tag[maxn];
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int min(int a, int b) { return a <= b ? a : b; }
int max(int a, int b) { return a >= b ? a : b; }
int st[maxn], cnt, primes[maxn];
vector<unordered_map<int, int>> num(maxn);
void isp(int n)
{
    st[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i, st[i] = i, num[i][i] = 1;
        for (int j = 0; i * primes[j] <= n; j++)
        {
            st[primes[j] * i] = primes[j];
            num[primes[j] * i] = num[i];
            num[primes[j] * i][primes[j]]++;
            if (i % primes[j] == 0)
                break;
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    isp(n);
    int bs = 300;
    vector<ll> pr(bs + 1, 0);
    vii cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cnt[i] = n / i;
    for (int i = 1; i <= n; i++)
        tag[i] = 0;
    vector<vii> fac(n + 1);
    vector<vii> GCD(n + 1, vii(min(bs / 2 + 5, n + 5)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(bs / 2, n); j++)
        {
            if (i == 1 || j == 1)
                GCD[i][j] = 1;
            else
            {
                int d = j / st[j];
                if (i % st[j] == 0 && d % st[j] != 0 || (i % st[j] == 0 && d % st[j] == 0 && num[i][st[j]] > num[d][st[j]]))
                    GCD[i][j] = GCD[i][d] * st[j];
                else
                    GCD[i][j] = GCD[i][d];
            }
            // cout << i << " " << j << " " << GCD[i][j] << endl;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                fac[i].pb(j);
                if (i / j != j)
                    fac[i].pb(i / j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(n, bs); j++)
        {
            if (i % j == 0)
                pr[j] += a[i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x, k;
            cin >> x >> k;
            if (x <= bs)
            {
                for (int j = 1; j <= min(n, bs); j++)
                {
                    int res;
                    if (j <= bs / 2)
                    {
                        res = x / GCD[x][j] * j;
                    }
                    else
                    {
                        int d = j / st[j];
                        int t;
                        if (x % st[j] == 0 && d % st[j] != 0 || (x % st[j] == 0 && d % st[j] == 0 && num[x][st[j]] > num[d][st[j]]))
                            t = GCD[x][d] * st[j];
                        else
                            t = GCD[x][d];
                        res = x / t * j;
                    }
                    pr[j] += k * (n / res);
                }
                tag[x] += k;
            }
            else
            {
                for (int j = 1; j * x <= n; j++)
                {
                    int id = j * x;
                    a[id] += k;
                }
                for (int j = 1; j <= min(n, bs); j++)
                {
                    int res;
                    if (j <= bs / 2)
                    {
                        res = x / GCD[x][j] * j;
                    }
                    else
                    {
                        int d = j / st[j];
                        int t;
                        if (x % st[j] == 0 && d % st[j] != 0 || (x % st[j] == 0 && d % st[j] == 0 && num[x][st[j]] > num[d][st[j]]))
                            t = GCD[x][d] * st[j];
                        else
                            t = GCD[x][d];
                        res = x / t * j;
                    }
                    pr[j] += k * (n / res);
                }
            }
        }
        else if (op == 2)
        {
            ll x, k;
            cin >> x >> k;
            for (int j : fac[x])
            {
                a[j] += k;
                if (j <= bs)
                {
                    int yu = x / j;
                    pr[j] += k * fac[yu].size();
                }
            }
        }
        else if (op == 3)
        {
            ll x;
            cin >> x;
            if (x <= bs)
                cout << pr[x] << endl;
            else
            {
                ll sum = 0;
                ll tagsum = 0;
                for (int j = 1; j * x <= n; j++)
                {
                    sum += a[j * x];
                }
                for (int j = 1; j <= min(n, bs); j++)
                {
                    int res;
                    if (j <= bs / 2)
                    {
                        res = x / GCD[x][j] * j;
                    }
                    else
                    {
                        int d = j / st[j];
                        int t;
                        if (x % st[j] == 0 && d % st[j] != 0 || (x % st[j] == 0 && d % st[j] == 0 && num[x][st[j]] > num[d][st[j]]))
                            t = GCD[x][d] * st[j];
                        else
                            t = GCD[x][d];
                        res = x / t * j;
                    }
                    sum += tag[j] * (n / res);
                }
                cout << sum << endl;
            }
        }
        else
        {
            ll x;
            cin >> x;
            ll sum = 0;
            for (int j : fac[x])
            {
                sum += a[j];
                int yu = x / j;
                sum += tag[j] * fac[yu].size();
            }
            cout << sum << endl;
        }
    }
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}