#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 200010;
typedef long long LL;
struct trNode
{
    LL sum;
} tr[maxn << 2];
void pushup(int lc)
{
    tr[lc].sum = tr[lc << 1].sum + tr[lc << 1 | 1].sum;
}
void build(int l, int r, int lc)
{
    if (l == r)
    {
        cin >> tr[lc].sum;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lc << 1);
    build(mid + 1, r, lc << 1 | 1);
    pushup(lc);
}

void update(int L, LL V, int l, int r, int lc)
{ 
    if (l == r)
    {
        tr[lc].sum = V;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        update(L, V, l, mid, lc << 1);
    else
        update(L, V, mid + 1, r, lc << 1 | 1);
    pushup(lc);
}
LL query(int L, int R, int l, int r, int lc)
{
    if (l >= L && r <= R)
        return tr[lc].sum;
    LL ans = 0;
    int mid = l + r >> 1;
    if (L <= mid)
        ans += query(L, R, l, mid, lc << 1);
    if (R >= mid + 1)
        ans += query(L, R, mid + 1, r, lc << 1 | 1);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int x,l,r,t, q, op,n;
    LL y;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        LL ans = 0;
        LL cnt=0;
        cin >> n >> q;
        build(1, n, 1);
        while (q--)
        {
            cin >> op;
            if (op == 1)
                cin >> x >> y, update(x, y, 1, n, 1);
            else
            {
                ++cnt;
                cin >> l >> r;
                LL res = 0;
                res += query(1, r, 1, n, 1) / 100;
                if (l!=1)
                res -= query(1, l - 1, 1, n, 1) / 100;
                ans ^= res * cnt;
            }
        }
        cout << ans << endl;
    }
}