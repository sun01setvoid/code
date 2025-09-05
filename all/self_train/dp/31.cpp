// P5658 括号树
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
stack<int> stk;
// 括号序列匹配考虑栈
// 算树形dp吗？但树状的结构确实好处理一些
vector<vii> adj(maxn);
int n, ans;
int dp1[maxn], dp2[maxn], f[maxn];
// dp1是以u为底的,dp2是不一定以它为底的
string s;
void dfs(int u)
{
    int tp = stk.top();
    bool flag = 0;
    bool f1 = 0;
    dp2[u] = dp2[f[u]];
    if (s[u] == '(')
    {
        stk.push(u);
        f1 = 1;
    }
    else
    {
        if (stk.size() > 1)
        {
            stk.pop();
            flag = 1;
            dp1[u] = dp1[f[tp]] + 1;
            dp2[u] += dp1[u];
        }
    }
    ans ^= (u * dp2[u]);
    // debug(u);debug(dp2[u]);debug(dp1[u]);
    for (auto &v : adj[u])
    {
        dfs(v);
    }
    if (flag)
        stk.push(tp);
    if (f1)
        stk.pop();
}
void solve()
{
    cin >> n;
    string tmp;
    cin >> tmp;
    s = "#" + tmp;
    while (stk.size())
        stk.pop();
    stk.push('&');
    rep(i, 2, n)
    {
        int x;
        cin >> x;
        adj[x].pb(i);
        f[i] = x;
    }
    dfs(1);
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