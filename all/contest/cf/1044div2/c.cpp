#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1000 + 50;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vii> g;
void solve()
{
    int n, k;
    cin >> n;
    g.assign(n + 1, vii());
    for (int i = 1; i <= n; i++)
    {
        cout << "? " << i << ' ' << n << ' ';
        for (int j = 1; j <= n; j++)
            cout << j << ' ';
        cout << endl;
        cout.flush();
        cin >> k;
        g[k].pb(i);
    }
    
    vii res;
    for (int i = n; i >= 1; i--)
    {
        if (!g[i].empty())
        {
            if (res.empty())
            {
                res.pb(g[i][0]);
                continue;
            }
            for (auto x : g[i])
            {
                cout << "? " << res.back() << ' ' << 2 << ' ' << res.back() << ' ' << x << endl;
                cout.flush();
                cin >> k;
                if (k == 2)
                {
                    res.pb(x);
                    break;
                }
            }
        }
    }
    
    cout << "! " << res.size() << ' ';
    for (auto x : res)
        cout << x << ' ';
    cout << endl;
    cout.flush();
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