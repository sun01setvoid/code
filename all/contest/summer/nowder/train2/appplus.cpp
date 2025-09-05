#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // dp[i][0] = {sum, cnt}, dp[i][1] = {sum, cnt}
    vector<array<pair<ll, ll>, 2>> dp(n + 1);
    
    if (a[1] == 1) {
        dp[1][1] = {1, 1};
    } else if (a[1] == 0) {
        dp[1][0] = {0, 1};
    } else {
        dp[1][1] = {1, 1};
        dp[1][0] = {0, 1};
    }
    
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1 || a[i] == -1) {
            // Current is 1
            dp[i][1].first = (dp[i - 1][0].first + dp[i - 1][0].second + dp[i - 1][1].first) % mod;
            dp[i][1].second = (dp[i - 1][0].second + dp[i - 1][1].second) % mod;
        }
        if (a[i] == 0 || a[i] == -1) {
            // Current is 0
            dp[i][0].first = (dp[i - 1][0].first + dp[i - 1][1].first) % mod;
            dp[i][0].second = (dp[i - 1][0].second + dp[i - 1][1].second) % mod;
        }
    }
    
    ll ans = 0;
    if (a[n] == 1) {
        ans = dp[n][1].first;
    } else if (a[n] == 0) {
        ans = dp[n][0].first;
    } else {
        ans = (dp[n][1].first + dp[n][0].first) % mod;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}