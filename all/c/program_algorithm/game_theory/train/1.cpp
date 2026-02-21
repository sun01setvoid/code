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
int mp[maxn][7];
int a[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int sg(int s, int len)
{
    // debug(s);
    // debug(len);
    if (len == 0)
        return 0;
    if (mp[s][len] != -1)
        return mp[s][len];
    int s2 = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s / a[i] % 10)
        {
            int ch = s / a[i] % 10;
            for (int j = 0; j < ch; j++)
            {
                s -= a[i];
                int t = sg(s, len);
                if (!t)
                {
                    s = s - s / a[i] % 10 * a[i] + ch * a[i];
                    return mp[s][len] = 1;
                }
            }
            s += ch * a[i];
        }
        else
        {
            int t = sg(s2, len - i - 1);
            if (!t)
                return mp[s][len] = 1;
        }
        s2 = s2 * 10 + s / a[i] % 10;
    }
    return mp[s][len] = 0;
}
void solve()
{
    string str;
    cin >> str;
    int len = str.size();
    int s = 0;
    for (int i = 0; i <= len - 1; i++)
    {
        s = s * 10 + (str[i] - '0');
    }
    int g = sg(s, len);
    if (g)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
signed main()
{
    memset(mp, -1, sizeof mp);
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}