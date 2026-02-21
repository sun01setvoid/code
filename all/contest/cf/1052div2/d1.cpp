
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
    int l, r;
    cin >> l >> r;
    vii a(r + 1);
    int pw = 1;
    while (pw < r)
    {
        pw = pw * 2 + 1;
    }
    set<int> s;
    for (int i = l; i <= r; i++)
        s.insert(i);
    int ans = 0;
    for (int i = r; i >= l; i--)
    {
        while (!s.count(pw - i))
            pw >>= 1;
        a[i] = pw - i;
        s.erase(pw - i);
        ans += i | a[i];
    }
    cout << ans << endl;
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << endl;
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