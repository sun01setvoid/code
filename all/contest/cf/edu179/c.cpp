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
        vector<int> a(n),dp(n+1,0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int mi=LONG_LONG_MAX;
        int l=0,r=0;
        for (int i=0;i<n-1;i++){
            if (a[i]==a[i+1]) r++;
            else {
                mi=min(mi,(l+n-1-r)*a[i]);
                l=r=i+1;
            }
        }
        mi=min(mi,(l+n-1-r)*a[n-1]);
        cout << mi << '\n';
    }
    return 0;
}