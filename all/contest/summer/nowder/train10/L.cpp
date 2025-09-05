#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, a[maxn]; pii t[maxn << 2]; int tag[maxn << 2];
void up(int node)
{
    pii l = t[node << 1], r = t[node << 1 | 1];
    if (l.fi >= r.fi)t[node] = l;
    else t[node] = r;
}
void build(int node, int l, int r)
{
    t[node] = { 0,-1 }; tag[node] = 0; if (l == r) { t[node].se = l; return; }int mid = (l + r) >> 1;
    build(node << 1, l, mid); build(node << 1 | 1, mid + 1, r); up(node);
}
void down(int node)
{
    if (tag[node])
    {
        t[node << 1].fi += tag[node]; t[node << 1 | 1].fi += tag[node];
        tag[node << 1] += tag[node]; tag[node << 1 | 1] += tag[node]; tag[node] = 0;
    }
}
void upd(int node, int l, int r, int ql, int qr, int v)
{
    if (l >= ql && r <= qr) { t[node].fi += v; tag[node] += v; return; }
    int mid = (l + r) >> 1; down(node);
    if (mid >= ql)upd(node << 1, l, mid, ql, qr, v);
    if (mid < qr)upd(node << 1 | 1, mid + 1, r, ql, qr, v);
    up(node);
}
pii q(int node, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)return t[node]; 
    pii ans = { -INF,-1 }; int mid = (l + r) >> 1;
    if (mid >= ql)
    {
        auto it = q(node << 1, l, mid, ql, qr);
        if (it.fi > ans.fi)ans = it;
    }
    if (mid < qr)
    {
        auto it = q(node << 1 | 1, mid + 1, r, ql, qr);
        if (it.fi > ans.fi)ans = it;
    }
    return ans;
}
void solve()
{

    cin >> n; int ma = 0; int ans = 0; int b1 = 1, b2 = 2;
    for (int i = 1; i <= n; i++)cin >> a[i];
    vii vis(ma + 1, 0); build(1, 1, n);
    vector<deque<int>>dq(ma+1);
    for (int i = 1; i <= n; i++)dq[a[i]].pb(i);
    for (int i = 1; i <= n; i++)
    {
        dq[a[i]].pop_front();
        if (!vis[a[i]])
        {
            if (!dq[a[i]].size())continue;
            int l = dq[a[i]].front();
            int r = dq[a[i]].back() - 1;
            if (l < r)
            {
                upd(1, 1, n, l, r, 1); vis[a[i]] = 1;
            }
        }
        else
        {
            if (dq[a[i]].size())
            {
                int l = i;
                int r = dq[a[i]].front() - 1;
                upd(1, 1, n, l, r, -1);
            }
        }
        auto it = q(1, 1, n, i, n);
        if (it.fi > ans)
        {
            ans = it.fi;
            b1 = i; b2 = it.se;
        }
    }
    b1++; b2++;
    cout << ans << endl;
    cout << b1 << " " << b2 << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}