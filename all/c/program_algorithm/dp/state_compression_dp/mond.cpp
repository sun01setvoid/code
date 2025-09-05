// 轮廓线dp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[2][1 << 11];

// 状压dp是从转移需要什么来看状态
// 轮廓线主要从转移的幅度来看状态

// s的digit表示这一行是否已被覆盖
// s是不同行的j列点的状态压缩
// 也就是说存的是以这个点长度为起始点为m的段的状态，然后再根据这个状态做正向递推
// 这样就可以保证不超出去边界
signed main()
{
    IOS;
    int n, m;
    while (cin >> n >> m && n)
    {
        fill(dp[0], dp[0] + (1 << m), 0);
        fill(dp[1], dp[1] + (1 << m), 0);
        dp[0][0] = 1;
        // 初始状态是第一行
        // 正向递推
        int st = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                fill(dp[st], dp[st] + (1 << m), 0);
                for (int s = 0; s < 1 << m; s++)
                {
                    if (s >> j & 1)
                    {
                        dp[st][s ^ (1 << j)] += dp[st ^ 1][s]; // 下一行不被覆盖
                    }
                    else
                    {
                        if (j != m - 1 && !(s >> j & 3))
                            dp[st][s ^ (1 << (j + 1))] += dp[st ^ 1][s];
                        dp[st][s ^ (1 << j)] += dp[st ^ 1][s];
                    }
                }
                st = st ^ 1;
            }
        }
        st = st ^ 1;
        cout << dp[st][0] << endl;
    }
    return 0;
}