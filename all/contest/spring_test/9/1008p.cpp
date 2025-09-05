#include <iostream>
#include <algorithm>
#include <cstring>
#define fi first
#define se second
using namespace std;

typedef pair <int, int> pii;

const int N = 2e3 + 5;

int n, q;
pii a[N];
int b[N];

int s[N][N];
void inc(int xl, int xr, int yl, int yr) {
	s[xl][yl]++;
	s[xl][yr + 1]--;
	s[xr + 1][yl]--;
	s[xr + 1][yr + 1]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> q;
		for (int i = 1;i <= n;++i) {
			int val;
			cin >> val;
			a[i] = {val, i};
		}
		sort(a + 1, a + n + 1);

		fill(b + 1, b + n + 1, 1);
		memset(s, 0, sizeof s);
		for (int i = 1;i <= n;++i) {
			int pos = a[i].se;
			b[pos] = 0;
			int l0 = pos; while ((l0 > 1) && (b[l0 - 1] == 0)) --l0;
			int r0 = pos; while ((r0 < n) && (b[r0 + 1] == 0)) ++r0;
			if (r0 == n) continue;
			int l1 = r0 + 1;
			int r1 = l1; while ((r1 < n) && (b[r1 + 1] == 1)) ++r1;
			inc(l0, pos, l1, r1);
		}

		for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= n;++j) {
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		}

		for (int i = 1;i <= q;++i) {
			int l, r;
			cin >> l >> r;
			cout << s[l][r] << "\n";
		}
	}
}

//区间更新，差分数组，为保证不重复，一每个分割点为端点，做一次操作