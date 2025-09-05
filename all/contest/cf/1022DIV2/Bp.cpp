#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        LL n, x; cin >> n >> x;
        if (x == 0) {
            if (n == 1) cout << "-1\n";
            else if (n%2==0) cout<<n<<"\n";
            else cout<<n+3<<"\n";
            continue;
        }
 
        LL ans = LLONG_MAX;
        for (int m = 1; m <= 3 && m <= n; m++) {
            LL ones = n - m, r = ones % 2, y = x ^ r;
            LL Sm = y;
            if (m == 2) Sm = (y == 0) ? 2 : (y == 1) ? 5 : (__builtin_popcountll(y) >= 2 ? y : y + 2);
            else if (m == 3) Sm = (y == 0) ? 6 : (__builtin_popcountll(y) >= 3 ? y : y + 2);
            if (Sm > 0) ans = min(ans, n - m + Sm);
        }
        for (int r : {0, 1}) {
            if (n - r < 1) continue;
            LL y = x ^ r;
            if (y == 0) continue;
            int pc = __builtin_popcountll(y);
            int m_max = pc - ((pc % 2) != ((n - r) % 2));
            if (m_max >= 1 && m_max <= n) ans = min(ans, n - m_max + y);
        }
        cout << ans << "\n";
    }
    return 0;
}