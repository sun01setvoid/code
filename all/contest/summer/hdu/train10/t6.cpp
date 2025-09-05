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
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
ll n, m, a[maxn], tag[maxn], b[maxn];
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll min(int a, int b) { return a <= b ? a : b; }
ll max(int a, int b) { return a >= b ? a : b; }
void solve()
{
    cin >> n >> m;
    vector<ll> pr(501, 0);
    vii cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cnt[i] = n / i;
    for (int i = 1; i <= n; i++)
        tag[i] = 0;
    vector<vii> fac(n + 1);
    // vector<vii>LCM(n+1,vii(201));
    vector<vii> LCM1(501, vii(501));
    vector<vii> LCM;
    set<int> may;
    vii id;
    vector<array<int, 3>> q;
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            LCM1[i][j] = lcm(i, j);
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
        cin >> a[i], b[i] = a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(n, 500ll); j++)
        {
            if (i % j == 0)
                pr[j] += a[i];
        }
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1 || op == 2)
        {
            int x, k;
            cin >> x >> k;
            q.pb({op, x, k});
            if (op == 1 && x > 500)
            {
                may.insert(x);
            }
        }
        else
        {
            int x;
            cin >> x;
            q.pb({op, x, 0});
        }
    }
    id.resize(n + 1);
    int tot = 0;
    LCM.resize(may.size());
    for (int v : may)
    {
        id[v] = tot++;
        LCM[tot - 1].resize(501);
        for (int j = 1; j <= 500; j++)
        {
            LCM[tot - 1][j] = lcm(v, j);
        }
    }
    for (int i = 0; i < q.size(); i++)
    {
        int op = q[i][0];
        if (op == 1)
        {
            ll x = q[i][1], k = q[i][2];
            for (int j = x; j <= n; j += x)
                b[j] += k;
            if (x <= 500)
            {
                for (int j = 1; j <= min(n, 500ll); j++)
                {
                    int cm = LCM1[x][j];
                    pr[j] += k * (n / cm);
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
                for (int j = 1; j <= min(n, 500ll); j++)
                {
                    int cm;
                    int idx = id[x];
                    cm = LCM[idx][j];
                    pr[j] += k * (n / cm);
                }
            }
        }
        else if (op == 2)
        {
            ll x = q[i][1], k = q[i][2];
            for (int j : fac[x])
            {
                b[j] += k;
                a[j] += k;
                if (j <= 500)
                {
                    int yu = x / j;
                    pr[j] += k * fac[yu].size();
                }
            }
        }
        else if (op == 3)
        {
            ll x = q[i][1];
            int ans = 0;
            for (int j = x; j <= n; j += x)
                ans += b[j];
            if (x <= 500 && pr[x] != ans)
                cout << "Wrong:" << op << " " << x << endl;
            else
            {
                ll sum = 0;
                ll tagsum = 0;
                for (int j = 1; j * x <= n; j++)
                {
                    sum += a[j * x];
                }
                for (int j : fac[x])
                {
                    if (j <= 500)
                        tagsum += tag[j];
                }
                sum += 1ll * cnt[x] * (tagsum);
                if (sum != ans)
                    cout << "Wrong:" << op << " " << x << endl;
            }
        }
        else
        {
            ll x = q[i][1];
            int ans = 0;
            ll sum = 0;
            for (int j : fac[x])
            {
                ans += b[j];
                sum += a[j];
                sum += tag[j];
            }
            if (sum != ans)
                cout << "Wrong:" << op << " " << x << endl;
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