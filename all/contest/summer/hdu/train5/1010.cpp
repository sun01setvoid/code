#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 6e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};
int n, x[maxn];
void Raze()
{
    cin >> n; ld mi = n; int tot = 0;
    for (int i = 1; i <= n; i++)cin >> x[i];
    for (int i = n - 1; i >= 1; i--)
    {
        ld val1 = (ld)i * (1000 - x[i]) / 1000 + (ld)x[i] / 1000 * (mi + 20);
        if (val1 < mi)
        {
            mi = val1;
        }
    }
    cout << fixed << setprecision(10) << mi << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}