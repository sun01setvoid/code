#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
// 完整的二维 DP 实现：
// F[i][j] 表示处理到第 i 个元素（1-indexed）之后，"长度为 j" 的方案数。
// 初始 F[0][0] = 1。
// 对于每个 i，先把上一行拷贝到当前行：F[i][j] = F[i-1][j]
// 然后对 j 在 [l[i], r[i]] 范围内做：F[i][j] += F[i][j-1]
// 最终答案是 F[n][n]
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> L(n+1), R(n+1);
        for (int i = 1; i <= n; ++i) {
            int l = i, r = i;
            while (l - 1 >= 1 && a[l-1] >= a[i]) --l;
            while (r + 1 <= n && a[r+1] >= a[i]) ++r;
            L[i] = l;
            R[i] = r;
        }
        vector<vector<ll>> F(n+1, vector<ll>(n+1, 0));
        F[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) F[i][j] = F[i-1][j];
            for (int j = max(1, L[i]); j <= min(n, R[i]); ++j) {
                F[i][j] += F[i][j-1];
                if (F[i][j] >= MOD) F[i][j] -= MOD;
            }
        }
        cout << F[n][n] % MOD << '\n';
    }
    return 0;
}
