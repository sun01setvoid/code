#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int mp[55][55];
int vis[55][55];
int n, m;
void dfs(int x, int y)
{
    vis[x][y]=1;
    for (int i = 0; i < 4; i++)
    {
        int xi = x + dir[i][0];
        int yi = y + dir[i][1];
        if (xi < 1 || xi > n || yi < 1 || yi > m)
            continue;
        if (!vis[xi][yi] && mp[xi][yi] == mp[x][y])
            dfs(xi, yi);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j])
               dfs(i, j), cnt++;
        }
    cout << cnt;
}
