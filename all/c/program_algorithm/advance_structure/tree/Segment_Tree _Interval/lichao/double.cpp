#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
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
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 1e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
const int MOD1 = 39989;
const int MOD2 = 1e9;
int cmp(ld x, ld y)
{
    if (x - y > eps)
        return 1;
    if (y - x > eps)
        return -1;
    return 0;
}
struct oo
{
    ld k, b;
} p[maxn];
int s[maxn], cnt;
ld cal(int id, int d) { return p[id].b + p[id].k * d; }
void add(int x0, int y0, int x1, int y1)
{
    cnt++;
    if (x0 == x1)
        p[cnt].k = 0, p[cnt].b = max(y0, y1);
    else
        p[cnt].k = 1.0 * (y1 - y0) / (x1 - x0), p[cnt].b = y0 - p[cnt].k * x0;
}
void upd(int rt, int l, int r, int u)
{
    int &v = s[rt], mid = (l + r) >> 1;
    int bmid = cmp(cal(u, mid), cal(v, mid));
    if (bmid == 1 || (!bmid && u < v))
        swap(u, v);
    // if (bmid == -1 || (!bmid && u < v)) swap(u, v);
    int bl = cmp(cal(u, l), cal(v, l)), br = cmp(cal(u, r), cal(v, r));
    if (bl == 1 || (!bl && u < v))
        upd(rt << 1, l, mid, u);
    if (br == 1 || (!br && u < v))
        upd(rt << 1 | 1, mid + 1, r, u);
    /*
    if (bl == -1 || (!bl && u < v)) upd(rt<<1, l, mid, u);
    if (br == -1 || (!br && u < v)) upd(rt<<1|1, mid+1, r, u);
    */
}
void update(int node, int l, int r, int ql, int qr, int u)
{
    if (l >= ql && r <= qr)
    {
        upd(node, l, r, u);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(node << 1, l, mid, ql, qr, u);
    if (mid < qr)
        update(node << 1 | 1, mid + 1, r, ql, qr, u);
}
pair<ld, int> qmax(pair<ld, int> x, pair<ld, int> y)
{
    if (cmp(x.fi, y.fi) == -1)
        return y;
    else if (cmp(x.fi, y.fi) == 1)
        return x;
    else
        return x.so < y.so ? x : y;
}
/*
pair<ld,int> qmin(pair<ld,int> x, pair<ld,int> y)
{
    if (cmp(x.first, y.first) ==  1) return y;
    if (cmp(x.first, y.first) == -1) return x;
    return x.second < y.second ? x : y;
}
*/
pair<ld, int> q(int node, int l, int r, int d)
{
    if (r < d || d < l)
        return {0, 0};
    int mid = (l + r) >> 1;
    ld res = cal(s[node], d);
    if (l == r)
        return {res, s[node]};
    return qmax({res, s[node]}, qmax(q(node << 1, l, mid, d), q(node << 1 | 1, mid + 1, r, d)));
} // 添加直线

//add(x0, y0, x1, y1);

//update(1, 1, ma, x0, x1, cnt);

// 输出x=多少时y最大线段编号

//cout << q(1, 1, ma, x).second << endl;

// fi为y最大

/*
初始化：
最小值版本：

cnt=0,add(0,INF,1,INF),++cnt,update(1,L,R,L,R,cnt);

最大值版本：

cnt=0;add(0,-INF,1,-INF);++cnt;update(1,L,R,L,R,cnt);
*/