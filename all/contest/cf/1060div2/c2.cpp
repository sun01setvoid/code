#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 4e5 + 5;
const int maxm = 1e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
bool st[maxn];
vector<vii> g(maxn);
int cnt[maxn];
void solve()
{
    int n;
    cin >> n;
    vii a(n + 1), b(n + 1);
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (auto x : g[a[i]])
        {
            cnt[x]++;
            if (cnt[x] >= 2)
                ans = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vii ord(n + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin() + 1, ord.begin() + n + 1, [&](int x, int y) -> bool
         { return b[x] < b[y]; });
    ans = min(b[ord[1]] + b[ord[2]], ans);
    for (int i = 1; i <= n; i++)
    {
        if (ans <= b[ord[i]])
            break;
        for (auto x : g[a[ord[i]]])
            cnt[x]--;
        for (auto x : g[a[ord[i]] + 1])
        {
            if (cnt[x])
            {
                ans = min(ans, b[ord[i]]);
            }
        }
        for (auto x : g[a[ord[i]]])
            cnt[x]++;
    }
    int idx = ord[1]; // 如果有两个相同的，那么2次的已经算过了，最优
    set<int> s;
    for (int i = 2; i <= n; i++)
    {
        for (auto x : g[a[ord[i]]])
        {
            s.insert(x);
        }
    }
    for (auto x : s)
    {
        int tm = x - (a[idx] % x);
        if (tm == x)
            tm = 0;
        ans = min(ans, tm * b[idx]);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : g[a[i]])
        {
            cnt[x]--;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= 200002; i++)
    {
        if (!st[i])
        {
            for (int j = i; j <= 200002; j += i)
            {
                g[j].pb(i);
                st[j] = 1;
            }
        }
    }
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}