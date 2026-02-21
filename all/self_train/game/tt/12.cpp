
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
int r, c;
vector<vii> mp(51, vii(51));
unordered_map<int, int> gd;
int sg()
{
    int res = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (mp[i][j] == 0)
                res += 1ll << ((i - 1) * c+ j);
    //用整数表示
    if (gd.count(res))
        return gd[res];
    unordered_map<int, int> s;
    for (int i = 1; i <= r - 1; i++)
    {
        for (int j = 1; j <= c - 1; j++)
        {
            if (mp[i][j] == 0 && mp[i][j + 1] == 0 && mp[i + 1][j] == 0 && mp[i + 1][j + 1] == 0)
            {
                mp[i][j] = mp[i][j + 1] = mp[i + 1][j + 1] = mp[i + 1][j] = 1;
                int t = sg();
                s[t] = 1;
                mp[i][j] = mp[i][j + 1] = mp[i + 1][j + 1] = mp[i + 1][j] = 0;
            }
        }
    }
    for (int i = 0;; i++)
    {
        if (!s.count(i))
        {
            gd[res] = i;
            break;
        }
    }
    return gd[res];
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> c;
        string s;
        for (int k = 1; k <= r; k++)
        {
            cin >> s;
            for (int j = 1; j <= c; j++)
                mp[k][j] = s[j - 1] - '0';
        }
        ans ^= sg();
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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