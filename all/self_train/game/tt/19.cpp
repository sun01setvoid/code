//HEOI2014人人尽说江南好
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
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;

void solve() {
	int n,m;
	cin>>n>>m;
	if (n<=m){
		if (n&1) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		int d=n/m;
		int r=n%m;
		int ans=d*(m-1)+max(r-1,0ll);
		ans=ans&1;
		if (ans) cout<<0<<endl;
		else cout<<1<<endl;
	}
}
signed main() {
  IOS;
  int t = 1;
  cin >> t;
  while (t--) solve();
}