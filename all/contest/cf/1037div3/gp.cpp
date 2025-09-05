#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 1e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int sum, pre, suf, mi;
    oo() :sum(-1), pre(-1), suf(-1), mi(INF) {}
    oo(int x) :sum(x), pre(x), suf(x), mi(x) {}
}t[maxn<<2];
int n, a[maxn]; int ans = 0; int med;
int min(int a, int b) { return a <= b ? a : b; }
oo merge(oo& l, oo& r)
{
    oo res; res.pre = max(l.pre, l.sum + r.pre); res.suf = max(r.suf, r.sum + l.suf);
    res.sum = l.sum + r.sum; res.mi = min(l.mi, r.mi); return res;
}

void build(int node, int l, int r)
{
    if (l == r) { t[node] = oo(); t[node].mi = a[l]; return; }
    int mid = (l + r) >> 1; build(node << 1, l, mid); build(node << 1 | 1, mid + 1, r); t[node] = merge(t[node << 1], t[node << 1 | 1]);
}
int q(int node, int l, int r, int sid, int val)
{
    if (val + t[node].sum >= 0)return t[node].mi;
    int mid = (l + r) >> 1; if (l == r)return INF;
    if (sid)
    {
        if (val + t[node << 1].sum >= 0)
        {
            return min(t[node << 1].mi, q(node << 1 | 1, mid + 1, r, sid, val + t[node << 1].sum));
        }
        else return q(node << 1, l, mid, sid, val);
    }
    else
    {
        if (val + t[node << 1 | 1].sum >= 0)
        {
            return min(t[node << 1 | 1].mi, q(node << 1, l, mid, sid, val + t[node << 1 | 1].sum));
        }
        else return q(node << 1 | 1, mid + 1, r, sid, val);
    }
}
void upd(int node, int l,int r,int pos)
{
    if (l == r) { t[node].sum = t[node].pre = t[node].suf = 1; return; }
    int mid = (l + r) >> 1;
    if (pos <= mid)upd(node << 1, l, mid, pos);
    else upd(node << 1 | 1, mid + 1, r, pos);
    t[node] = merge(t[node << 1], t[node << 1 | 1]);
    if (t[node].sum >= 0)ans = max(ans, med - t[node].mi);
    int suf = t[node << 1].suf;
    int sufm = q(node << 1 | 1, mid + 1, r, 1, suf);
    ans = max(ans, med - sufm);
    int pre = t[node << 1 | 1].pre;
    int prem = q(node << 1, l, mid, 0, pre);
    ans = max(ans, med - prem);
}
void Raze()
{
    cin >> n; vector<vii>pos(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i], pos[a[i]].pb(i);
    build(1, 1, n); ans = 0;
    for (int i = n; i >= 1; i--)
    {
        med = i; for (int j : pos[i])upd(1, 1, n, j);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}