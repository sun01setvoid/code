#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int dp[N][N];
// 可以有负权边，但不能有负权回路
int main()
{
    int n, m, from, to, value;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> value;
        dp[from][to] = value;
    }
    memset(dp, 0x3f, sizeof dp);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
    for (int i = 0; i < n; i++)
        cout << dp[i][i] << endl;
    getchar();
    getchar();
}