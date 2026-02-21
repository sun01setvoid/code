
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
int a[maxn];
int k;
int gd[maxn];
int sg(int u)
{
    if (gd[u] != -1)
        return gd[u];
    set<int> s;
    for (int i = 1; i <= k; i++)
    {
        if (a[i] > u)
            break;
        int t = sg(u - a[i]);
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
    gd[0] = 0;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    sort(a + 1, a + k + 1);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int l;
        cin >> l;
        int ans = 0;
        for (int i = 1; i <= l; i++)
        {
            int x;
            cin >> x;
            if (gd[x]==-1) sg(x); 
            ans ^= gd[x];
        }
        if (ans)
            cout << "W";
        else
            cout << "L";
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