#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<ld, ld>
#define pb push_back
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 3e6 + 5;
const int mod = 998244353;
const ld eps = 1e-8;
//-----------------------------------------------------//
int stk[maxn];
//suffix表达式直接按顺序算就好了，所以生成suffix表达式，就是生成计算顺序
//这个后缀其实是语法树后序遍历（左右根，运算符在根）
// 构建语法树？
void solve() 
{	
	char ch;
	int cur=0;
	int top=-1;
	while ((ch=getchar())!='@'){
		if (ch=='.') {
			stk[++top]=cur;
			cur=0;
		}
		else if (isdigit(ch)){
			cur=cur*10+ch-'0';
		}else{
			int b=stk[top--],a=stk[top--];
			int c;
			if (ch=='+') c=a+b;
			else if (ch=='-') c=a-b;
			else if (ch=='*') c=a*b;
			else c=a/b;
			stk[++top]=c;
		}
	}
	cout<<stk[top];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _ = 1;
  //cin >> _;
  while (_--) solve();
  return 0;
}