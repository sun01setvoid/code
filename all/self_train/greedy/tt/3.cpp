// P10478 生日礼物
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
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int vc[maxn], l[maxn], r[maxn], a[maxn], b[maxn], c[maxn];
bool vis[maxn];
void del(int x)
{
    vis[x] = 1;
    l[r[x]] = l[x], r[l[x]] = r[x];
}
void solve()
{
    int n, m, k = 0;
    cin >> n >> m;
    int st = 1, s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            s += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            st = i;
            break;
        }
    }
    int cnt = 1;
    for (int i = st; i <= n; i++)
    {
        if (a[i] >= 0 && vc[cnt] >= 0 || a[i] <= 0 && vc[cnt] <= 0)
            vc[cnt] += a[i];
        else
            vc[++cnt] += a[i];
    }
    n = cnt;
    for (int i = 1; i <= n; i++)
    {

        if (vc[i] > 0)
            k++;
    }
    if (k <= m)
        cout << s << endl;
    else
    {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int i = 1; i <= n; i++)
        {
            l[i] = i - 1, r[i] = i + 1;
            q.push({abs(vc[i]), i});
        }
        while (q.size() && k > m)
        {
            auto cur = q.top();
            q.pop();
            int val = cur.fi, x = cur.se;
            if (vis[x])
                continue;
            if (0 < l[x] && r[x] < n + 1 || vc[x] > 0)
            {
                // 合并之后中间正两边负，中间减掉，所以下次少减
                // 另一种也一样
                s -= abs(vc[x]);
                vc[x] += vc[l[x]] + vc[r[x]];
                del(l[x]);
                del(r[x]);
                q.push({abs(vc[x]), x});
                k--;
            }
        }
        cout << s << endl;
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