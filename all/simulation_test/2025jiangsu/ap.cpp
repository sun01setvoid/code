#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int MAXM = 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, A, B;
    cin >> n >> m >> A >> B;
    int totalS = 1 << m;
    long long totalW = (long long)m * (m + 1) / 2;
    vector<int> cnt0(totalS, 0), w0(totalS, 0);
    vector<int> choices(totalS, 0);
    vector<long long> i0_arr(totalS, 0);

    for (int s = 0; s < totalS; s++) {
        for (int j = 0; j < m; j++) {
            if (s >> j & 1) {
                cnt0[s]++;
                w0[s] += (j + 1);
            }
        }
        int L = 2 * cnt0[s] - m;
        long long R = totalW - 2 * (long long)w0[s];
        long long k = (long long)A * L;
        long long c = (long long)B * R;

        if (k > 0) {
            if (c <= 0) {
                choices[s] = 0;
            } else {
                long long i0_val = (c - 1) / k + 1;
                if (i0_val > n) choices[s] = 1;
                else {
                    choices[s] = 2;
                    i0_arr[s] = i0_val;
                }
            }
        } else if (k < 0) {
            if (c > 0) {
                choices[s] = 1;
            } else {
                long long i0_val = c / k;
                if (i0_val < 1) choices[s] = 1;
                else if (i0_val >= n) choices[s] = 0;
                else {
                    choices[s] = 3;
                    i0_arr[s] = i0_val;
                }
            }
        } else {
            choices[s] = (c <= 0) ? 0 : 1;
        }
    }

    vector<vector<int>> groups(totalS);
    for (int i = 1; i <= n; i++) {
        string s_str;
        cin >> s_str;
        int r = 0;
        for (int j = 0; j < m; j++) {
            if (s_str[j] == '1') 
                r |= (1 << j);
        }
        groups[r].push_back(i);
    }

    vector<vector<long long>> prefix_arr(totalS);
    for (int r = 0; r < totalS; r++) {
        if (groups[r].empty()) continue;
        sort(groups[r].begin(), groups[r].end());
        long long sum = 0;
        for (int i = 0; i < groups[r].size(); i++) {
            sum += groups[r][i];
            prefix_arr[r].push_back(sum);
        }
    }

    long long ans = LLONG_MIN;
    for (int mask = 0; mask < totalS; mask++) {
        long long total = 0;
        for (int s = 0; s < totalS; s++) {
            int r = s ^ mask;
            if (groups[r].empty()) continue;
            vector<int>& rows = groups[r];
            vector<long long>& pre = prefix_arr[r];
            int n_rows = rows.size();
            long long sum_i = pre.back();

            if (choices[s] == 0) { 
                total += (long long)A * cnt0[s] * sum_i + (long long)B * w0[s] * n_rows;
            } else if (choices[s] == 1) {
                total += (long long)A * (m - cnt0[s]) * sum_i + (long long)B * (totalW - w0[s]) * n_rows;
            } else if (choices[s] == 2) { 
                int pos = lower_bound(rows.begin(), rows.end(), i0_arr[s]) - rows.begin();
                int cnt1 = pos;
                int cnt2 = n_rows - cnt1;
                long long sum1 = (cnt1 > 0) ? pre[cnt1 - 1] : 0;
                long long sum2 = sum_i - sum1;
                total += (long long)A * (m - cnt0[s]) * sum1 + (long long)B * (totalW - w0[s]) * cnt1;
                total += (long long)A * cnt0[s] * sum2 + (long long)B * w0[s] * cnt2;
            } else if (choices[s] == 3) {
                int pos = upper_bound(rows.begin(), rows.end(), i0_arr[s]) - rows.begin();
                int cnt1 = pos;
                int cnt2 = n_rows - cnt1;
                long long sum1 = (cnt1 > 0) ? pre[cnt1 - 1] : 0;
                long long sum2 = sum_i - sum1;
                total += (long long)A * cnt0[s] * sum1 + (long long)B * w0[s] * cnt1;
                total += (long long)A * (m - cnt0[s]) * sum2 + (long long)B * (totalW - w0[s]) * cnt2;
            }
            debug(mask);debug(r);debug(total);
        }
        if (total > ans) ans = total;
    }
    cout << ans << endl;
    return 0;
}