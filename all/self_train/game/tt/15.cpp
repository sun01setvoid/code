//求区间mex
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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vii> adj(maxn);
int n, m, Q, sg[maxn];
int B;
int cnt[maxn];
int mex = 0;
struct oo
{
    int l, r, id;
    bool operator<(const oo &other) const
    {
        if (l / B != other.l / B)
            return l / B < other.l / B;
        else
            return r / B < other.r / B;
    }
} q[maxn];
void add(int x)
{
    if (++cnt[x] == 1)
    {
        while (cnt[mex])
        {
            mex++;
        }
    }
}
void del(int x)
{
    if (--cnt[x] == 0)
    {
        mex = min(mex, x);
    }
}
void solve()
{
    memset(sg, -1, sizeof sg);
    cin >> n >> m >> Q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    int mx = 0;
    map<int, int> ma;
    for (int i = 1; i <= n; i++) //给定删除的边那就删掉删除的那些sg值，不过每轮开始的sg值也是要维护的
    {
        int mini = mx;
        for (int j = 0; j < adj[i].size(); j++)
        {
            ma[sg[adj[i][j]]]--;
            if (ma[sg[adj[i][j]]] == 0)
            {
                mini = min(mini, sg[adj[i][j]]);
            }
        }
        sg[i] = mini;
        for (int j = 0; j < adj[i].size(); j++)
        {
            ma[sg[adj[i][j]]]++;
        }
        ma[sg[i]]++;
        while (ma[mx] >= 1)
        {
            mx++;
        }
    }
    B = sqrt(n);
    vector<int> ans(Q + 1);
    for (int i = 1; i <= Q; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + Q);
    int nl = q[1].l, nr = q[1].l - 1;
    for (int i = 1; i <= Q; i++)
    {
        int l = q[i].l, r = q[i].r, id = q[i].id;
        while (nr < r)
        {
            if (sg[nr + 1] <= n && sg[nr + 1] >= 0)
                add(sg[++nr]);
        }
        while (nl > l)
        {
            if (sg[nl - 1] <= n && sg[nl - 1] >= 0)
                add(sg[--nl]);
        }
        while (nr > r)
        {
            if (sg[nr] <= n && sg[nr] >= 0)
                del(sg[nr--]);
        }
        while (nl < l)
        {
            if (sg[nl] <= n && sg[nl] >= 0)
                del(sg[nl++]);
        }
        ans[id] = mex;
    }
    int res = 0;
    for (int i = 1; i <= Q; i++)
    {
        res ^= ans[i];
    }
    if (res)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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