#include <bits/stdc++.h>
#define int unsigned long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define ls (lc << 1)
#define rs (lc << 1 | 1)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 4e5;
// 把查询改为[x,y+1)
struct node
{
    int sm;
    int ad;
} tr[maxn << 2];
int a[maxn];
int n, m;
void up(int lc) { tr[lc].sm = tr[ls].sm + tr[rs].sm; }
void down(int lc, int ll, int rr)
{
    tr[ls].sm = tr[ls].sm + tr[lc].ad * ll;
    tr[rs].sm = tr[rs].sm + tr[lc].ad * rr;
    tr[ls].ad = tr[ls].ad + tr[lc].ad;
    tr[rs].ad = tr[rs].ad + tr[lc].ad;
    tr[lc].ad = 0;
}
void upd(int lc, int l, int r, int L, int R, int val)
{
    if (R < l || L > r)
        return;
    if (L <= l && r <= R)
    {
        tr[lc].ad = tr[lc].ad + val;
        tr[lc].sm = tr[lc].sm + (a[r + 1] - a[l]) * val;
        return;
    }
    int mid = (l + r) / 2;
    down(lc, a[mid + 1] - a[l], a[r + 1] - a[mid + 1]);
    if (L <= mid)
        upd(ls, l, mid, L, R, val);
    if (mid + 1 <= R)
        upd(rs, mid + 1, r, L, R, val);
    up(lc);
}
int qry(int lc, int l, int r, int L, int R)
{
    if (R < l || L > r)
        return 0;
    if (L <= l && r <= R)
    {
        return tr[lc].sm;
    }
    int mid = (l + r) / 2;
    int ans = 0;
    down(lc, a[mid + 1] - a[l], a[r + 1] - a[mid + 1]);
    if (L <= mid)
        ans = ans + qry(ls, l, mid, L, R);
    if (R >= mid + 1)
        ans = ans + qry(rs, mid + 1, r, L, R);
    return ans;
}
void build(int lc, int l, int r)
{
    tr[lc].ad = 0;
    if (l == r)
    {
        tr[lc].sm = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    up(lc);
}
pair<pii, pii> q[maxn];
void solve()
{
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            q[i] = pair<pii, pii>(pii(op, k), pii(x, y + 1));
            mp[x] = 1, mp[y + 1] = 1;
        }
        else
        {
            cin >> x >> y;
            q[i] = pair<pii, pii>(pii(op, k), pii(x, y + 1));
            mp[x] = 1, mp[y + 1] = 1;
        }
    }
    int tot = 0;
    for (auto &cu : mp)
    {
        a[++tot] = cu.fi;
        cu.se = tot;
    }
    a[tot + 1] = a[tot] + 1;
    build(1, 1, tot);
    for (int i = 1; i <= m; i++)
    {
        int op = q[i].fi.fi, k = q[i].fi.se;
        int x = q[i].se.fi, y = q[i].se.se;
        if (op == 1)
        {
            upd(1, 1, tot, mp[x], mp[y] - 1, k);
        }
        else
        {
            int t = qry(1, 1, tot, mp[x], mp[y] - 1);
            int ans = (x + y - 1) * (y - x) / 2;
            cout << ans + t << endl;
        }
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