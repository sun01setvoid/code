#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],pos[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int ma = 1, len = 1;
        for (int x = 2; x <= n; x++) {
            if (pos[x-1] < pos[x]) len++;
            else len = 1;
            ma = max(ma, len);
        }
        cout << n - ma << "\n";
    }
    return 0;
}