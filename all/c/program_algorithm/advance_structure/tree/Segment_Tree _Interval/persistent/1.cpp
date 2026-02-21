#include <bits/stdc++.h>
#define debug(x) cerr << #x << '=' << (x) << endl
#define ls (tr[p].l)
#define rs (tr[p].r)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 25000000; // 增加空间大小
const int maxm = 1000010;
int rt[maxm], cnt, n, m;
struct node
{
    int sm;
    int l, r;
} tr[maxn];
int a[maxm];

void upd(int &p, int pre, int l, int r, int L, int val)
{
    p = ++cnt;
    tr[p].l = tr[pre].l;
    tr[p].r = tr[pre].r;
    tr[p].sm = tr[pre].sm;
    if (l == r)
    {
        tr[p].sm = val;
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
    tr[p].sm=tr[ls].sm+tr[rs].sm; //单点查询，可以不要
}
int qry(int p, int l, int r, int L)
{
    if (l == r)
    {
        return tr[p].sm;
    }
    int mid = (l + r) / 2;
    if (L <= mid)
        return qry(ls, l, mid, L);
    else
        return qry(rs, mid + 1, r, L);
}

void build(int &p, int l, int r)
{
    p = ++cnt;
    if (l == r)
    {
        tr[p].sm = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(rt[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int v;
        cin >> v;
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, c;
            cin >> p >> c;
            upd(rt[i], rt[v], 1, n, p, c);
        }
        else
        {
            int p;
            cin >> p;
            rt[i] = rt[v];
            cout << qry(rt[i], 1, n, p) << endl;
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