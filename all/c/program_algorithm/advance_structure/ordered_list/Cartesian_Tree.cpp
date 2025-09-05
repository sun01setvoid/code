#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e7 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
int arr[maxn], ls[maxn], rs[maxn], stk[maxn];
int n;
//-----------------------------------------------------//
void build()
{
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = top;
        while (pos > 0 && arr[stk[pos]] > arr[i])
        {
            pos--;
        }
        if (pos > 0)
            rs[stk[pos]] = i;
        if (pos < top)
        {
            ls[i] = stk[pos + 1];
        }
        stk[++pos] = i;
        top = pos;
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    ll ans1 = 0, ans2 = 0;
    build();
    for (int i = 1; i <= n; i++)
    {
        ans1 ^= 1LL * i * (ls[i] + 1);
        ans2 ^= 1LL * i * (rs[i] + 1);
    }
    cout << ans1 << " " << ans2 << endl;
    return;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}