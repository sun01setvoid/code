#include <iostream>
#include <math.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int a, b;
void solve()
{
    if (a > b)
        swap(a, b);
    int k = b - a;
    if (a == (int)(k * (sqrt(5) + 1) / 2))
        cout << 0 << endl;
    else
        cout << 1 << endl;
}
signed main()
{

    while (cin >> a >> b)
    {
        solve();
    }
    return 0;
}