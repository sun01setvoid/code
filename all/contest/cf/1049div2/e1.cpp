#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vii vector <int,int>
// 你的第一个代码（Raze） - 修改为从字符串流读取
void Raze(istream& in) {
    int n;
    in >> n;
    vector<pair<int, int>> tmp;
    tmp.push_back({-1, -1});
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l, r;
        in >> l >> r;
        tmp.push_back({l, r});
        ans += r - l;
    }
    
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.first + a.second < b.first + b.second;
    };
    sort(tmp.begin() + 1, tmp.end(), cmp);
    
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            int l1 = tmp[i].first, r1 = tmp[i].second;
            int l2 = tmp[n - i + 1].first, r2 = tmp[n - i + 1].second;
            ans += max(r2 - l1, r1 - l2);
        }
        cout << ans << endl;
        return;
    }
    
    vector<vector<int>> add(n + 1, vector<int>(4, 0));
    for (int i = 1; i <= n; i++) {
        if (i == (n + 1) / 2) {
            int pos = n - i + 1;
            for (int j = 1; j <= 3; j++) {
                if (j == 2) continue;
                int p = pos + j - 2;
                if (p >= 1 && p <= n) {
                    int l1 = tmp[i].first, r1 = tmp[i].second;
                    int l2 = tmp[p].first, r2 = tmp[p].second;
                    add[i][j] = max(r1 - l2, r2 - l1);
                }
            }
        } else {
            int pos = n - i + 1;
            for (int j = 1; j <= 3; j++) {
                int p = pos + j - 2;
                if (p >= 1 && p <= n) {
                    int l1 = tmp[i].first, r1 = tmp[i].second;
                    int l2 = tmp[p].first, r2 = tmp[p].second;
                    add[i][j] = max(r1 - l2, r2 - l1);
                }
            }
        }
    }
    
    vector<int> pre1(n + 2, 0), pre2(n + 2, 0), pre3(n + 2, 0);
    vector<int> suf1(n + 2, 0), suf2(n + 2, 0), suf3(n + 2, 0);
    
    for (int i = 1; i <= (n + 1) / 2; i++) {
        pre1[i] = pre1[i - 1] + add[i][1];
        pre2[i] = pre2[i - 1] + add[i][2];
        pre3[i] = pre3[i - 1] + add[i][3];
    }
    
    for (int i = (n + 1) / 2; i >= 1; i--) {
        suf1[i] = suf1[i + 1] + add[i][1];
        suf2[i] = suf2[i + 1] + add[i][2];
        suf3[i] = suf3[i + 1] + add[i][3];
    }
    
    int res = ans, mid = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        int sum = ans;
        if (i <= mid) {
            sum += pre2[i] + suf3[i + 1];
            sum -= add[i][2];
        } else {
            sum += pre2[n - i + 1] + suf1[n - i + 2];
            sum -= add[i][2];
        }
        res = max(res, sum);
    }
    cout << res << endl;
}

// 你的第二个代码（solve） - 修改为从字符串流读取
void solve(istream& in) {
    int n;
    in >> n;
    vector<pair<int, int>> vc(n);
    for (int i = 0; i < n; i++) {
        in >> vc[i].first >> vc[i].second;
    }
    
    int ans = 0;
    for (auto &p : vc) {
        ans += (p.second - p.first);
    }
    
    vector<int> t1(n), t2(n), idx(n), a1(n), a2(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        t1[i] = vc[i].first + vc[i].second;
        t2[i] = vc[i].second;
        tot += t2[i];
        idx[i] = i;
    }
    
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return t1[i] < t1[j];
    });
    
    for (int i = 0; i < n; i++) {
        a1[i] = t1[idx[i]];
        a2[i] = t2[idx[i]];
    }
    
    int tmp = -1e18;
    if (n % 2 == 0) {
        int m = n / 2;
        int res = 0;
        for (int i = 0; i < m; i++) {
            res += a1[i];
        }
        tmp = tot - res;
    } else {
        int m = (n - 1) / 2;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a1[i];
        }
        
        if (m == 0) {
            tmp = 0;
        } else {
            tmp = -1e18;
            for (int k = 0; k < n; k++) {
                int res = tot - a2[k], mi;
                if (k >= m) {
                    mi = pre[m];
                } else {
                    mi = pre[m + 1] - a1[k];
                }
                tmp = max(tmp, res - mi);
            }
        }
    }
    
    ans += max(0LL, tmp);
    cout << ans << endl;
}

// 生成随机测试数据
string generate_test(int n) {
    stringstream ss;
    ss << n << endl;
    for (int i = 0; i < n; i++) {
        int l = rand() % 100 + 1;
        int r = l + rand() % 100 + 1;
        ss << l << " " << r << endl;
    }
    return ss.str();
}

// 运行程序并获取输出
string run_program(void (*program)(istream&), const string &input) {
    stringstream in_stream(input);
    stringstream out_stream;
    
    // 保存原来的cin和cout缓冲区
    streambuf* cin_backup = cin.rdbuf();
    streambuf* cout_backup = cout.rdbuf();
    
    // 重定向到字符串流
    cin.rdbuf(in_stream.rdbuf());
    cout.rdbuf(out_stream.rdbuf());
    
    // 运行程序
    program(cin);
    
    // 恢复原来的缓冲区
    cin.rdbuf(cin_backup);
    cout.rdbuf(cout_backup);
    
    return out_stream.str();
}

signed main() {
    srand(time(0));
    int test_count = 1000; // 测试次数
    
    for (int i = 1; i <= test_count; i++) {
        cout << "Test " << i << ": ";
        int n = rand() % 10 + 1; // 随机n从1到10
        
        string input = generate_test(n);
        
        string output1 = run_program(Raze, input);
        string output2 = run_program(solve, input);
        
        // 去除可能的换行符
        if (!output1.empty() && output1.back() == '\n') output1.pop_back();
        if (!output2.empty() && output2.back() == '\n') output2.pop_back();
        
        if (output1 != output2) {
            cout << "Error found!" << endl;
            cout << "Input:" << endl;
            cout << input;
            cout << "Raze output: " << output1 << endl;
            cout << "Solve output: " << output2 << endl;
            return 0;
        } else {
            cout << "Passed" << endl;
        }
    }
    
    cout << "All tests passed!" << endl;
    return 0;
}