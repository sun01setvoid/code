#include <bits/stdc++.h>
using namespace std;

// ==================== 第一个解法 ====================
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back

namespace Solver1 {
void solve(int n, const vector<int>& a) {
    n = 2 * n;
    vii pre0(n + 1, 0), pre1(n + 1, 0);
    rep(i, 1, n) {
        if (i & 1)
            pre1[i] += pre1[i - 1] + a[i-1], pre0[i] += pre0[i - 1];
        else
            pre0[i] += pre0[i - 1] + a[i-1], pre1[i] += pre1[i - 1];
    }
    int sum = pre0[n] + pre1[n];
    set<int> S[2];
    int ans = 0;
    S[0].insert(0);
    rep(i, 1, n) {
        int dif = pre1[n] - pre0[n] + 2 * (pre0[i] - pre1[i]);
        if (S[i & 1].size()) {
            auto it = S[i & 1].lower_bound(dif);
            int d;
            if (it != S[i & 1].end())
                d = *it;
            if (it != S[i & 1].begin()) {
                auto idx = --it;
                if (abs(dif - d) > abs(dif - *idx))
                    d = *idx;
            }
            ans = max(ans, min((dif - d + sum) / 2, (sum - (dif - d)) / 2));
        }
        S[i & 1].insert(2 * (pre0[i] - pre1[i]));
    }
    cout << "Solver1: " << ans << endl;
}
} // namespace Solver1

// ==================== 第二个解法 ====================
namespace Solver2 {
const long long INF = 1e18;

long long getMinD(int n, vector<int>& a) {
    vector<long long> pre(2*n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        if (i % 2 == 1)
            a[i-1] = -a[i-1];
        pre[i] = pre[i - 1] + a[i-1];
    }

    long long mn = abs(pre[2 * n]);

    multiset<long long> ms;

    auto f = [&](long long x) {
        long long res = INF;
        auto it = ms.lower_bound(x);
        if (it != ms.end()) {
            res = min(res, (*it) - x);
        }
        if (it != ms.begin()) {
            it--;
            res = min(res, x - (*it));
        }
        return res;
    };

    ms = multiset<long long>();
    for (int i = 2 * n; i >= 2; i -= 2) {
        ms.insert(2 * pre[i]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i]));
    }

    ms = multiset<long long>();
    for (int i = 2 * n; i >= 2; i -= 2) {
        if (i + 1 <= 2 * n)
            ms.insert(2 * pre[i + 1]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i] - 2 * a[i-1]));
    }

    ms = multiset<long long>();
    for (int i = 2 * n - 1; i >= 1; i -= 2) {
        ms.insert(2 * pre[i]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i]));
    }

    ms = multiset<long long>();
    for (int i = 2 * n - 1; i >= 1; i -= 2) {
        if (i + 1 <= 2 * n)
            ms.insert(2 * pre[i + 1]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i] - 2 * a[i-1]));
    }

    for (int i = 1; i <= 2 * n; i++)
        if (i % 2 == 1)
            a[i-1] = -a[i-1];
    return mn;
}

void solve(int n, vector<int>& a) {
    long long sum = 0;
    for (int i = 0; i < 2 * n; i++)
        sum += a[i];

    vector<int> a_copy = a;
    long long ans = (sum - getMinD(n, a_copy)) / 2;

    reverse(a.begin(), a.end());
    ans = max(ans, (sum - getMinD(n, a)) / 2);

    cout << "Solver2: " << ans << endl;
}
} // namespace Solver2

// ==================== 随机数据生成与对拍 ====================
vector<int> generateRandomTest(int n) {
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        a[i] = rand() % 100 + 1; // 生成1-100的随机数
    }
    return a;
}

void printTest(int n, const vector<int>& a) {
    cout << "Test case:" << endl;
    cout << n << endl;
    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void compareSolutions() {
    srand(time(0));
    int testCases = 100;
    int maxN = 1; // 初始小数据测试
    
    for (int tc = 1; tc <= testCases; tc++) {
        if (tc % 20 == 0) maxN = min(100LL, maxN * 2); // 逐步增大数据规模
        
        int n = rand() % maxN + 1;
        vector<int> a = generateRandomTest(n);
        
        cout << "Test case #" << tc << " (n=" << n << ")" << endl;
        printTest(n, a);
        
        cout << "Results:" << endl;
        Solver1::solve(n, a);
        Solver2::solve(n, a);
        
        // 这里可以添加自动比较结果的逻辑
        // 如果结果不一致，可以暂停或保存测试用例
        
        cout << "------------------------" << endl;
    }
}

signed main() {
    compareSolutions();
    return 0;
}