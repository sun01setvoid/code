#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int lc[maxn << 2], rc[maxn << 2], ad[maxn << 2], t[maxn << 2];
void up(int node)
{
    t[node] = max(t[node << 1], t[node << 1 | 1]) + ad[node];
}
void maintain(int u, int v)
{
    ad[u] += v;
    t[u] += v;
}
void build(int node, int l, int r)
{
    lc[node] = l;
    rc[node] = r;
    ad[node] = t[node] = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    up(node);
}
void upd(int node, int l, int r, int v)
{
    if (lc[node] >= l && rc[node] <= r)
    {
        maintain(node, v);
        return;
    }
    int mid = (lc[node] + rc[node]) >> 1;
    if (mid >= l)
        upd(node << 1, l, r, v);
    if (mid < r)
        upd(node << 1 | 1, l, r, v);
    up(node);
}
int q(int node, int l, int r)
{
    if (lc[node] >= l && rc[node] <= r)
        return t[node];
    int mid = (lc[node] + rc[node]) >> 1, ans = 0;
    if (mid >= l)
        ans = max(ans, q(node << 1, l, r));
    if (mid < r)
        ans = max(ans, q(node << 1 | 1, mid + 1, r));
    up(node);
    return ans;
}
struct seg
{
    int x, l, r, w;
    seg(int x = 0, int l = 0, int r = 0, int w = 0)
    {
        this->x = x;
        this->l = l;
        this->r = r;
        this->w = w;
    }
};
vector<seg> g;
bool cmp(seg &a, seg &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.w < b.w;
}
int n, k;
struct oo
{
    int x, y, v;
} a[maxn];
void Raze()
{
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].v;
    }
    for (int h = 1; h * h <= k; h++)
    {
        int w = k / h;
        g.clear();
        for (int i = 1; i <= n; i++)
        {
            g.pb({a[i].x, a[i].y, min(n + 2, a[i].y + h - 1), a[i].v});
            g.pb({min(a[i].x + w, n + 2), a[i].y, min(n + 2, a[i].y + h - 1), -a[i].v});
        }
        build(1, 1, n + 2);
        int ans = 0;
        sort(g.begin(), g.end(), cmp);
        for (int i = 0; i < g.size(); i++)
        {
            upd(1, g[i].l, g[i].r, g[i].w);
            ans = max(ans, t[1]);
        }
        res = max(res, ans);
    }
    for (int w = 1; w * w <= k; w++)
    {
        int h = k / w;
        g.clear();
        for (int i = 1; i <= n; i++)
        {
            g.pb({a[i].x, a[i].y, min(n + 2, a[i].y + h - 1), a[i].v});
            g.pb({min(a[i].x + w, n + 2), a[i].y, min(n + 2, a[i].y + h - 1), -a[i].v});
        }
        build(1, 1, n + 2);
        int ans = 0;
        sort(g.begin(), g.end(), cmp);
        for (int i = 0; i < g.size(); i++)
        {
            upd(1, g[i].l, g[i].r, g[i].w);
            ans = max(ans, t[1]);
        }
        res = max(res, ans);
    }
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}