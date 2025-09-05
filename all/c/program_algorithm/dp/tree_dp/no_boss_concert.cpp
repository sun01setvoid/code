// lg P1352
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 6010;
int n;
int dp[N][2], v[N]; // 有上司和没上司
int d[N];
vector<int> G[N];
void dfs(int u, int fa)
{
    for (auto t : G[u])
    {
        dfs(t, u);
        dp[u][0] += max(dp[t][1], dp[t][0]);
        dp[u][1] += dp[t][0];
    }
}
int main()
{
    int a, b, rt;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n - 1; i++)
        cin >> a >> b, G[b].push_back(a), d[a]++;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
        {
            rt = i;
            break;
        }
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0, dp[i][1] = v[i]; // 初始化
    dfs(rt, 0);
    cout << max(dp[rt][0], dp[rt][1]);
}