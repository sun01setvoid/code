
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
int a[maxn];
int pre[maxn], d[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id, len;
        cin >> id >> len;
        a[id] = len;
        int x;
        while (cin >> x && x)
        {
            g[x].pb(id);
            d[id]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur])
        {
            d[v]--;
            pre[v] = max(pre[v], pre[cur] + a[cur]);
            if (d[v] == 0)
                q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] + a[i] > ans)
            ans = pre[i] + a[i];
    }
    cout << ans << endl;
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