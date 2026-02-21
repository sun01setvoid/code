// P1333 瑞瑞的木棍
//实际上把这个木棍看成边更好，两端之间就是两个点，代表了连接
//后连前，那么意思就是有向边
//那感觉后面的答案好像稍稍有点问题，应该是无向边才对哎
//不管了，无序字母对和这个一样
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
vector<vii> g(maxn);
int d[maxn];
unordered_map<string, vii> mp1;
unordered_map<string, vii> mp2;
signed main()
{
    IOS;
    string a, b;
    int cnt = 0;
    while (cin >> a >> b)
    {
        ++cnt;
        mp1[a].pb(cnt);
        mp2[b].pb(cnt);
    }
    int ct0 = 0, ct1 = 0;
    int ncnt = cnt;
    for (auto &[s, v1] : mp1)
    {
        int n1 = v1.size();
        auto v2 = mp2[s];
        int n2 = v2.size();
        if (n2 == 0)
        {
            continue;
        }
        ++ncnt;
        for (auto x : v1)
            d[x] += n2, g[x].pb(ncnt), g[ncnt].pb(x);
        for (auto x : v2)
            d[x] += n1, g[ncnt].pb(x), g[x].pb(ncnt);
    }
    vector<bool> vis(ncnt + 1, 0);
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (!vis[i])
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (d[i] & 1)
            ct1++;
        else
            ct0++;
    }
    if (ct0 != cnt - 2 && ct0 != cnt)
    {
        cout << "Impossible" << endl;
    }
    else
        cout << "Possible" << endl;
    return 0;
}