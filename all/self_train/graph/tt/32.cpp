//无向图欧拉回路 P1341无序字母对
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vector<pii>> g(maxn);
bool used[2 * maxn];
int del[maxn], d[maxn];
stack<int> stk;
bool vis[maxn], has[maxn];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = del[u]; i < g[u].size(); i = del[u])
    {
        del[u] = i + 1;
        if (used[g[u][i].se / 2])
            continue;
        int v = g[u][i].fi;
        used[g[u][i].se / 2] = 1;
        dfs(v);
    }
    stk.push(u);
}
void solve()
{
    string s;
    int n;
    cin >> n;
    int st = 51;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int a, b;
        if (s[0] >= 'a' && s[0] <= 'z')
            a = s[0] - 'a' + 26;
        else
            a = s[0] - 'A';
        if (s[1] >= 'a' && s[1] <= 'z')
            b = s[1] - 'a' + 26;
        else
            b = s[1] - 'A';
        d[a]++, d[b]++;
        has[a] = has[b] = 1;
        st = min(st, min(a, b));
        g[a].pb({b, 2 * i});
        g[b].pb({a, 2 * i + 1});
    }
    // 直接存边再排序是一种思路，但是我们要思考一下怎么找到相关边的位置，感觉是nlogn
    // 我们这里只需要标识边的编号，就好，所以不必这么做
    int ct = 0;
    for (int i = 51; i >= 0; i--)
    {
        if (d[i] & 1)
        {
            ct++;
            st = i;
        }
    }
    if (ct != 0 && ct != 2)
    {
        cout << "No Solution" << endl;
        return;
    }
    for (int i=0;i<=51;i++) sort(g[i].begin(),g[i].end());
    dfs(st);
    for (int i = 0; i <= 51; i++)
    {
        if (has[i] && !vis[i])
        {
            cout << "No Solution" << endl;
            return;
        }
    }
    while (!stk.empty())
    {
        int t = stk.top();
        if (t >= 0 && t <= 25)
            cout << (char)(t + 'A');
        else
            cout << (char)(t - 26 + 'a');
        stk.pop();
    }
    cout << endl;
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