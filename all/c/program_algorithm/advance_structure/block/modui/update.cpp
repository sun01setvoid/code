//带修莫队 n^(5/3)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                    \
  ios::sync_with_stdio(false); \
  cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int w[maxn], cnt[maxn], be[maxn];
int ans[maxn];
int len;
vector<pii> c(maxn);
struct node {
  int l, r, tm, id;
  bool operator<(const node &p) {
    if (be[l] != be[p.l]) return be[l] < be[p.l];
    if (be[r] != be[p.r]) return be[r] < be[p.r];
    return tm < p.tm;
  }
} qr[maxn];
void add(int x, int &res) {
  if (++cnt[x] == 1) res++;
}
void del(int x, int &res) {
  if (cnt[x]-- == 1) res--;
}
void solve() {
  string s;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  int ct = 0;
  int l, r;
  int cq = 0;
  for (int i = 1; i <= m; i++) {
    cin >> s;
    cin >> l >> r;
    if (s[0] == 'Q') {
      qr[++cq] = {l, r, ct, cq};
    } else {
      c[++ct] = {l, r};
    }
  }
  len = pow(n, 2.0 / 3.0);
  for (int i = 1; i <= 1e6; i++) be[i] = i / len;
  sort(qr + 1, qr + cq + 1);
  int res = 0;
  for (int q = 1, i = 1, j = 0, t = 0; q <= cq; q++) {
    int l = qr[q].l, r = qr[q].r, tm = qr[q].tm, id = qr[q].id;
    while (j < r) add(w[++j], res);
    while (j > r) del(w[j--], res);
    while (i > l) add(w[--i], res);
    while (i < l) del(w[i++], res);
    while (t < tm) {
      ++t;
      if (c[t].fi >= l && c[t].fi <= r) {
        del(w[c[t].fi], res);
        add(c[t].se, res);
      }
      swap(w[c[t].fi], c[t].se);  //记录原先是谁
    }
    while (t > tm) {
      if (c[t].fi >= l && c[t].fi <= r) {
        del(w[c[t].fi], res);
        add(c[t].se, res);
      }
      swap(w[c[t].fi], c[t].se);
      t--;
    }
    ans[id] = res;
  }
  for (int i = 1; i <= cq; i++) cout << ans[i] << endl;
}
signed main() {
  IOS;
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}