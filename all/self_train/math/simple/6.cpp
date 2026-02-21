//P2441角色树 随机a,b,__gcd(a,b)>1的概率为31%
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                    \
  ios::sync_with_stdio(false); \
  cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------/
int f[maxn],a[maxn];
int dfs(int u,int val){
	if (u==0) return -1; 
	if (__gcd(a[u],a[val])>1) return u;
	else return dfs(f[u],val);
}
void solve() {
  int n,q;
  cin>>n>>q;
  for (int i=1;i<=n;i++){
  	cin>>a[i];
  }
  for (int i=1;i<=n-1;i++){
  	int x,y;
  	cin>>x>>y;
  	f[y]=x;
  }
  for (int i=1;i<=q;i++){
  	int op,x,y;
  	cin>>op;
  	if (op==1){
  		cin>>x;
  		int t=dfs(f[x],x);
  		cout<<t<<endl;
  	}else cin>>x>>y,a[x]=y;
  }
}
signed main() {
  IOS;
  int _ = 1;
  //cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}