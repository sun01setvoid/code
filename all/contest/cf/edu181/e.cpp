#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> f(x + 2, 0); 
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<int> g(x + 2, 0);
        int sum = 0;
        for (int val = 1; val <= x; ++val) {
            sum = (sum + f[val / 2]) % MOD;
            g[val] = sum;
        }
        f = g;
    }

    int ans = 0;
    for (int val = 1; val <= x; ++val)
        ans = (ans + f[val]) % MOD;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
