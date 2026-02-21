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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 4e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n;
int a[maxn], b[maxn];
int cal(int x, int y)
{
    if (x > y)
        return 0;
    int num = 0;
    for (int i = n, l = 1, r = 1; i >= 1; i--)
    {
        while (l <= n && b[i] + b[l] < x)
            l++;
        while (r <= n && b[i] + b[r] <= y)
            r++;
        num += (r - l - (l <= i && i < r));
    }
    return (num / 2) & 1;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i <= 25; i++)
    {
        for (int j = 1; j <= n; j++)
            b[j] = a[j] % (1 << i + 1);
        sort(b + 1, b + n + 1);
        int cnt = cal(1 << i, (1 << i + 1) - 1) ^ cal(3 * (1 << i), ((1 << i + 1) - 1) * 2);
        ans += cnt * (1 << i);
    }
    cout << ans << endl;
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