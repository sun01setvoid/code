#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
string s;
int tot;
void Raze()
{
    cin >> s;
    int n = s.size();
    debug(++tot);
    vector<char> b;
    b.pb('&');
    b.pb('#');
    for (int i = 0; i < n; i++)
    {
        b.pb(s[i]);
        b.pb('#');
    }
    b.pb('$');
    int sz = b.size();
    vii p(sz, 0);
    int c = 0, r = 0;
    for (int i = 3; i < sz - 3; i += 2)
    {
        if (i < r)
        {
            p[i] = min(r - i, p[2 * c - i]);
        }
        while (b[i + p[i] + 1] == b[i - p[i] - 1] ||
               b[i + p[i] + 1] == '2' ||
               b[i - p[i] - 1] == '2')
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }
    vector<pii> tmp;
    for (int i = 3; i < sz - 3; i += 2)
    {
        if (p[i] <= 1)
            continue;
        int st = (i - p[i] + 1) / 2;
        int en = (i + p[i] - 1) / 2;

        if (st >= 1 && en <= n && st <= en)
        {
            tmp.pb({en, st});
        }
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        cerr << "区间: [" << tmp[i].so << ", " << tmp[i].fi << "]" << endl;
    }
    vii dp(n + 1, 0);
    sort(tmp.begin(), tmp.end());
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        while (id < tmp.size() && tmp[id].fi <= i)
        {
            int l = tmp[id].so;
            int r = tmp[id].fi;
            if (l == 1)
            {
                dp[i] = max(dp[i], r - l + 1);
            }
            else
            {
                dp[i] = max(dp[i], dp[l - 1] + (r - l + 1));
            }
            id++;
        }
    }
    int ans = n - dp[n];
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}