
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
const int maxn = 3e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
double getdis(pii &A, pii &B)
{
    return sqrt((double)(A.fi - B.fi) * (A.fi - B.fi) + (A.se - B.se) * (A.se - B.se));
}
pii pt[maxn];
int p[maxn];
struct edge
{
    double dis;
    int u, v;
    bool operator<(const edge &oth) const { return dis < oth.dis; }
} ed[maxn];
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
void solve()
{
    int s, n;
    cin >> s >> n;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        pt[i] = {x, y};
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ed[++cnt] = {getdis(pt[i], pt[j]), i, j};
        }
    }
    sort(ed + 1, ed + cnt + 1);
    int tot = 0;
    double ans = 0;
    vector<double> res(n + 1);
    for (int i = 1; i <= cnt; i++)
    {
        auto &[w, u, v] = ed[i];
        int fu = find(u), fv = find(v);
        if (fu != fv)
            p[fu] = fv, tot++, ans += w, res[tot] = w;
        if (tot == n - 1)
            break;
    }
    cout << fixed << setprecision(2) << res[n - 1 - (s - 1)] << endl;
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