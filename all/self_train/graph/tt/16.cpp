// P1030 先序排列
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
string s1, s2;
void dfs(int l, int r, int ll, int rr)
{
    for (int i = l; i <= r; i++)
    {
        if (s1[i] == s2[rr])
        {
            cout << s1[i];
            if (l <= i - 1)
                dfs(l, i - 1, ll, ll + i - 1 - l);
            if (r >= i + 1)
                dfs(i + 1, r, ll + i - l, rr - 1);
        }
    }
}
void solve()
{
    cin >> s1 >> s2;
    dfs(0, s1.size() - 1,0,s1.size() - 1);
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