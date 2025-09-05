#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0, st = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            st++;
        }
        else
            st = 0;
        ans = max(ans, st);
    }
    if (ans >= k)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        vii a(s.size() + 1);
        int p = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                a[i + 1] = p++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                a[i + 1] = p++;
            }
        }
        for (int i = 1; i <= s.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
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