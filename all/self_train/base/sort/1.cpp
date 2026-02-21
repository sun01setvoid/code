//[POI 2011] TEM-Temperature
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, tr[maxn];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i <= 1e5; i += lowbit(i))
    {
        tr[i] += v;
    }
}
int qry(int x)
{
    int ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
    {
        ans += tr[i];
    }
    return ans;
}
int cnt[maxn], a[maxn];
void solve()
{
    cin >> n;
    map<int, int> mp;    //注意交换没有无用的，每个数的交换数是有关他的逆序对
    unordered_map<int, int> to;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]] = 1;
    int idx = 1;
    for (auto t : mp)
    {
        to[t.fi] = idx++;
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i] += qry(1e5) - qry(to[a[i]]);
        add(to[a[i]], 1);
    }
    memset(tr, 0, sizeof tr);
    for (int i = n; i >= 1; i--)
    {
        cnt[i] += qry(to[a[i]] - 1);
        add(to[a[i]], 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += cnt[i] * (cnt[i] + 1) / 2;
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