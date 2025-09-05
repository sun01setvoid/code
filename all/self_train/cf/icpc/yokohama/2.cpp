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
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int l, r, id;
} qry[maxn];
int ans[maxn];
int n, a[maxn], q_cnt;
vii mp[maxn];
int t[maxn << 2], tag[maxn << 2];
bool cmp(oo &A, oo &B)
{
    return A.l < B.l;
}
void build(int node, int l, int r)
{
    t[node] = 1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
}
void down(int node)
{
    if (tag[node])
    {
        t[node << 1] = max(t[node << 1], tag[node]);
        t[node << 1 | 1] = max(t[node << 1 | 1], tag[node]);
        tag[node << 1] = max(tag[node << 1], tag[node]);
        tag[node << 1 | 1] = max(tag[node << 1 | 1], tag[node]);
        tag[node] = 0;
    }
}
void upd(int node, int l, int r, int ql, int qr, int v)
{
    if (l >= ql && r <= qr)
    {
        t[node] = max(t[node], v);
        tag[node] = max(tag[node], v);
        return;
    }
    int mid = (l + r) >> 1;
    down(node);
    if (mid >= ql)
        upd(node << 1, l, mid, ql, qr, v);
    if (mid < qr)
        upd(node << 1 | 1, mid + 1, r, ql, qr, v);
}
int q(int node, int l, int r, int p)
{
    if (l == r)
        return t[node];
    int mid = (l + r) >> 1;
    down(node);
    if (p <= mid)
        return q(node << 1, l, mid, p);
    else
        return q(node << 1 | 1, mid + 1, r, p);
}
void solve()
{
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mx = max(mx, a[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                mp[j].pb(i);
                if (a[i] / j != j)
                    mp[a[i] / j].pb(i);
            }
        }
    }
    vector<array<int, 3>> tmp;
    for (int i = 2; i <= mx; i++)
    {
        if (mp[i].size() < 2)
            continue;
        for (int j = 1; j < mp[i].size(); j++)
        {
            tmp.pb({mp[i][j - 1], mp[i][j], i});
        }
    }
    sort(tmp.begin(), tmp.end());
    cin >> q_cnt;
    for (int i = 1; i <= q_cnt; i++)
    {
        int l, r;
        cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    sort(qry + 1, qry + q_cnt + 1, cmp);
    int i, j;
    for (i = tmp.size() - 1, j = q_cnt; i >= 0; i--)
    {
        int pos1 = tmp[i][0], pos2 = tmp[i][1], val = tmp[i][2];
        cout << pos1 << " " << pos2 << " " << val << endl;
        while (j >= 1 && pos1 < qry[j].l)
        {
            ans[qry[j].id] = q(1, 1, n, qry[j].r);
            j--;
        }
        if (j < 1)
            break;
        upd(1, 1, n, pos2, n, val);
    }
    while (j >= 1)
    {
        ans[qry[j].id] = q(1, 1, n, qry[j].r);
        j--;
    }
    for (int i = 1; i <= q_cnt; i++)
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