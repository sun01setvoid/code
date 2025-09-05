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