#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e6 + 10;
int vis[maxn];
ull H[maxn];
// 1009存储字符串 hash
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd() { return (unsigned long long)rng(); }
void solve() {
  int n;
  cin >> n;
  vector<ull> sum(n + 1);
  unordered_map<ull, int> mp;
  mp[0] = 0;
  int ansl = -1, ansr = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum[i] = sum[i - 1] ^ H[x];
    if (mp.find(sum[i]) != mp.end()) {
      int l = mp[sum[i]];
      if (i - (l + 1) > ansr - ansl || ansl == -1) {
        ansr = i;
        ansl = l + 1;
      }
    } else
      mp[sum[i]] = i;
  }
  cout << ansl << " " << ansr << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i < maxn; i++)
    if (!vis[i]) {
      ull h = rnd();
      H[i] = h;
      for (int j = i * 2; j < maxn; j += i) {
        int t = j;
        vis[j] = 1;
        while (t % i == 0) {
          H[j] ^= h;
          t /= i;
        }
      }
    }
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

//公式推算冲突概率为n*n/(2*H)