#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define debug(x) cerr << #x << '=' << (x) << endl
#define endl '\n'
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
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
__int128 fp(int a, int b)
{
    __int128 res = 1;
    while (b)
    {
        if (b % 2)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
int get(__int128 n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 2;
        n /= 2;
    }
    return sum;
}
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int val = abs(a - b);
    if (val == 0)
    {
        cout << 1 << endl;
        return;
    }
    if (val >= 100)
    {
        int ans = 1;
        __int128 now = 1;
        for (int i = 1; i <= k; i++)
        {
            now = now * (k + 1 - i) / i;
            ans += get(now);
        }
        cout << ans << endl;
    }
    else
    {
        int ans = 1;
        __int128 now = 1;
        __int128 p = 1;
        for (int i = 0; i < val; i++)
            p *= 2;
        int pr = 0;
        for (int i = 1; i <= k; i++)
        {
            now = now * (k + 1 - i) / i;
            int nt = now % p;
            ans += get(now + pr);
            pr = now / p;
        }
        ans += get(pr);
        cout << ans << endl;
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