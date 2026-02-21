//2016-2017 National Taiwan University World Final Team Selection Contest
//G
//子树信息向高位传递
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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 5e6 + 5;
const int mod = 1e9 + 7;
const int P = 998244353123456789;
const ld eps = 1e-7;
//-----------------------------------------------------//
bool vis[maxn];
vector<vii> g(maxn);
int dg[maxn];
int ans;
int dfs(int u, int fa) {
  if (dg[u] == 1) return 1;
  int a = 0, b = 0;
  for (auto v : g[u]) {
    if (v == fa) continue;
    int t = dfs(v, u);
    if (t == 1)
      a++;
    else if (t==2)
      b++;
  }
  while (a > 2) ans++, a -= 2;
  while (b > 1) ans++, b -= 2;
  while (a > 1 && b) ans++, a -= 1, b -= 1;
  return min(2ll, a + 2 * b);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n-1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    dg[u]++;
    dg[v]++;
  }
  if(n==2){
  	cout<<1<<endl;
  	return;
  }
  for (int i = 1; i <= n; i++) {
    if (dg[i] > 1) {
      if(dfs(i, i)==2) ans++;
      break;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) solve();
  return 0;
}