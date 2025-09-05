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
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
map<int, int> mp;
void solve()
{
    int a, b;
    cin >> a >> b;
    if ((a + b) & 1)
    {
        cout << -1 << endl;
    }
    else
    {
        if (a == b)
            cout << 1 << endl;
        else if (a > b)
        {
            if (a % b == 0 && mp.count(a / b + 1))
                cout << mp[a / b + 1] << endl;
        }
        else if (b % a == 0 && mp.count(b / a + 1))
            cout << mp[b / a + 1] << endl;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    mp[1] = 0;
    int st = 1;
    for (int i = 1; i <= 32; i++)
    {
        st = st * 2;
        mp[st] = i;
    }
    while (_--)
    {
        solve();
    }
    return 0;
}