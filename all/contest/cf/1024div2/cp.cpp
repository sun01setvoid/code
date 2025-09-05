#include <bits/stdc++.h>
using namespace std;
const int N = 250010, M = 510;
struct node
{
    int x, y, val;
    bool operator>(const node &a) const
    {
        return val > a.val;
    }
} a[N];
int mp[M][M];
int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[cnt].x = i;
                a[cnt].y = j;
                a[cnt].val = i * (n - i + 1) * j * (n - j + 1);
                cnt++;
            }
        }
        sort(a, a + cnt, greater<node>());
        for (int i = 0; i < n * n; i++)
        {
            mp[a[i].x][a[i].y] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << mp[i][j] << " ";
            }
            cout << "\n";
        }
    }
}//xxxxx