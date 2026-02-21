// poj1679
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<array<int, 3>> ed(maxn);
int p[maxn];
int find(int u)
{
    if (p[u] != u)
        return p[u] = find(p[u]);
    return p[u];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int w, u, v;
        cin >> u >> v >> w;
        ed[i] = {w, u, v};
    }
    sort(ed.begin() + 1, ed.begin() + m + 1);
    int num = 0, sm = 0, sm1 = 0, sm2 = 0, ans = 0, tt = 0;
    bool f = 1;
    for (int i = 1; i <= m + 1; i++)
    {
        if (i > tt)
        {
            if (sm1 != sm2)
            {
                f = 0;
                break;
            }
            sm1 = 0;
            for (int j = i; j <= m + 1; j++)
            {
                if (j > m || ed[i][0] != ed[j][0])
                {
                    tt = j - 1;
                    break;
                }
                if (find(ed[j][1]) != find(ed[j][2]))
                    ++sm1;
            }
            sm2 = 0;
        }
        if (i > m)
            break;
        int fu = find(ed[i][1]), fv = find(ed[i][2]);
        if (fu != fv)
        {
            sm2++;
            p[fu] = fv;
            ans += ed[i][0];
        }
    }
    if (f)
        cout << ans << endl;
    else
        cout << "Not Unique!" << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}