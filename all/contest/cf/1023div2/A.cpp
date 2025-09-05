#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int compute_gcd(const vector<int>& a) {
    int g = a[0];
    for (int i = 1; i < a.size(); ++i) {
        g = gcd(g, a[i]);
    }
    return g;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int g = compute_gcd(a);
    bool f = true;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != g) {
            f = false;
            pos = i;
            break;
        }
    }

    if (f) {
        cout << "No\n";
        return;
    }

    vector<int> ans(n, 1);
    ans[pos] = 2;

    cout << "Yes\n";
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}