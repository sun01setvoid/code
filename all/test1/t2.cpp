#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n"
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
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
map<pii, int> f;
int sg(const pii &u)
{
    if (f.count(u))
        return f[u];
    set<int> T;
    for (int i = 1; i <= u.fi; i++)
    {
        for (int k = 0; k * i <= u.se; k++)
        {
            int t = sg({u.fi - i, u.se - i * k});
            T.insert(t);
        }
    }
    for (int i = 1; i <= u.se; i++)
    {
        for (int k = 0; k * i <= u.fi; k++)
        {
            int t = sg({u.fi - i * k, u.se - i});
            T.insert(t);
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
    // cin >> _;
    f[{0, 0}] = 0;
    while (_--)
    {
        pii v = {100,100};
        int t = sg(v);
        int cnt=0;
        for (auto i : f)
        {
            // int ans=0;
            if (i.se == 0)
            {
                cnt++;
            }
            // cout<<ans<<endl;
        }
        cout<<cnt;
    }
    return 0;
}