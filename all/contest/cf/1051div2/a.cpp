
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
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int pos[maxn];
bool vis[maxn];
void solve()
{
    int n;
    cin >> n;
    vis[0] = 0, vis[n + 1] = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        pos[x] = i;
        vis[i] = 0;
    }
    vis[pos[n]] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        int p = pos[i];
        if (vis[p + 1] || vis[p - 1])
            vis[p] = 1;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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