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
int n;
int a[maxn], b[maxn];
int ma1[maxn], ma2[maxn];
int stk[maxn], top;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ma1[i] = -1;
    for (int i = 1; i <= n; i++)
        cin >> b[i], ma2[i] = -1;
    top = -1;
    for (int i = 1; i <= n; i++)
    {
        while (top != -1 && a[stk[top]] < a[i])
            top--;
        if (top != -1 && a[stk[top]] >= a[i])
            ma1[i] = stk[top];
        if (top != -1 && a[stk[top]] >= b[i])
            ma2[i] = stk[top];
        stk[++top] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
            ans += i * (n - i + 1);
        else if (a[i] > b[i])
        {
            if (ma1[i] == -1)
                continue;
            else
                ans += ma1[i] * (n - i + 1);
        }
        else
        {
            if (ma2[i] == -1)
                continue;
            else
                ans += ma2[i] * (n - i + 1);
        }
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