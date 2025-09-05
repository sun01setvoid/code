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
const int maxn = 5e5 + 10;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int l, r, c;
}a[maxn];
bool cmp(oo& a, oo& b) { return a.l < b.l; }
int n, m, t[maxn << 2], tag[maxn << 2];
int min(int a, int b) { return a <= b ? a : b; }
void build(int node, int l, int r)
{
    t[node] = 0, tag[node] = 0;
    if (l == r)return; int mid = (l + r) >> 1;
    build(node << 1, l, mid); build(node << 1 | 1, mid + 1, r);
}
void down(int node)
{
    if (tag[node])
    {
        t[node << 1] += tag[node]; t[node << 1 | 1] += tag[node];
        tag[node << 1] += tag[node]; tag[node << 1 | 1] += tag[node]; tag[node] = 0;
    }
}
void upd(int node, int l, int r, int ql, int qr,int val)
{
    if (l >= ql && r <= qr) { t[node] += val; tag[node] += val; return; }
    int mid = (l + r) >> 1; down(node);
    if (mid >= ql)upd(node << 1, l, mid, ql, qr, val);
    if (mid < qr)upd(node << 1 | 1, mid + 1, r, ql, qr, val);
    t[node] = min(t[node << 1], t[node << 1 | 1]);
}
int q(int node, int l, int r, int pos)
{
    if (l == r)return t[node]; int mid = (l + r) >> 1; down(node);
    if (pos <= mid)return q(node << 1, l, mid, pos);
    else return q(node << 1 | 1, mid + 1, r, pos);
}
void Raze()
{
    cin >> n >> m; int tot = 0; map<int, int>mp;
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].c;
    for (int i = 1; i <= m; i++)
    {
        if(a[i].l==1)mp[a[i].l] = 1;
        else { a[i].l++; mp[a[i].l] = 1; }
        mp[a[i].r] = 1;
    }
    for (auto& it : mp)it.so = ++tot;
    for (int i = 1; i <= m; i++)
    {
        a[i].l = mp[a[i].l]; a[i].r = mp[a[i].r];
    }
    if (mp[1] != 1) { cout << "0" << endl; return; }
    build(1, 1, tot);
    for (int i = 1; i <= m; i++)
    {
        //debug(a[i].l); debug(a[i].r); debug(a[i].c);
        if (a[i].l > a[i].r)continue;
        upd(1, 1, tot, a[i].l, a[i].r, a[i].c);
    }
    cout << t[1] << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}