// P2293 yyy loves Maths II
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
signed main()
{
    long double ans = 0, a;
    while (cin >> a)
    {
        ans += a * 1000000;
    }
    cout << fixed << setprecision(5) << ans / 1000000 << endl;
    return 0;
}