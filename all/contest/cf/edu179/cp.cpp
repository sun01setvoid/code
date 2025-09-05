#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> fi(n + 1, -1);
        vector<int> la(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            if (fi[a[i]] == -1) {
                fi[a[i]] = i;
            }
            la[a[i]] = i;
        }
        int mi = LONG_LONG_MAX;
        for (int val = 1; val <= n; ++val) {
            if (fi[val] == -1) {
                continue; 
            }
            int first = fi[val];
            int last = la[val];
            int cost = 0;
            if (first > 0) {
                cost += first * val;
            }
            if (last < n - 1) {
                cost += (n - 1 - last) * val;
            }
            mi = min(mi, cost);
        }

        cout << mi << '\n';
    }
    return 0;
}