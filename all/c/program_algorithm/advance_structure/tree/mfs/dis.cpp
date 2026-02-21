#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define fi first
#define se second
#define endl '\n'
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << endl
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
const int mod = 998244353;
int p[maxn], dis[maxn];
int find(int u)
{
    if (p[u] != u)
    {
        int fa = p[u], w = dis[u];
        p[u] = find(p[u]);
        dis[u] = dis[fa] + w;
    }
    return p[u];
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n + 1; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        int u = find(l), v = find(r + 1);
        if (u != v)
        {
            p[u] = v;
            dis[u] = dis[r+1] + s - dis[l];//注意这里要用原值来更新
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int u = find(l), v = find(r + 1);
        if (u != v)
        {
            cout << "UNKNOWN" << endl;
        }
        else
        {
            cout << dis[l] - dis[r+1] << endl;//注意要用dis[l],dis[r]
        }
    }
}
signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}