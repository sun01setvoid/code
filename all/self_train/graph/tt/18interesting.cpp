//P1229 遍历问题，中序遍历的数量
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e3 + 5;
const int maxm = 1e5 + 5;
const int mod = 998244353;
using namespace std;
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  for (int i = 0; i < s1.size() - 1; i++) {
    for (int j = 1; j < s1.size(); j++) {
      if (s1[i] == s2[j] && s1[i + 1] == s2[j - 1]) ans++;
    }
  }
  int res = 1;
  for (int i = 1; i <= ans; i++) res *= 2;
  cout << res << endl;
}
signed main() {
  IOS;
  int t = 1;
  // cin >> t;
  while (t--) solve();
}