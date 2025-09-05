#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n+1, vector<int>(m+1));
        vector<int> ma(n+1);
        int sum = 0;
        for (int i = 1; i <=n; ++i) {
            int sma = 0;
            for (int j = 1; j <=m; ++j) {
                cin >> a[i][j];
                sma = max(sma, a[i][j]);
            }
            ma[i] = sma;
            sum += sma;
        }
        int ans = 0;
        for (int k = 1; k <= m; ++k) {
            vector<int> res;
            for (int i = 1; i <= n; ++i) {
                res.push_back(ma[i] - a[i][k]);
            }
            sort(res.begin(), res.end());
            int tmp=0;
            for (int i=0;i<n/2+1;i++) tmp+=res[i];
            ans = max(ans, sum - tmp);
        }
        cout << ans << "\n";
    }
    return 0;
}