#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
    repn(i, st, en) cerr << a[i] << ' '; \
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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
const int n = 2;
//-----------------------------------------------------//
map<array<int, n>, int> f;
int sg(array<int, n> &u)
{
    if (f.count(u))
        return f[u];
    set<int> T;
    for (int i = 0; i < n; i++)
    {
        array<int, n> v = u;
        if (u[i] != 0)
        {
            for (int j = 1; j <= min(u[i], 3ll); j++)
            {
                v[i] = u[i] - j;
                int t = sg(v);
                T.insert(t);
            }
        }
    }
    if (T.count(0))
        return f[u] = 1;
    else
        return f[u] = 0;
}
signed main()
{
    IOS;
    int _ = 1;
    f[{0, 0}] = 0;
    while (_--)
    {
        array<int, n> v = {10, 10};
        array<int, n> v1 = {8, 10};
        sg(v);
        for (auto i : f)
        {
            if (i.second == 0)
            {
                int ans = 0;
                for (auto x : i.first)
                    cout << x << " ", ans ^= x;
                cout << ans << endl;
            }
        }
    }
    return 0;
}