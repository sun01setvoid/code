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
int n, m, f[maxn], tr[maxn], pos[maxn];
vector<array<int, 4>> arr(maxn + 1);
//-----------------------------------------------------//
int lowbit(int x) { return x & -x; }
void add(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += val;
}
int qry(int x)
{
    int ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        ans += tr[i];
    return ans;
}
void merge(int l, int m, int r) // 0数值，1时序，2位置，3效果
{
    // l~m,m+1~r
    int p1, p2;
    for (p1 = l - 1, p2 = m + 1; p2 <= r; p2++)
    {
        while (p1 + 1 <= m && arr[p1 + 1][2] < arr[p2][2])
        {
            p1++;
            add(arr[p1][0], arr[p1][3]);
        }
        f[arr[p2][1]] += arr[p2][3] * (qry(n) - qry(arr[p2][0]));
    }
    for (int i = l; i <= p1; i++) // p1在当前要判断的位置的前一个
    {
        add(arr[i][0], -arr[i][3]);
    }
    for (p1 = m + 1, p2 = r; p2 >= m + 1; p2--)
    {
        while (p1 - 1 >= l && arr[p1 - 1][2] > arr[p2][2])
        {
            p1--;
            add(arr[p1][0], arr[p1][3]);
        }
        f[arr[p2][1]] += arr[p2][3] * qry(arr[p2][0] - 1);
    }
    for (int i = m; i >= p1; i--) // p1在当前要判断的位置的前一个
    {
        add(arr[i][0], -arr[i][3]);
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
void solve()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        pos[tmp] = i;
        arr[++cnt][0] = tmp;
        arr[cnt][1] = 0;
        arr[cnt][2] = i;
        arr[cnt][3] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int tmp;
        cin >> tmp;
        arr[++cnt][0] = tmp;
        arr[cnt][1] = i;
        arr[cnt][2] = pos[tmp];
        arr[cnt][3] = -1;
    }
    cdq(1, n + m);
    int ans = 0;
    for (int i = 0; i <= m - 1; i++)
    {
        ans += f[i];
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