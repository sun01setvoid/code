#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, m;
vector<vii> g(maxn);
int d[maxn];
int del[maxn];
vii ans;
void dfs(int u)
{
    for (int i = del[u]; i < g[u].size(); i = del[u])
    {
        del[u] = i + 1;
        dfs(g[u][i]);
    }
    ans.pb(u);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        d[u]++;
        d[v]--;
    }
    // if (n==1 && m==0){   //这东西需要吗
    //     cout<<"NO"<<endl;
    //     return;
    // }
    int s = 1, t = 1, cnt;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1)
            s = i;
        else if (d[i] == -1)
            t = i;
        else if (d[i] == 0)
            cnt++;
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    if (cnt!=n-2 && cnt!=n){
        cout<<"No"<<endl;
        return;
    }
    queue<int> q;
    vector<bool> vis(n + 1);
    q.push(s);
    vis[s] = 1;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) // 使字典序最小
        sort(g[i].begin(), g[i].end());
    dfs(s);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}