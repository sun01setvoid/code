#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
unordered_map<int, int> memo;
vector<int> getFactors(int n, int k) {
    vector<int> factors;
    for (int a = 1; a * a <= n; ++a) {
        if (n % a == 0) {
            if (a != 1 && a <= k) {
                factors.push_back(a);
            }
            if (n / a != 1 && n / a != a && n / a <= k) {
                factors.push_back(n / a);
            }
        }
    }
    sort(factors.begin(), factors.end(), greater<int>());
    return factors;
}

int getSteps(int n, int k, const vector<int>& factors) {
    if (n == 0) return -1;
    if (n == 1) return 0;
    if (memo.find(n) != memo.end()) return memo[n];
    int min_steps = INT_MAX;
    for (int a : factors) {
        if (n % a != 0) continue;
        int steps = getSteps(n / a, k, factors);
        if (steps != -1) {
            min_steps = min(min_steps, steps + 1);
        }
    }
    memo[n] = (min_steps == INT_MAX) ? -1 : min_steps;
    return memo[n];
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (x == y) {
        cout << 0 << '\n';
        return;
    }
    int g = gcd(x, y);
    int p = y / g;
    int q = x / g;

    memo.clear();
    vector<int> factors = getFactors(p, k);
    int steps_p = getSteps(p, k, factors);
    memo.clear();
    factors = getFactors(q, k);
    int steps_q = getSteps(q, k, factors);

    if (steps_p == -1 || steps_q == -1) {
        cout << -1 << '\n';
    } else {
        cout << steps_p + steps_q << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}