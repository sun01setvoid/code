#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
bool vis[maxn];
bool ans[maxn];
int n, k;
void solve()
{
    // cin >> n >> k;
    int cnt = n;
    int st = 1;
    while (cnt > 1)
    {
        for (int i = st; i <= n; i++)
        {
            if (!vis[i])
            {
                st = i;
                cnt--;
                vis[i] = 1;
                break;
            }
        }
        int sum = 0;
        for (int i = st + 1; i <= n; i++)
        {
            if (!vis[i])
                sum++;
            if (sum == k)
            {
                vis[i] = 1;
                sum = 0;
                cnt--;
                if (cnt == 1)
                    break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && !ans[i])
        {
            cout << i << endl;
            ans[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        for (int i = 2; i <= 1000; i++)
        {
            for (int j = 4; j <= 4; j++)
            {
                n = i, k = j;
                solve();
            }
        }
    }
    return 0;
}