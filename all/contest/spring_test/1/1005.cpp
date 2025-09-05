#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
struct node
{
    int from;
    int x;
    int y;
};
typedef pair<ll, node> PII;
bool operator>(const pair<ll, node> &a, const pair<ll, node> &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second.from > b.second.from;
}
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1, n, m;
    cin >> t;
    while (t--)
    {
        ll ans = 0x3f3f3f3f3f3f3f3f;
        cin >> n >> m;
        vector<vector<ll>> t(n + 1, vector<ll>(m + 1)); // 通过
        vector<vector<ll>> d(n + 1, vector<ll>(m + 1)); // 转向
        vector<vector<vector<ll>>> dist(n + 1, vector<vector<ll>>(m + 1, vector<ll>(4, 0x3f3f3f3f3f3f3f3f)));
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> t[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> d[i][j];
        heap.push({0, {0, 1, 1}});
        while (heap.size())
        {
            auto tp = heap.top();
            heap.pop();
            ll dis = tp.first;
            node s = tp.second;
            int from = s.from;
            int x = s.x;
            int y = s.y;
            if (x == n && y == m && from == 1)
            {
                ans = dis+t[x][y];
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                if (i != from && dis + d[x][y] < dist[x][y][i])
                    dist[x][y][i] = dis + d[x][y], heap.push({dist[x][y][i], {i, x, y}});
                else if (i == from)
                {
                    int xi = x + dir[i][0];
                    int yi = y + dir[i][1];
                    if (xi < 1 || xi > n || yi < 1 || yi > m)
                        continue;
                    if ( dis + t[x][y] < dist[xi][yi][i])
                        dist[xi][yi][i] = dis + t[x][y], heap.push({dist[xi][yi][i], {i, xi, yi}});
                }
            }
        }
        cout << ans << endl;
    }
}
