#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10010;
int a[maxn], h[maxn];
struct trNode
{
    int max;
} tr[maxn << 2];
struct node
{
    int ai;
    int hi;
    int id;
    int times;
    bool operator<(const node &b) const {
        if (hi != b.hi) return hi > b.hi;
        if (ai != b.ai) return ai > b.ai;
        return id > b.id;
    }
};
void pushup(int lc)
{
    tr[lc].max = max(tr[lc << 1].max, tr[lc << 1 | 1].max);
}
void build(int l, int r, int lc)
{
    if (l == r)
    {
        tr[lc].max = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lc << 1);
    build(mid + 1, r, lc << 1 | 1);
    pushup(lc);
}

void update(int L, int V, int l, int r, int lc)
{
    if (l == r)
    {
        tr[lc].max = V;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        update(L, V, l, mid, lc << 1);
    else
        update(L, V, mid + 1, r, lc << 1 | 1);
    pushup(lc);
}
int query(int L, int R, int l, int r, int lc)
{
    if (l >= L && r <= R)
        return tr[lc].max;
    int ans = 0;
    int mid = l + r >> 1;
    if (L <= mid)
        ans = max(ans, query(L, R, l, mid, lc << 1));
    if (R >= mid + 1)
        ans = max(ans, query(L, R, mid + 1, r, lc << 1 | 1));
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n, u, k, hq;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        cin >> n >> u >> k >> hq;
        priority_queue<node> heap;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> h[i];
            heap.push({a[i], h[i], i, k});
        }
        build(1, n, 1);
        while (hq > 0 && heap.size())
        {
            auto tmp = heap.top();
            heap.pop();
            if (k > tmp.times)
            {
                tmp.hi -= u / 2;
            }
            else
            {
                tmp.hi -= u;
            }
            if (tmp.hi <= 0)
                update(tmp.id, 0, 1, n, 1), cnt++;
            int sh = query(1, n, 1, n, 1);
            hq -= sh;
            tmp.times--;
            if (tmp.times == 0 || tmp.hi <= 0)
                continue;
            heap.push({tmp.ai, tmp.hi, tmp.id, tmp.times});
        }
        cout << cnt << endl;
    }
}