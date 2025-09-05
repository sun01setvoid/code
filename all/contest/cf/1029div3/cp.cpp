#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), last(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            last[a[i]] = i; // 记录每个值最后出现位置
        }

        int seg_end = 0, segments = 0;
        for (int i = 0; i < n; ++i) {
            seg_end = max(seg_end, last[a[i]]);
            if (i == seg_end) {
                segments++; // 可以切一段
            }
        }
        cout << segments << '\n';
    }
    return 0;
}
