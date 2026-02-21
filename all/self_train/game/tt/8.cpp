
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
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int gd[maxn];
vector<vii> adj(maxn);
int sg(int u)
{
    if (gd[u] != -1)
        return gd[u];
    set<int> s;
    for (auto v : adj[u])
    {
        int t = sg(v);
        s.insert(t);
    }
    for (int i = 0;; i++)
    {
        if (!s.count(i))
        {
            gd[u] = i;
            break;
        }
    }
    return gd[u];
}
void solve()
{
    memset(gd, -1, sizeof gd);
    int n;
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            adj[i].pb(x);
        }
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (gd[i] == -1)
            sg(i);
    }
    int m;
    while (cin >> m && m)
    {
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            ans ^= gd[x];
        }
        if (ans)
            cout << "WIN" << endl;
        else
            cout << "LOSE" << endl;
    }
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