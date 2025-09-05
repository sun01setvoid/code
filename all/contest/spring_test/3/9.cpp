#include <bits/stdc++.h>
//基础并查集，merge是把野人合并到某个部落，野人和部落在根时同义
//对于基础并查集,在op2,野人和部落分离
//op3交换部落,位置和部落分离
const int N = 1e6 + 5;
int n, q;
int g[N];//每个野人对应的部落
int fx[N], xf[N];//fx是i位置对应的部落，xf是i部落所做的位置  //映射
int fa[N];//部落的关系
int a[N];

//野人，部落分别处理
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
// x is root
void merge(int x, int y) {
  x = find(x); y = find(y);
  fa[y] = x;
}

void solve() {
  std::cin >> n >> q;
  std::iota(g + 1, g + n + 1, 1);
  std::iota(fx + 1, fx + n + 1, 1);
  std::iota(xf + 1, xf + n + 1, 1);
  std::iota(fa + 1, fa + n + 1, 1);
  // for (int i = 1; i <= n; i++) {
  //   std::cin >> a[i];
  // }
  while (q--) {
    int op, a, b;
    std::cin >> op;
    if (op == 1) {
      std::cin >> a >> b;
      a = fx[a];
      b = fx[b];
      merge(a, b);
    } else if (op == 2) {
      std::cin >> a >> b;
      g[a] = fx[b];
    } else if (op == 3) {
      std::cin >> a >> b;
      a = fx[a];
      b = fx[b];
      std::swap(fx[xf[a]], fx[xf[b]]);
      std::swap(xf[a], xf[b]);      
    } else {
      std::cin >> a;
      int fa = find(g[a]);
      std::cout << xf[fa] << '\n';
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}