#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct Node
{
    int left0, right0;
    int left1, right1;
    int ma[2];
    int len;
    bool tag;
} tr[N << 2];
string str;
int ls(int lc)
{
    return lc << 1;
}
int rs(int lc)
{
    return lc << 1 | 1;
}
void pushup(int lc)
{
    Node &L = tr[ls(lc)], &R = tr[rs(lc)], &p = tr[lc];
    p.len = L.len + R.len;
    p.ma[0] = max(max(L.ma[0], R.ma[0]), L.right0 + R.left0);
    p.ma[1] = max(max(L.ma[1], R.ma[1]), L.right1 + R.left1);
    p.left0 = L.left0 == L.len ? L.len + R.left0 : L.left0;
    p.left1 = L.left1 == L.len ? L.len + R.left1 : L.left1;
    p.right0 = R.right0 == R.len ? R.len + L.right0 : R.right0;
    p.right1 = R.right1 == R.len ? R.len + L.right1 : R.right1;
}
void build(int lc, int l, int r)
{
    tr[lc].len = r - l + 1;
    tr[lc].tag = 0;
    if (l == r)
    {
        if (str[l - 1] == '0')
        {
            tr[lc].left0 = tr[lc].right0 = tr[lc].ma[0] = 1;
            tr[lc].left1 = tr[lc].right1 = tr[lc].ma[1] = 0;
        }
        else
        {
            tr[lc].left1 = tr[lc].right1 = tr[lc].ma[1] = 1;
            tr[lc].left0 = tr[lc].right0 = tr[lc].ma[0] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(lc), l, mid);
    build(rs(lc), mid + 1, r);
    pushup(lc);
}
void rev(int lc)
{
    swap(tr[lc].left0, tr[lc].left1);
    swap(tr[lc].right0, tr[lc].right1);
    swap(tr[lc].ma[0], tr[lc].ma[1]);
    tr[lc].tag ^= 1;
}
void pushdown(int lc)
{
    if (tr[lc].tag)
    {
        rev(ls(lc));
        rev(rs(lc));
        tr[lc].tag = 0;
    }
}
void update(int lc, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        rev(lc);
        return;
    }
    pushdown(lc);
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(ls(lc), l, mid, L, R);
    if (R > mid)
        update(rs(lc), mid + 1, r, L, R);
    pushup(lc);
}
int query(int lc, int l, int r, int k, int op)
{
    if (tr[lc].len < k)
        return -1;

    if (l == r)
        return l;
    pushdown(lc);
    int mid = (l + r) >> 1;
    if (op == 0)
    {
        if (tr[ls(lc)].ma[0] >= k)
            return query(ls(lc), l, mid, k, op);
        if (tr[ls(lc)].right0 + tr[rs(lc)].left0 >= k)
            return mid - tr[ls(lc)].right0 + 1;
        if (tr[rs(lc)].ma[0] >= k)
            return query(rs(lc), mid + 1, r, k, op);
        else
            return -1;
    }
    else
    {
        if (tr[ls(lc)].ma[1] >= k)
            return query(ls(lc), l, mid, k, op);
        if (tr[ls(lc)].right1 + tr[rs(lc)].left1 >= k)
            return mid - tr[ls(lc)].right1 + 1;
        if (tr[rs(lc)].ma[1] >= k)
            return query(rs(lc), mid + 1, r, k, op);
        else
            return -1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    int op, k, pos;
    cin >> T;
    while (T--)
    {
        cin >> str;
        int l = str.size();
        build(1, 1, l);
        int q;
        cin >> q;
        while (q--)
        {
            cin >> op >> k;
            if (tr[1].ma[op] < k)
            {
                cout << -1<<"\n";
                continue;
            }
            pos = query(1, 1, l, k, op);
            cout << pos << "\n";
            update(1, 1, l, pos, pos + k - 1);
        }
    }
    return 0;
}