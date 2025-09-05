// 有0有1->1
// 全为0，全为1->1

//|增，&减，整体增，每个位整体增，最多有O（m)种值
#include <bits/stdc++.h>
#define int long long
#define INF LLONG_MIN
using namespace std;
const int N = 1e5 + 10, M = 21;
int a[N], g[1 << M];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> vec;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= (1 << m) - 1; i++)
        cin >> g[i];
    dp[0] = 0;
    vec.push_back({0, (1 << m) - 1, 0});
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INF;
        for (auto &[p, s, t] : vec)
        {
            s &= a[i];
            t |= a[i];
            dp[i] = max(dp[i], p + g[t - s]);
        }
        auto tmp = vec;
        vec.clear();
        for (int i = 0; i < (int)tmp.size(); ++i)
            if (vec.empty() || get<1>(vec.back()) != get<1>(tmp[i]) || get<2>(vec.back()) != get<2>(tmp[i]))
            {
                vec.push_back(tmp[i]);
            }
            else    get<0>(vec.back()) = max(get<0>(vec.back()),get<0>(tmp[i]));
        vec.push_back({dp[i], (1 << m) - 1, 0});
    }
    cout << dp[n] << "\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}