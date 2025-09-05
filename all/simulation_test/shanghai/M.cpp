#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    __int128 ans = LLONG_MAX;
    __int128 cost = 0;
    while (true) {
        __int128 tot = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] & 1) {
                cost += x;
                a[i]--;
            }
            tot += a[i];
        }
        ans = min(ans, cost + tot * x);
        if (tot == 0) {
            break;
        }
        cost += y;
        for (int i = 1; i <= n; ++i) {
            a[i] /= 2;
        }
    }
    cout << (ll)ans << endl;
    return 0;
}