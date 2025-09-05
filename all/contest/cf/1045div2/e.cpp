#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
signed main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        int n, val;
        cin >> n;
        vii a(n + 1), dp(n + 3);
        dp[n + 1] = dp[n + 2] = 0;
        for (int i = n; i >= 1; i--)
        {
            if (dp[i + 1] == dp[i + 2])
                dp[i] = dp[i + 1] + 1;
            else
            {
                cout << "throw " << i << endl;
                cout.flush();
                cin >> dp[i];
                if (dp[i] == dp[i + 1] + 1)
                    a[i] = 1;
                else
                    a[i] = 2;
            }
        }
        for (int i = 1; i <= n - 2; i++)
        {
            if (a[i] == 0)
            {
                cout << "swap " << i << endl;
                cout.flush();
                cout << "throw " << i + 1 << endl;
                cout.flush();
                cin >> val;
                if (val == dp[i + 2] + 1)
                    a[i] = 1;
                else
                    a[i] = 2;
            }
        }
        cout << "swap " << n - 1 << endl;
        cout.flush();
        cout << "throw " << n - 1 << endl;
        cout.flush();
        cin >> val;
        if (val == 2)
            a[n] = 1;
        else
            a[n] = 2;
        cout << "!";
        for (int i = 1; i <= n; i++)
            cout << " " << a[i];
        cout << endl;
        cout.flush();
    }
    return 0;
}