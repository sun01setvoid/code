#include <bits/stdc++.h>
using namespace std;

#define int long long

// 修正后的正确代码
int solve_correct(int n, int m, int A, int B, vector<string> &grid)
{
    int totalS = 1 << m;
    long long totalW = (long long)m * (m + 1) / 2;

    vector<int> cnt0(totalS, 0), w0(totalS, 0);
    vector<int> choices(totalS, 0);
    vector<long long> i0_arr(totalS, 0);

    for (int s = 0; s < totalS; s++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s >> j & 1)
            {
                cnt0[s]++;
                w0[s] += (j + 1);
            }
        }
        int L = 2 * cnt0[s] - m;
        long long R = totalW - 2 * (long long)w0[s];
        long long k = (long long)A * L;
        long long c = (long long)B * R;

        if (k > 0)
        {
            if (c <= 0)
            {
                choices[s] = 0;
            }
            else
            {
                long long i0_val = (c - 1) / k + 1;
                if (i0_val > n)
                    choices[s] = 1;
                else
                {
                    choices[s] = 2;
                    i0_arr[s] = i0_val;
                }
            }
        }
        else if (k < 0)
        {
            if (c > 0)
            {
                choices[s] = 1;
            }
            else
            {
                long long i0_val = c / k;
                if (i0_val < 1)
                    choices[s] = 1;
                else if (i0_val >= n)
                    choices[s] = 0;
                else
                {
                    choices[s] = 3;
                    i0_arr[s] = i0_val;
                }
            }
        }
        else
        {
            choices[s] = (c <= 0) ? 0 : 1;
        }
    }

    vector<vector<int>> groups(totalS);
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
                r |= (1 << j);
        }
        groups[r].push_back(i + 1);
    }

    vector<vector<long long>> prefix_arr(totalS);
    for (int r = 0; r < totalS; r++)
    {
        if (groups[r].empty())
            continue;
        sort(groups[r].begin(), groups[r].end());
        long long sum = 0;
        for (int i = 0; i < groups[r].size(); i++)
        {
            sum += groups[r][i];
            prefix_arr[r].push_back(sum);
        }
    }

    long long ans = LLONG_MIN;
    for (int mask = 0; mask < totalS; mask++)
    {
        long long total = 0;
        for (int s = 0; s < totalS; s++)
        {
            int r = s ^ mask;
            if (groups[r].empty())
                continue;

            vector<int> &rows = groups[r];
            vector<long long> &pre = prefix_arr[r];
            int n_rows = rows.size();
            long long sum_i = pre.back();

            if (choices[s] == 0)
            {
                total += (long long)A * cnt0[s] * sum_i + (long long)B * w0[s] * n_rows;
            }
            else if (choices[s] == 1)
            {
                total += (long long)A * (m - cnt0[s]) * sum_i + (long long)B * (totalW - w0[s]) * n_rows;
            }
            else if (choices[s] == 2)
            {
                int pos = lower_bound(rows.begin(), rows.end(), i0_arr[s]) - rows.begin();
                int cnt1 = pos;
                int cnt2 = n_rows - cnt1;
                long long sum1 = (cnt1 > 0) ? pre[cnt1 - 1] : 0;
                long long sum2 = sum_i - sum1;
                total += (long long)A * (m - cnt0[s]) * sum1 + (long long)B * (totalW - w0[s]) * cnt1;
                total += (long long)A * cnt0[s] * sum2 + (long long)B * w0[s] * cnt2;
            }
            else if (choices[s] == 3)
            {
                int pos = upper_bound(rows.begin(), rows.end(), i0_arr[s]) - rows.begin();
                int cnt1 = pos;
                int cnt2 = n_rows - cnt1;
                long long sum1 = (cnt1 > 0) ? pre[cnt1 - 1] : 0;
                long long sum2 = sum_i - sum1;
                total += (long long)A * cnt0[s] * sum1 + (long long)B * w0[s] * cnt1;
                total += (long long)A * (m - cnt0[s]) * sum2 + (long long)B * (totalW - w0[s]) * cnt2;
            }
        }
        if (total > ans)
            ans = total;
    }
    return ans;
}

