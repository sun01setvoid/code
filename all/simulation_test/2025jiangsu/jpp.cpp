#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define fi first
#define so second
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
const int maxn = 1e5 + 5;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct oo
{
    
};
int n, m, k, a[maxn];
vector<pair<int, int>>mp[maxn];
int min(int x, int y) { return x <= y ? x : y; }
void solve()
{
    cin >> n >> m >> k; vector<int>ans(n + 1, INF);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)ans[i] = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b; cin >> a >> b;
        for (int j = 1; j <= b; j++)
        {
            int x; cin >> x; ans[x] = min(ans[x], a);
        }
    }
    vector<int>in(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        mp[u].push_back({ v,w }); in[v]++;
    }
    vector<int>unable(n + 1, 0);
    vector<multiset<int>>st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (in[i] < a[i])unable[i] = 1;
    }
    priority_queue<pii, vector<pii>, greater<pii>>q;
    vector<int>used(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != INF)q.push({ ans[i],i });
    }
    while (q.size())
    {
        auto now = q.top(); q.pop();
        int ti = now.fi, u = now.so; used[u] = 1;
        //debug(u); debug(ti);
        ans[u] = min(ans[u], ti);
        for (auto nex : mp[u])
        {
            int v = nex.fi, w = nex.so;
            if (unable[v]||used[v])continue;
            int val = ti + w; //debug(val);
            if (st[v].size() < a[v])
            {
                st[v].insert(val);
            }
            else
            {
                auto tmp = prev(st[v].end());
                if (*tmp > val)
                {
                    st[v].erase(tmp);
                    st[v].insert(val);
                }
            }
            if (st[v].size() == a[v])
            {
                if (ans[v] > *st[v].rbegin())
                    q.push({ *st[v].rbegin(),v }), ans[v] = *st[v].rbegin();
            }
        }
    }
    //debug(unable[6]);
    //debug(st[6].size());
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == INF)cout << "-1 ";
        else cout << ans[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); int _ = 1;
    //cin >> _;
    while (_--)solve(); return 0;
}