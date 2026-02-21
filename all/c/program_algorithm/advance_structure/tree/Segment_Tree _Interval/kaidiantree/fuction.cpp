// root 表示整棵线段树的根结点；cnt 表示当前结点个数
/*
int n, cnt, root;
int sum[n * 2], ls[n * 2], rs[n * 2];

// 用法：update(root, 1, n, x, f); 其中 x 为待修改节点的编号
void update(int& p, int s, int t, int x, int f) {  // 引用传参
  if (!p) p = ++cnt;  // 当结点为空时，创建一个新的结点
  if (s == t) {
    sum[p] += f;
    return;
  }
  int m = s + ((t - s) >> 1);
  if (x <= m)
    update(ls[p], s, m, x, f);
  else
    update(rs[p], m + 1, t, x, f);
  sum[p] = sum[ls[p]] + sum[rs[p]];  // pushup
}

// 用法：query(root, 1, n, l, r);
int query(int p, int s, int t, int l, int r) {
    if (!p) return 0;  // 如果结点为空，返回 0
    if (s >= l && t <= r) return sum[p];
    int m = s + ((t - s) >> 1), ans = 0;
    if (l <= m) ans += query(ls[p], s, m, l, r);
    if (r > m) ans += query(rs[p], m + 1, t, l, r);
    return ans;
  }
*/
#include <bits/stdc++.h>
#define int unsigned long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define ls (tr[p].l)
#define rs (tr[p].r)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 4e5 + 10;
// 把查询改为[x,y+1)
struct node
{
  int sm;
  int l, r;
  int ad;
} tr[maxn << 2];
int a[maxn];
int n, m, rt, cnt;
void up(int p) { tr[p].sm = tr[ls].sm + tr[rs].sm; }
void down(int &p, int ll, int rr)
{
  if (!ls)
    ls = ++cnt;
  if (!rs)
    rs = ++cnt;
  tr[ls].sm = tr[ls].sm + tr[p].ad * ll;
  tr[rs].sm = tr[rs].sm + tr[p].ad * rr;
  tr[ls].ad = tr[ls].ad + tr[p].ad;
  tr[rs].ad = tr[rs].ad + tr[p].ad;
  tr[p].ad = 0;
}
void upd(int &p, int l, int r, int L, int R, int val)
{
  if (!p)
    p = ++cnt;
  if (L <= l && r <= R)
  {
    tr[p].ad = tr[p].ad + val;
    tr[p].sm = tr[p].sm + (r - l + 1) * val;
    return;
  }
  int mid = (l + r) / 2;
  down(p, mid - l + 1, r - mid);
  if (L <= mid)
    upd(ls, l, mid, L, R, val);
  if (mid + 1 <= R)
    upd(rs, mid + 1, r, L, R, val);
  up(p);
}
int qry(int &p, int l, int r, int L, int R)
{
  if (!p)
    return 0;
  if (L <= l && r <= R)
  {
    return tr[p].sm;
  }
  int mid = (l + r) / 2;
  int ans = 0;
  down(p, mid - l + 1, r - mid);
  if (L <= mid)
    ans = ans + qry(ls, l, mid, L, R);
  if (R >= mid + 1)
    ans = ans + qry(rs, mid + 1, r, L, R);
  return ans;
}
void solve()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int op, x, y, k;
    cin >> op;
    if (op == 1)
    {
      cin >> x >> y >> k;
      upd(rt, 1, n, x, y, k);
    }
    else
    {
      cin >> x >> y;
      cout << (y + x) * (y - x + 1) / 2 + qry(rt, 1, n, x, y) << endl;
    }
  }
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  // cin >> T;
  for (int tc = 1; tc <= T; tc++)
  {
    solve();
  }
  return 0;
}