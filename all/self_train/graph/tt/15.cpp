
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
string s;
char dfs(int l, int r)
{
    if (l == r)
    {
        if (s[l] == '0')
        {
            cout << 'B';
            return 'B';
        }
        else
        {
            cout << 'I';
            return 'I';
        }
    }
    int mid = (l + r) / 2;
    char a = dfs(l, mid), b = dfs(mid + 1, r);
    if (a == 'B' && b == 'B')
    {
        cout << 'B';
        return 'B';
    }
    else if (a == 'I' && b == 'I')
    {
        cout << 'I';
        return 'I';
    }
    else
    {
        cout << 'F';
        return 'F';
    }
}
void solve()
{
    int n;
    cin >> n;
    cin >> s;
    dfs(0,s.size()-1);
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