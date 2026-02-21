
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
int n, m;
vector<vii> adj(maxn);
int cnt[maxn];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= m; i++)
        cnt[i] = 0;
    unordered_map<int, int> mp;
    int val = n;
    for (int i = 1; i <= n; i++)
    {
        int li;
        cin >> li;
        for (int j = 1; j <= li; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
            cnt[x]++;
        }
    }
    for (int i = 1; i <= m; i++)
        if (cnt[i] == 1)
        {
            mp[i] = 1;
        }
        else if (cnt[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            if (mp.count(j))
            {
                val--;
                break;
            }
        }
    }
    if (val >= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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