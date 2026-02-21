// gcd相同则停，考虑归1化，gcd为1则停
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define pb push_back
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int cnt[maxn];
int pre[maxn];
int a[maxn];
void solve()
{
    memset(cnt, 0, sizeof cnt);
    int n, y;
    cin >> n >> y;
    int ma = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++, ma = max(ma, a[i]);
    ma += 1;
    for (int i = 1; i <= ma; i++)
    {
        pre[i] = pre[i - 1] + cnt[i];
    }
    int ans = LONG_LONG_MIN;
    for (int i = 2; i <= ma; i++)
    {
        int ct = 0, num = 0;
        for (int j = 1; j <= ma; j++)
        {
            int l = (j - 1) * i + 1, r = j * i;
            if (l >= ma)
                break;
            r = min(ma, r);
            ct += max(0ll, pre[r] - pre[l - 1] - cnt[j]);
            num += (pre[r] - pre[l - 1]) * j;
        }
        ans = max(num - ct * y, ans);
    }
    cout << ans << endl;
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