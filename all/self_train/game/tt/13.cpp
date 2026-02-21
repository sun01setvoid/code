
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

void solve()
{
    int n;
    cin >> n;
    int cnt1 = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        res ^= x;
        if (x == 1)
            cnt1++;
    }
    if (cnt1 == n)
    {
        if (res)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    else
    {
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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