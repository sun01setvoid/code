#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(2);
    int t;
    LL P;
    int n, k;
    int ti, pi;
    cin >> t;
    while (t--) {
        cin >> P >> n >> k;
        vector<double> dct;
        vector<LL> sub;
        dct.push_back(1.0);
        sub.push_back(0);  
        for (int i = 0; i < n; ++i) {
            cin >> ti >> pi;
            if (ti == 0)
                dct.push_back(pi / 10.0);  
            else
                sub.push_back(pi);         
        }
        sort(dct.begin() + 1, dct.end());          
        sort(sub.begin() + 1, sub.end(), greater<LL>());
        for (int i = 1; i < dct.size(); ++i) {
            dct[i] *= dct[i - 1];
        }
        for (int i = 1; i < sub.size(); ++i) {
            sub[i] += sub[i - 1];
        }
        double mi = 1e18;
        int l1 = dct.size() - 1, l2 = sub.size() - 1;
        int l = max(0, k - l2),r = min(l1, k);
        for (int i = l; i <= r; ++i) {
            int j = k - i;
            if (j < 0 || j > l2) continue;  // 检查j是否超出sub数组范围
            double mul = dct[i];
            LL sum = sub[j];
            double price1 = max(P * mul - sum, 0.0);
            double remaining = max(P - sum, 0LL);
            double price2 = remaining * mul;
            price2 = max(price2, 0.0);
            mi = min(mi, min(price1, price2));
        }
        cout << mi << endl;
    }
    return 0;
}