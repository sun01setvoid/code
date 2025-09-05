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
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> tmp;
    rep(i, 1, m)
    {
        int l, r;
        cin >> l >> r;
        tmp.pb({l, r});
    }
    sort(tmp.begin(), tmp.end());
    vii ans(2 * n + 1, -1);
    int pos = 0, cnt = 0;
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        int l = tmp[i].fi, r = tmp[i].se;
        // debug(l);
        if (pos == 0)
            pos = l, ans[pos] = 1, cnt++;
        else
        {
            if (r < pos)
                pos = l, ans[pos] = 1, cnt++;
        }
    }
    if (cnt > n)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= 2 * n; i++)
        {
            if (ans[i] == 1)
                continue;
            else
            {
                if (cnt < n)
                    ans[i] = 1, cnt++;
            }
        }
        int sum = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            sum = sum + ans[i];
            if (sum < 0)
            {
                cout << -1 << endl;
                return;
            }
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (ans[i] == 1)
                cout << "(";
            else
                cout << ")";
        }
    }
    cout << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        // debug(_);
        solve();
    }
    return 0;
}