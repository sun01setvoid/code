
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
void solve()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s = " ";
    s += s1;
    int l = 1, r = 0;
    vii a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            a[i] = i;
            if (l == r)
            {
                cout << "NO" << endl;
                return;
            }
            for (int j = l; j <= r; j++)
            {
                a[j] = j + 1;
                if (j == r)
                    a[j] = l;
            }
            l = i + 1, r = i;
        }
        else
            r++;
    }
    if (l <= r)
    {
        if (l == r)
        {
            cout << "NO" << endl;
            return;
        }
        for (int j = l; j <= r; j++)
        {
            a[j] = j + 1;
            if (j == r)
                a[j] = l;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
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