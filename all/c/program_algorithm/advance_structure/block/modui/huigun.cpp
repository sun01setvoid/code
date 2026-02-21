//回滚莫队
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int w[maxn], cnt[maxn], be[maxn], nums[maxn], val[maxn];
int ans[maxn];
int len;
struct node
{
    int l, r, id;
    bool operator<(const node &p)
    {
        if (be[l] != be[p.l])
            return be[l] < be[p.l];
        return r < p.r;
    }
} q[maxn];
void add(int x, int &res)
{
    cnt[x]++;
    res = max(res, cnt[x] * val[x]);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    len = sqrt(n);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        cin >> nums[i], mp[nums[i]]++, be[i] = i / len;
    int tot = 0;
    for (auto &x : mp)
    {
        x.se = ++tot;
        val[tot] = x.fi;
    }
    for (int i = 1; i <= n; i++)
        w[i] = mp[nums[i]];
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    for (int x = 1; x <= m;)
    {
        int y = x;
        while (y <= m && be[q[y].l] == be[q[x].l])
            y++;
        int ri = be[q[x].l] * len + len - 1;
        while (x < y && q[x].r <= ri)
        {
            int res = 0;
            int l = q[x].l, r = q[x].r, id = q[x].id;
            for (int i = l; i <= r; i++)
                add(w[i], res);
            ans[id] = res;
            for (int i = l; i <= r; i++)
                cnt[w[i]]--;
            x++;
        }
        int res = 0;
        int i = ri + 1, j = ri;
        while (x < y)
        {
            int l = q[x].l, r = q[x].r, id = q[x].id;
            while (j < r)
                add(w[++j], res);
            int bk = res;
            while (i > l)
                add(w[--i], res);
            ans[id] = res;
            while (i < ri + 1)
                cnt[w[i++]]--;
            res = bk;
            x++;
        }
        memset(cnt, 0, sizeof cnt);
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
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