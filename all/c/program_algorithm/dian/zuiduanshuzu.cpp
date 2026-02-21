//选一个最短数组使之升序
//那么要最右的前缀max>当前位置，这样后面的就都有序了
//选最左的后缀min<当前位置，这样前面的就有序了
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
#define fi first
#define se second
#define pa pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
const int z = 2e5 + 10;
const int zz = 2e5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const ld pi = 4. * atan(1.);
const ld eps = 1e-9;
int a[maxn];

void solve()
{
    int n;
    cin>>n;
    int mi=inf,ma=0;
    for (int i=1;i<=n;i++) cin>>a[i],mi=min(a[i],mi),ma=max(a[i],ma);
    int prema=mi,premi=ma;
    int l=inf,r=0;
    for (int i=1;i<=n;i++){
        if (prema>a[i]) r=max(r,i);
        prema=max(prema,a[i]);
    }
    for (int i=n;i>=1;i--){
        if (premi<a[i]) l=min(l,i);
        premi=min(premi,a[i]);
    }
    if (l>=r) cout<<0<<endl;
    else cout<<r-l+1<<endl;
}
signed main()
{
  IOS;
  int t = 1;
  //cin >> t;
  while (t--)
    solve();
}