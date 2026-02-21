#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define IOS ios::sync_with_stdio(0);
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
int a[maxn];
void solve()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int en = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > p)
        {
            en = i - 1;
            break;
        }
    }
    int ans = 0;
    for (int i = 1, j = en; i <= en; i++)
    {
        while (i < j && a[i] + a[j] > p)
            j--;
        ans += min(en - j, en - i);
    }
    for (int i = en + 1, j = i + 1; i <= n - 1; i++)
    {
        while (j <= n && p + a[i] > a[j])
            j++;
        ans += (j - 1 - i);
    }
    for (int i = 1, j = en + 1; i <= en; i++)
    {
        while (j <= n && a[i] + p > a[j])
            j++;
        ans += (j - en - 1);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}