// P8743 异或数列
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
//偶数位拿不影响
void solve()
{
    int n;
    vii cnt(21);
    cin >> n;
    int res = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        res^=x;
        for (int j = 19; j >= 0; j--)
        {
            if (x >> j & 1)
                cnt[j]++;
        }
    }
    if (!res)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (cnt[i] % 2 == 0)
            continue;
        else if (cnt[i] == 1)
            cout << 1 << endl;
        else if ((n - cnt[i]) & 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
        break;
    }
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