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
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
ll n, m, a[maxn], tag[maxn];
int min(int a, int b) { return a <= b ? a : b; }
int max(int a, int b) { return a >= b ? a : b; }
int st[maxn], cnt;
int primes[maxn];
vector<unordered_map<int, int>> num(maxn);
void isp(int n)
{
    st[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i, st[i] = i, num[i][i] = 1;
        for (int j = 0; primes[j] <= n / i; j++)
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
    cin >> n >> m;
    isp(n);
    int bs = 400;
    vector<ll> pr(bs + 1, 0);
    vii cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cnt[i] = n / i;
    for (int i = 1; i <= n; i++)
        tag[i] = 0;
    vector<vii> fac(n + 1);
    vector<vii> LCM(n + 1, vii(min(bs / 2 + 1, n + 1)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(bs / 2, n); j++)
        {
            if (i == 1 || j == 1)
                LCM[i][j] = 1;
            else
            {
                int d = j / st[j];
                if (i % st[j] == 0 && d % st[j] != 0 || (i % st[j] == 0 && d % st[j] == 0 && num[i][st[j]] > num[d][st[j]]))
                    LCM[i][j] = LCM[i][d] * st[j];
                else
                    LCM[i][j] = LCM[i][d];
            }
            // cout << i << " " << j << " " << LCM[i][j] << endl;
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
                        res = LCM[x][j];
                    else
                    {
                        int d = j / st[j];
                        if (x % st[j] == 0 && d % st[j] != 0 || (x % st[j] == 0 && d % st[j] == 0 && num[x][st[j]] > num[d][st[j]]))
                            res = LCM[x][d] * st[j];
                        else
                            res = LCM[x][d];
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
                        res = LCM[x][j];
                    else
                    {
                        int d = j / st[j];
                        if (x % st[j] == 0 && d % st[j] != 0 || (x % st[j] == 0 && d % st[j] == 0 && num[x][st[j]] > num[d][st[j]]))
                            res = LCM[x][d] * st[j];
                        else
                            res = LCM[x][d];
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
                for (int j = 1; j <= bs; j++)
                {
                    int res;
                    if (j <= bs / 2)
                        res = LCM[x][j];
                    else
                    {
                        int d = j / st[j];
                        if (x % st[j] == 0 && d % st[j] != 0 || (x % st[j] == 0 && d % st[j] == 0 && num[x][st[j]] > num[d][st[j]]))
                            res = LCM[x][d] * st[j];
                        else
                            res = LCM[x][d];
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
                sum += tag[j];
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