#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long long> sum() {
    vector<int> primes;
    int cnt = 2;
    while (primes.size() < 1000) {
        bool f = true;
        for (int p : primes) {
            if (p * p > cnt) break;
            if (cnt % p == 0) {
                f = false;
                break;
            }
        }
        if (f) {
            primes.push_back(cnt);
        }
        cnt++;
    }
    vector<long long> presum(1, 0);
    for (int p : primes) {
        presum.push_back(presum.back() + p);
    }
    return presum;
}

vector<long long> presum = sum();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        int tmp = 0;
        int ma = min(n, (int)presum.size() - 1);
        for (int k = ma; k >= 1; k--) {
            if (pre[k] >= presum[k]) {
                tmp = k;
                break;
            }
        }
        cout << n - tmp << '\n';
    }
    return 0;
}