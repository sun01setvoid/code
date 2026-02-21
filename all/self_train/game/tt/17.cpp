//agc010_f tree_game
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
const int maxn = 3010;
const int maxm = 3e3 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
//从小数据开始分析
int a[maxn];
vector<vii> adj(maxn);
int dfs(int u,int fa){
  for (auto v:adj[u]){
    if (v==fa) continue;
    int t=dfs(v,u);
    if (!t && a[v]<a[u]) return 1;
  }
  return 0;
}
void solve() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>a[i];
  for (int i=1;i<=n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i=1;i<=n;i++){
    int t=dfs(i,i);
    if (t) cout<<i<<" ";
  }
}
signed main() {
  IOS;
  int t = 1;
  //cin >> t;
  while (t--) solve();
}