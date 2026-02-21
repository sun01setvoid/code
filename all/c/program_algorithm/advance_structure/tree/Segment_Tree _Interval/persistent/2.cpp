#include <bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define ls (tr[p].l)
#define rs (tr[p].r)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 5000000; // 增加空间大小
const int maxm = 200010;
int rt[maxm], cnt, n, m;
struct node
{
    int sm;
    int l, r;
} tr[maxn];
int a[maxm];
int b[maxm], c[maxm];
void upd(int &p, int pre, int l, int r, int L, int val)
{
    p = ++cnt;
    tr[p].l = tr[pre].l;
    tr[p].r = tr[pre].r;
    tr[p].sm = tr[pre].sm;
    if (l == r)
    {
        tr[p].sm += val;
        return;
    }
    int mid = (l + r) / 2;
    if (L <= mid)
    {
        upd(ls, tr[pre].l, l, mid, L, val);
    }
    else
    {
        upd(rs, tr[pre].r, mid + 1, r, L, val);
    }
    tr[p].sm = tr[ls].sm + tr[rs].sm;
}
int qry(int p, int pre, int l, int r, int L)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (L <= tr[tr[p].l].sm - tr[tr[pre].l].sm)
        return qry(ls, tr[pre].l, l, mid, L);
    else
        return qry(rs, tr[pre].r, mid + 1, r, L - (tr[tr[p].l].sm - tr[tr[pre].l].sm));
}

void build(int &p, int l, int r)
{
    p = ++cnt;
    if (l == r)
    {
        tr[p].sm = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

void solve()
{
    cin >> n >> m;
    map<int, int> mp;
    int tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i], mp[b[i]] = 1;
    for (auto [x, ct] : mp)
    {
        mp[x] = ++tot;
        c[tot] = x;
    }
    for (int i = 1; i <= n; i++)
        a[i] = mp[b[i]];
    build(rt[0], 1, n);
    for (int i = 1; i <= n; i++)
    {
        upd(rt[i], rt[i - 1], 1, n, a[i], 1);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << c[qry(rt[r], rt[l - 1], 1, n, k)] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        solve();
    }
    return 0;
}