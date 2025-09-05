#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5 + 10;
int num[N], ma[N], mi[N];
int h[N], e[N], ne[N], idx;
int n;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u, int fa)
{
    if (u == fa)
        ma[u] = num[u], mi[u] = 0;
    else
    {
        ma[u] = max(num[u], num[u] - mi[fa]);
        mi[u] = min(num[u], num[u] - ma[fa]);
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        dfs(j, u);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        idx = 0;
        for (int i = 1; i <= n; i++)
        {
            h[i] = -1;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            add(a, b);
            add(b, a);
        }
        dfs(1, 1);
        for (int i = 1; i <= n; i++)
        {
            cout << ma[i] << " ";
        }
        cout << endl;
    }
    return 0;
}