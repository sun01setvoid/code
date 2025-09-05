// lg 6242
// 将Ai加上k会增加的标签数量为logn
// 代价为logn,势能增加为最多（mlognlogn）
// 分开max增量和其他值增量
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define LOWEST -0x3f3f3f3f3f3f3f3f
typedef long long LL;
const int maxn = 500010;
struct trnode
{
    LL sum, ma, num, se;
    LL maxadd, otheradd;                   // 来做加法
    LL maxhistory, maxtopadd, othertopadd; // 来做区间历史最值
} tr[maxn << 2];
LL ls(LL lc) { return lc << 1; }
LL rs(LL lc) { return lc << 1 | 1; }
void pushup(int lc)
{
    trnode &p = tr[lc], &l = tr[ls(lc)], &r = tr[rs(lc)];
    p.maxhistory = max(l.maxhistory, r.maxhistory);
    p.sum = l.sum + r.sum;
    p.ma = max(l.ma, r.ma);
    if (l.ma == r.ma)
    {
        p.se = max(l.se, r.se);
        p.num = l.num + r.num;
    }
    else
    {
        p.se = max(min(l.ma, r.ma), max(l.se, r.se));
        p.num = l.ma > r.ma ? l.num : r.num;
    }
}
void lazy(int lc, int len, LL maxadd, LL otheradd, LL maxtopadd, LL othertopadd)
{
    trnode &p = tr[lc]; // 参数列表里的只是一次的变化值
    p.maxhistory = max(p.maxhistory, p.ma + maxtopadd);
    p.maxtopadd = max(p.maxtopadd, p.maxadd + maxtopadd);
    p.otheradd = max(p.othertopadd, p.otheradd + othertopadd);
    p.sum += maxadd * p.num + otheradd * (len - p.num);
    p.ma += maxadd;
    p.se += p.se == LOWEST ? 0 : otheradd;
    p.maxadd += maxadd;
    p.otheradd += otheradd;
}
void pushdown(int lc, int ln, int rn)
{
    trnode &p = tr[lc], &l = tr[lc << 1], &r = tr[lc << 1 | 1];
    LL tmp = max(l.ma, r.ma); // 全局最大值
    if (l.ma == tmp)
    {
        lazy(ls(lc), ln, p.maxadd, p.otheradd, p.maxtopadd, p.othertopadd);
    }
    else
    {
        lazy(ls(lc), ln, p.otheradd, p.otheradd, p.othertopadd, p.othertopadd);
    }
    if (r.ma == tmp)
    {
        lazy(rs(lc), rn, p.maxadd, p.otheradd, p.maxtopadd, p.othertopadd);
    }
    else
    {
        lazy(rs(lc), rn, p.otheradd, p.otheradd, p.othertopadd, p.othertopadd);
    }
    p.maxadd = p.otheradd = p.othertopadd = p.maxtopadd = 0;
}
void build(int lc, int l, int r)
{ // 建树
    trnode &p = tr[lc];
    if (l == r)
    {
        cin >> p.sum;
        p.ma = p.sum;
        p.se = LOWEST;
        p.num = 1;
        p.maxadd = 0, p.otheradd = 0;
        p.maxhistory = p.sum, p.maxtopadd = 0, p.othertopadd = 0;
        return;
    }
    int m = l + r >> 1;
    build(ls(lc), l, m);
    build(rs(lc), m + 1, r);
    pushup(lc);
}
void add(int L, int R, LL V, int lc, int l, int r)
{
    trnode &p = tr[lc];
    if (L <= l && r <= R)
    {
        lazy(lc, r - l + 1, V, V, V, V);
        return;
    }
    int m = l + r >> 1;
    pushdown(lc, m - l + 1, r - m);
    if (L <= m)
        add(L, R, V, lc << 1, l, m);
    if (R >= m + 1)
        add(L, R, V, lc << 1 | 1, m + 1, r);
    pushup(lc);
}
void setMin(int L, int R, LL V, int lc, int l, int r)
{
    trnode &p = tr[lc];
    if (V >= p.ma)
        return;
    if (L <= l && r <= R && p.se < V)
    {
        lazy(lc, r - l + 1, V - p.ma, 0, V - p.ma, 0);
        return;
    }
    int m = l + r >> 1;
    pushdown(lc, m - l + 1, r - m);
    if (L <= m)
        setMin(L, R, V, lc << 1, l, m);
    if (R >= m + 1)
        setMin(L, R, V, lc << 1 | 1, m + 1, r);
    pushup(lc);
}
LL querySum(int L, int R, int lc, int l, int r)
{
    if (l >= L && R >= r)
        return tr[lc].sum;
    if (r < L || l > R)
        return LOWEST;
    int m = l + r >> 1;
    pushdown(lc, m - l + 1, r - m);
    return querySum(L, R, ls(lc), l, m) + querySum(L, R, rs(lc), m + 1, r);
}
LL queryMax(int L, int R, int lc, int l, int r)
{
    if (l >= L && R >= r)
        return tr[lc].ma;
    if (r < L || l > R)
        return LOWEST;
    int m = l + r >> 1;
    pushdown(lc, m - l + 1, r - m);
    return max(queryMax(L, R, ls(lc), l, m), queryMax(L, R, rs(lc), m + 1, r));
}
LL queryMaxhistory(int L, int R, int lc, int l, int r)
{
    if (l >= L && R >= r)
        return tr[lc].maxhistory;
    if (r < L || l > R)
        return LOWEST;
    int m = l + r >> 1;
    pushdown(lc, m - l + 1, r - m);
    return max(queryMaxhistory(L, R, ls(lc), l, m), queryMaxhistory(L, R, rs(lc), m + 1, r));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        build(1, 1, n);
        while (m--)
        {
            int q, l, r;
            LL x;
            cin >> q >> l >> r;
            if (q == 1)
                cin >> x, add(l, r, x, 1, 1, n), cout << queryMax(1, 4, 1, 1, n) << endl;
            else if (q == 2)
                cin >> x, setMin(l, r, x, 1, 1, n);
            else if (q == 3)
                cout << querySum(l, r, 1, 1, n) << endl;
            else if (q == 4)
                cout << queryMax(l, r, 1, 1, n) << endl;
            else if (q == 5)
                cout << queryMaxhistory(l, r, 1, 1, n) << endl;
        }
    }
}
