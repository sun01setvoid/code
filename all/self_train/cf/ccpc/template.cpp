#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
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
    int n = rand() % 50 + 10, k = rand() % 1000 + 10, q = rand() % 100 + 20;
    cout << n << " " << k << " " << q << endl;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++)
    {
        int x = rand() % k + 1, y = rand() % k + 1;
        a.pb({x, y});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cout << a[i].fi << " " << a[i].se << endl;
    }
    while (q--)
    {
        int x = rand() % 100 + 1, y = rand() % n + 1;
        cout << x << " " << y << endl;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    srand(time(0));
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}