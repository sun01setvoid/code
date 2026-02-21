
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
const int maxm = 3e3 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
//对于k阶多项式维护k个数组，vp^0,vp^1,vp^2,vp^k-1
//ap前的系数为c（pos-p+k-1,k-1)，拆开看看各项系数
//1/(k-1)!   先提出，但不要忘记
//剩下的连乘做二项式分解
//得到(pos+1)x+1,(pos+2)x+1...(pos+(k-1)x)+1的多项式
//多项式相乘，可分治之类的
//x^(k-1-i)次前的系数就是，vp^i的系数，但不要忘记最后总和乘1/(k-1)!
//注意一下每项的正负，i为偶数的时候是正，奇数的时候是负
void solve() {

}
signed main() {
  IOS;
  int t = 1;
  //cin >> t;
  while (t--) solve();
}