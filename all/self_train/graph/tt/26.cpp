
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
//P3980 斐波那契
vii tmp;
void solve()
{
    int m;
    cin >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (a == 1 || b == 1)
        {
            cout << 1 << endl;
            continue;
        }
        while (a != b)
        {
            if (a > b)
                swap(a, b);
            auto idx = lower_bound(tmp.begin(), tmp.end(), b);
            --idx;
            b -= *idx;
        }
        cout << a << endl;
    }
}
signed main()
{
    int f1 = 1, f2 = 1;
    int mx = 1e12;
    while (f2 <= mx)
    {
        tmp.pb(f2);
        int cur = f1 + f2;
        f1 = f2, f2 = cur;
    }
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}