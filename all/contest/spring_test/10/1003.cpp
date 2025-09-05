#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
vector <int> cnt(N);
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
            ma = max(ma, a[i]);
        }
        int ans = 0;
        for (int d = 1; d <= ma; ++d) {
            for (int k = 1; k * d <= ma; ++k) {
                int x = k * d;
                int y = (k + 1) * d;
                if (y > ma) break;
                ans += cnt[x] * cnt[y];
            }
        }
        cout << ans << "\n";
        for (int i = 0; i < n; ++i)
            cnt[a[i]] = 0;
    }
    return 0;
}
