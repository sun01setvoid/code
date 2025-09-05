#include <bits/stdc++.h>
using namespace std;
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
typedef long long ll;
ll compute(vector<ll> &basis)
{
    int rank = 0;
    for (int i = 60; i >= 0; --i)
    {
        int pivot = -1;
        for (int j = rank; j < basis.size(); ++j)
        {
            if ((basis[j] >> i) & 1)
            {
                pivot = j;
                break;
            }
        }
        if (pivot == -1)
            continue;
        swap(basis[rank], basis[pivot]);
        for (int j = 0; j < basis.size(); ++j)
        {
            if (j != rank && ((basis[j] >> i) & 1))
            {
                basis[j] ^= basis[rank];
            }
        }
        rank++;
    }
    ll res = 0;
    for (int i = 0; i < rank; ++i)
    {
        if ((res ^ basis[i]) > res)
        {
            res ^= basis[i];
        }
    }
    return res;
}
int n;
vector<ll> a(51);
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        cin >> n;
        ll ans = 0;
        rep(i, 1, n)
        {
            cin >> a[i];
            ans = max(ans, a[i]);
        }
        vector<vector<vector<ll>>> p(3);
        if (n >= 1)
        {
            vector<ll> g;
            g.pb(a[1]);
            p[0].pb(g);
        }
        if (n >= 2)
        {
            vector<ll> g;
            g.pb(a[2]);
            p[1].pb(g);
        }
        if (n >= 3)
        {
            vector<ll> g;
            g.pb(a[1]);
            g.pb(a[3]);
            p[2].pb(g);
            ans = max(ans, a[1] ^ a[3]);
        }
        if (n <= 3)
        {
            cout << ans << endl;
            continue;
        }
        for (int i = 4; i <= n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (auto &base : p[j])
                {
                    vector<ll> g = base;
                    g.pb(a[i]);
                    p[2].pb(g);
                }
            }
            p[0] = move(p[1]);
            p[1] = move(p[2]);
            p[2].clear();
        }
        if (n >= 1)
        {
            for (auto &base : p[1])
            {
                ll res = compute(base);
                ans = max(ans, res);
            }
        }
        if (n >= 2)
        {
            for (auto &base : p[0])
            {
                ll res = compute(base);
                ans = max(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}