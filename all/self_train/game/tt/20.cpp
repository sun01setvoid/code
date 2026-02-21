// ZJOI 取石子游戏
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                  \
	ios::sync_with_stdio(0); \
	cin.tie(0)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int maxn = 1e3 + 10;
const int maxm = 1e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
//L[i][j]表示在[i,j]左边放多少个石子，先手必败
//所以哪个判断应该是只用写一个
void solve()
{
	int n;
	cin >> n;
	vii a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<vii> L(n + 1, vii(n + 1, 0)), R(n + 1, vii(n + 1, 0));
	for (int i = 1; i <= n; i++)
		L[i][i] = a[i], R[i][i] = a[i];
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			int LL = L[i][j - 1], RR = R[i][j - 1], x = a[j];
			if (RR == x)
				L[i][j] = 0;
			else if (x < LL && x < RR || x > LL && x > RR)
				L[i][j] = x;
			else if (LL > RR)
				L[i][j] = x - 1;
			else
				L[i][j] = x + 1;
			LL = L[i + 1][j], RR = R[i + 1][j], x = a[i];
			if (LL == x)
				R[i][j] = 0;
			else if (x < LL && x < RR || x > LL && x > RR)
				R[i][j] = x;
			else if (LL > RR)
				R[i][j] = x + 1;
			else
				R[i][j] = x - 1;
		}
	}
	if (n == 1)
		cout << 1 << endl;
	else
	{
		if (L[2][n] == a[1] && R[1][n - 1] == a[n])
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
}
signed main()
{
	IOS;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}