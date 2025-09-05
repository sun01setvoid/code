#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> classrooms;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        int floor = num / 100;
        classrooms.emplace_back(floor, num);
    }
    sort(classrooms.begin(), classrooms.end());

    vector<pair<int, int>> ans;
    int left = 0, right = m - 1;
    while (left <= right && ans.size() < n) {
        if (left == right) {
            ans.emplace_back(classrooms[left].second, classrooms[left].second);
            break;
        } else {
            ans.emplace_back(classrooms[left].second, classrooms[right].second);
            if (ans.size() < n) {
                ans.emplace_back(classrooms[right].second, classrooms[left].second);
            }
            left++;
            right--;
        }
    }

    for (int i = 0; i < n; ++i) {
        auto [first, second] = ans[i % ans.size()];
        for (int j = 0; j < 6; ++j) {
            if (j % 2 == 0) {
                cout << first;
            } else {
                cout << second;
            }
            if (j < 5) cout << " ";
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}