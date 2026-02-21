//P3185 HNOI2007 分裂游戏 （翻硬币）
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int maxn = 100;
const int maxm = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
int sg[maxn];
int cnt[maxn];
int a[maxn];
void solve() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = n; i >= 1; i--) {
    cin >> a[i];
    res ^= sg[i * (a[i] & 1)];
  }
  if (!res) {
    cout << "-1 -1 -1" << endl;
    cout << 0 << endl;
  } else {
    bool f = 0;
    int num = 0;
    for (int i = n; i >= 2; i--) {
      if (a[i] > 0) {
        res ^= sg[i];
        for (int j = i - 1; j >= 1; j--) {
          res ^= sg[j];
          for (int k = j; k >= 1; k--) {
            res ^= sg[k];
            if (!res) {
              if (!f) cout << n - i << " " << n - j << " " << n - k << endl;
              f = 1;
              num++;
            }
            res ^= sg[k];
          }
          res ^= sg[j];
        }
        res ^= sg[i];
      }
    }
    cout << num << endl;
  }
}
signed main() {
  IOS;
  int t = 1;
  memset(sg, -1, sizeof sg);
  sg[0] = 0;
  sg[1] = 0;
  for (int i = 2; i <= 21; i++) {
    int mex = 0;
    for (int j = i - 1; j >= 1; j--) {
      for (int k = j; k >= 1; k--) {
        cnt[sg[j] ^ sg[k]]++;
      }
    }
    while (cnt[mex]) mex++;
    sg[i] = mex;
    for (int j = i - 1; j >= 1; j--) {
      for (int k = j; k >= 1; k--) {
        cnt[sg[j] ^ sg[k]]--;
      }
    }
  }
  cin >> t;
  while (t--) solve();
}