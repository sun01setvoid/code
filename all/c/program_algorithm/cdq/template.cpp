#include <bits/stdc++.h>
using namespace std;
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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, k, f[maxn], tr[maxn];
vector<array<int, 4>> arr(maxn + 1);
//-----------------------------------------------------//
int lowbit(int x) { return x & -x; }
void add(int x, int val)
{
    for (int i = x; i <= k; i += lowbit(i))
        tr[i] += val;
}
int qry(int x)
{
    int ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        ans += tr[i];
    return ans;
}
void merge(int l, int m, int r)
{
    // l~m,m+1~r
    int p1, p2;
    for (p1 = l - 1, p2 = m + 1; p2 <= r; p2++)
    {
        while (p1 + 1 <= m && arr[p1 + 1][2] <= arr[p2][2])
        {
            p1++;
            add(arr[p1][3], 1);
        }
        f[arr[p2][0]] += qry(arr[p2][3]);
    }
    for (int i = l; i <= p1; i++) // p1在当前要判断的位置的前一个
    {
        add(arr[i][3], -1);
    }
    sort(arr.begin() + l, arr.begin() + r + 1, [](array<int, 4> &a, array<int, 4> &b)
         { return a[2] < b[2]; });
}
void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    cdq(l, mid);
    cdq(mid + 1, r);
    merge(l, mid, r);
}
void prepare() // 处理相同的数据
{
    sort(arr.begin() + 1, arr.begin() + n + 1, [](array<int, 4> &a, array<int, 4> &b)
         {
        if (a[1]==b[1]){
            if (a[2]==b[2]) return a[3]<b[3];
            return a[2]<b[2];
        }return a[1]<b[1]; });
    int cnt = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (arr[i][1] == arr[i + 1][1] && arr[i][2] == arr[i + 1][2] && arr[i][3] == arr[i + 1][3])
            cnt++, f[arr[i][0]] += cnt;
        else
            cnt = 0;
    }
}
void solve()
{
    cin >> n >> k;
    vii ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {i, a, b, c};
    }
    prepare();
    cdq(1, n);
    for (int i = 1; i <= n; i++)
    {
        ans[f[i]]++;
    }
    for (int i = 0; i <= n - 1; i++)
        cout << ans[i] << endl;
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