// 您的原始代码（稍作修改以接受参数）
int solve_your_code(int n, int m, int A, int B, vector<string> &grid)
{
    vector<int> cnt(1 << m, 0), w(1 << m, 0), pos(1 << m, -1), f(1 << m);
    vector<vector<int>> idx(1 << m), presum(1 << m);

    for (int i = 0; i < (1 << m); i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if ((i >> j) & 1)
                ++cnt[i], w[i] += m - j;
        }
        f[i] = i;
        if (A * (m - 2 * cnt[i]) > 0)
        {
            if (A * n * (m - 2 * cnt[i]) + B * ((m + 1) * m / 2 - 2 * w[i]) <= 0)
                continue;
            int l = 1, r = n;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (A * mid * (m - 2 * cnt[i]) + B * ((m + 1) * m / 2 - 2 * w[i]) > 0)
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            pos[i] = l;
        }
        else
        {
            if (A * 1 * (m - 2 * cnt[i]) + B * ((m + 1) * m / 2 - 2 * w[i]) <= 0)
                continue;
            int l = 1, r = n;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (A * mid * (m - 2 * cnt[i]) + B * ((m + 1) * m / 2 - 2 * w[i]) > 0)
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            pos[i] = r;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
                num |= (1 << (m - 1 - j));
        }
        idx[f[num]].push_back(i + 1);
    }

    for (int i = 0; i < (1 << m); i++)
    {
        int sum = 0;
        for (int j = 0; j < idx[f[i]].size(); j++)
        {
            sum += idx[f[i]][j];
            presum[f[i]].push_back(sum);
        }
    }

    int ans = LLONG_MIN;
    for (int i = 0; i < (1 << m); i++)
    {
        vector<int> vis(1 << m, 0);
        for (int j = 0; j < (1 << m); j++)
        {
            if (!vis[j] && !vis[i ^ j])
                swap(f[j], f[i ^ j]), vis[j] = vis[i ^ j] = 1;
        }

        int sum = 0;
        for (int j = 0; j < (1 << m); j++)
        {
            if (idx[f[j]].empty())
                continue;
            if (pos[j] != -1)
            {
                if (A * (m - 2 * cnt[j]) > 0)
                {
                    auto t = lower_bound(idx[f[j]].begin(), idx[f[j]].end(), pos[j]);
                    if (t == idx[f[j]].end())
                        continue;
                    int cur = t - idx[f[j]].begin();
                    sum += (cur - 1 >= 0) ? A * presum[f[j]][cur - 1] * cnt[j] + B * w[j] * cur : 0;
                    sum += A * (presum[f[j]].back() - ((cur - 1 >= 0) ? presum[f[j]][cur - 1] : 0)) * (m - cnt[j]) + B * ((m + 1) * m / 2 - w[j]) * (idx[f[j]].size() - cur);
                }
                else
                {
                    auto t = upper_bound(idx[f[j]].begin(), idx[f[j]].end(), pos[j]);
                    if (t == idx[f[j]].begin())
                        continue;
                    int cur = --t - idx[f[j]].begin();
                    sum += (cur + 1 <= (int)presum[f[j]].size() - 1) ? A * (presum[f[j]].back() - presum[f[j]][cur]) * cnt[j] + B * w[j] * (idx[f[j]].size() - cur - 1) : 0;
                    sum += A * presum[f[j]][cur] * (m - cnt[j]) + B * ((m + 1) * m / 2 - w[j]) * (cur + 1);
                }
            }
            else
            {
                sum += A * presum[f[j]].back() * cnt[j] + B * w[j] * idx[f[j]].size();
            }
        }
        ans = max(ans, sum);

        for (int j = 0; j < (1 << m); j++)
            vis[j] = 0;
        for (int j = 0; j < (1 << m); j++)
        {
            if (!vis[j] && !vis[i ^ j])
                swap(f[j], f[i ^ j]), vis[j] = vis[i ^ j] = 1;
        }
    }
    return ans;
}

// 随机数据生成器
void generate_test_case(int &n, int &m, int &A, int &B, vector<string> &grid)
{
    // 随机生成n, m (m较小)
    n = rand() % 3 + 1; // 1-10行
    m = rand() % 2 + 1; // 1-3列

    // 随机生成A, B
    A = (rand() % 21) - 10; // -10到10
    B = (rand() % 21) - 10;

    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        grid[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = (rand() % 2) ? '1' : '0';
        }
    }
}

void print_test_case(int n, int m, int A, int B, vector<string> &grid)
{
    cout << "Test case:\n";
    cout << n << " " << m << " " << A << " " << B << "\n";
    for (string &row : grid)
    {
        cout << row << "\n";
    }
    cout << endl;
}

signed main()
{
    srand(time(0));
    int test_num = 100;
    bool all_passed = true;

    for (int t = 1; t <= test_num; t++)
    {
        int n, m, A, B;
        vector<string> grid;
        generate_test_case(n, m, A, B, grid);

        int correct = solve_correct(n, m, A, B, grid);
        int yours = solve_your_code(n, m, A, B, grid);

        if (correct != yours)
        {
            all_passed = false;
            cout << "Test case #" << t << " failed!\n";
            print_test_case(n, m, A, B, grid);
            cout << "Correct answer: " << correct << "\n";
            cout << "Your answer: " << yours << "\n\n";
        }
    }

    if (all_passed)
    {
        cout << "All " << test_num << " test cases passed!\n";
    }
    else
    {
        cout << "Some test cases failed. See above for details.\n";
    }

    return 0;
}