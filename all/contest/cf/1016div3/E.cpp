#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int num[N];
int n, k;

int check(int x) {
    int count = 0;
    vector<bool> present(x, false);
    int mex = 0;
    for (int i = 1; i <= n; ++i) {
        if (num[i] < x) {
            present[num[i]] = true;
        }
        while (mex < x && present[mex]) {
            mex++;
        }
        if (mex >= x) {
            count++;
            present.assign(x, false);
            mex = 0;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        int l = 0, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid) >= k) {  //只能大于等于k,因为如果更多的话可以合并让他更小
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}