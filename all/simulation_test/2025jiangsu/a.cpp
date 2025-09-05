#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
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
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
    repn(i, st, en) cerr << a[i] << ' '; \
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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vii cnt(1 << m, 0), w(1 << m, 0), pos(1 << m, -1), f(1 << m); // f是映射 i->f[i]
    vector<vii> idx(1 << m), presum(1 << m);                      // 与映射对应
    for (int i = 0; i < (1 << m); i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if ((i >> j) & 1)
                ++cnt[i], w[i] += m - j;
        }
        f[i] = i; // 初始映射
        if (a * (m - 2 * cnt[i]) > 0)
        { // 后缀
            if (a * n * (m - 2 * cnt[i]) + b * ((m + 1) * m / 2 - 2 * w[i]) <= 0)
                continue;
            if (a * 1 * (m - 2 * cnt[i]) + b * ((m + 1) * m / 2 - 2 * w[i]) > 0)
            {
                pos[i] = 1;
                continue;
            }
            int l = 1, r = n;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (a * mid * (m - 2 * cnt[i]) + b * ((m + 1) * m / 2 - 2 * w[i]) > 0)
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            pos[i] = l;
        }
        else
        { // 前缀
            if (a * 1 * (m - 2 * cnt[i]) + b * ((m + 1) * m / 2 - 2 * w[i]) <= 0)
                continue;
            if (a * n * (m - 2 * cnt[i]) + b * ((m + 1) * m / 2 - 2 * w[i]) > 0)
            {
                pos[i] = n;
                continue;
            }
            int l = 1, r = n;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (a * mid * (m - 2 * cnt[i]) + b * ((m + 1) * m / 2 - 2 * w[i]) > 0)
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            pos[i] = r;
        }
    }
    string s1;
    for (int i = 0; i < n; i++)
    {
        cin >> s1;
        int num = stoi(s1, nullptr, 2);
        idx[f[num]].pb(i + 1);
    }
    for (int i = 0; i < (1 << m); i++)
    {
        int sum = 0;
        for (int j = 0; j < idx[f[i]].size(); j++)
        {
            sum += idx[f[i]][j];
            presum[f[i]].pb(sum);
        }
    }
    int ans = LLONG_MIN;
    for (int i = 0; i < (1 << m); i++)
    {
        vii vis(1 << m, 0);
        for (int j = 0; j < (1 << m); j++)
        {
            if (!vis[j] && !vis[i ^ j])
                swap(f[j], f[i ^ j]), vis[j] = vis[i ^ j] = 1;
        }
        int sum = 0;
        for (int j = 0; j < (1 << m); j++)
        {
            if (!idx[f[j]].size())
                continue;
            if (pos[j] != -1)
            {
                if (a * (m - 2 * cnt[j]) > 0) // 后缀
                {
                    auto t = lb(idx[f[j]].begin(), idx[f[j]].end(), pos[j]);
                    int cur= t - idx[f[j]].begin();
                    sum += (cur - 1 >= 0) ? a * presum[f[j]][cur - 1] * cnt[j] + b * w[j] * cur : 0;
                    if (cur<=n-1)   sum += a * (presum[f[j]][presum[f[j]].size() - 1] - ((cur - 1 >= 0) ? presum[f[j]][cur - 1] : 0)) * (m - cnt[j]) + b * ((m + 1) * m / 2 - w[j]) * (presum[f[j]].size() - cur);
                }
                else
                { // 前缀
                    auto t = ub(idx[f[j]].begin(), idx[f[j]].end(), pos[j]);
                    int cur = t - idx[f[j]].begin();
                    --cur;
                    sum += (cur + 1 <= presum[f[j]].size() - 1) ? a * (presum[f[j]][presum[f[j]].size() - 1] - (cur>=0?presum[f[j]][cur]:0)) * cnt[j] + b * w[j] * (presum[f[j]].size() - cur - 1) : 0;
                    if (cur>=0) sum += a * presum[f[j]][cur] * (m - cnt[j]) + b * ((m + 1) * m / 2 - w[j]) * (cur + 1);
                }
            }
            else
            {
                sum += a * presum[f[j]][presum[f[j]].size() - 1] * cnt[j] + b * w[j] * presum[f[j]].size();
            }
            //debug(i);
            //debug(j);
            //debug(sum);
        }
        ans = max(ans, sum);
        for (int j = 0; j < (1 << m); j++)
            vis[j] = 0;
        for (int j = 0; j < (1 << m); j++)
        {
            if (!vis[j] && !vis[i ^ j])
                swap(f[j], f[i ^ j]), vis[j] = vis[i ^ j] = 1;
        }
    }
    cout << ans;
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