
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
// int vis[maxn];
// int sg(int n)
// {
//     if (n == 1)
//         return 0;
//     if (vis[n] != -1)
//         return vis[n];
//     for (int i = 2; i <= n - 1; i++)
//     {
//         if (n % i == 0)
//         {
//             int t = sg(n - i);
//             if (!t)
//                 return vis[n] = 1;
//         }
//     }
//     return vis[n] = 0;
// }
void solve()
{
    int n;
    cin >> n;
    if (n & 1 || ((n & (n - 1)) == 0 && __builtin_ctzll(n) & 1))
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
}
signed main()
{
    //     memset(vis, -1, sizeof vis);
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}