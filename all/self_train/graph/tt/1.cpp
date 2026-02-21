// P2261 信息传递
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
//tarjan
int ne[maxn];
bool ins[maxn];
int dfn[maxn], low[maxn], stk[maxn], ts, top;
int ans = inf;
void tarjan(int u)
{
    dfn[u] = low[u] = ++ts;
    stk[++top] = u, ins[u] = 1;
    int v = ne[u];
    if (!dfn[v])
    {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    else if (ins[v])
    {
        low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int y;
        int cnt = 0;
        do
        {
            y = stk[top--], ins[y] = 0;
            cnt++;
        } while (y != u);
        if (cnt != 1)
            ans = min(ans, cnt);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ne[i];
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
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