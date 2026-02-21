// gcd相同则停，考虑归1化，gcd为1则停
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ull;
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
vector<vii> adj(maxn);
int n;
int cnt[maxn];
bool vis[maxn];
void solve()
{
    for (int i = 2; i <= n; i++)
        cnt[i] = 0;
    cin >> n;
    vii a(n + 1), ans(n + 1);
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d = __gcd(a[i], d);
    }
    for (int i = 1; i <= n; i++)
        a[i] /= d;
    vii ma;
    for (int i = 1; i <= n; i++)
    {
        vii ne;
        ans[i] = ans[i - 1];
        for (auto j : adj[a[i]])
        {
            cnt[j]++;
            if (cnt[j] != i)
                ans[i] = max(cnt[j], ans[i]);
            else if (!vis[j])
            {
                ne.pb(j);
                vis[j] = 1;
            }
        }
        for (auto j : ma)
        {
            if (cnt[j] != i)
                ans[i] = max(cnt[j], ans[i]), vis[j] = 0;
            else
                ne.pb(j);
        }
        ma = ne;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    for (int i = 2; i <= 2e5; i++)
    {
        for (int j = i; j <= 2e5; j += i)
        {
            adj[j].pb(i);
        }
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}