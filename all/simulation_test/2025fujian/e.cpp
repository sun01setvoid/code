#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
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
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    n = 2 * n;
    vii a(n + 1), pre0(n + 1, 0), pre1(n + 1, 0);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        if (i & 1)
            pre1[i] += pre1[i - 1] + a[i], pre0[i] += pre0[i - 1];
        else
            pre0[i] += pre0[i - 1] + a[i], pre1[i] += pre1[i - 1];
    }
    int sum = pre0[n] + pre1[n];
    //debug(pre0[n]);
    //debug(pre1[n]);
    set<int> S[2];
    int ans = 0;
    S[0].insert(0);
    rep(i, 1, n)
    {
        int dif = pre1[n] - pre0[n] + 2 * (pre0[i] - pre1[i]);
        int d=INF;
        if (S[i & 1].size())
        {
            auto it = S[i & 1].lb(dif);
            if (it != S[i & 1].end())
                d = *it;
            if (it != S[i & 1].begin())
            {
                auto idx = --it;
                if (abs(dif - d) > abs(dif - *idx))
                    d = *idx;
            }
            ans = max(ans, min((dif - d + sum) / 2, (sum - (dif - d)) / 2));
        }
        S[i & 1].insert(2 * (pre0[i] - pre1[i]));
        //vdebug(S[0]);
        //vdebug(S[1]);
    }
    cout << ans << endl;
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