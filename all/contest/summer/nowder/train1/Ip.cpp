#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 42e1 + 5;
const int maxm = 1e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
vii st;
void Raze()
{
    int n; cin >> n; vii a(n + 1), pre(n + 1, 0), ans(n, -1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i];
    vector<vector<vector<pii>>>dp(n + 1, vector<vector<pii>>(n + 1));
    for (int i = 1; i <= n; i++)dp[i][i].pb({ 0,0 });
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1; vector<pii>tmp; tmp.reserve(r - l);
            for (int k = l; k < r; k++)
            {
                int s1 = pre[k] - pre[l - 1];
                int s2 = pre[r] - pre[k];
                int x = abs(s1 - s2), sum = 0;
                int t = lower_bound(st.begin(), st.end(), s1+s2) - st.begin();
                int cost = min(s1, s2) * t;
                if (dp[l][k].empty() || dp[k + 1][r].empty())continue;
                auto it1 = upper_bound(dp[l][k].begin(), dp[l][k].end(), make_pair(x, INF));
                if (it1 == dp[l][k].begin())continue; it1--;
                int cos1 = it1->so;
                auto it2 = upper_bound(dp[k + 1][r].begin(), dp[k + 1][r].end(), make_pair(x, INF));
                if (it2 == dp[k + 1][r].begin())continue; it2--;
                int cos2 = it2->so;
                int tot = cost + cos1 + cos2;
                tmp.pb({ x,tot });
            }
            if (tmp.size())
            {
                sort(tmp.begin(), tmp.end());
                int mi = tmp[0].so;
                for (int i = 1; i < tmp.size(); i++)
                {
                    if (tmp[i].so < mi)mi = tmp[i].so;
                    else tmp[i].so = mi;
                }
            }
            dp[l][r] = tmp;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int s1 = pre[i] - pre[0];
        int s2 = pre[n] - pre[i];
        int x = abs(s1 - s2);
        int tot = s1 + s2;
        int t = lower_bound(st.begin(), st.end(), s1 + s2) - st.begin();
        int cost = min(s1, s2) * t;
        auto it1 = upper_bound(dp[1][i].begin(), dp[1][i].end(), make_pair(x, INF));
        if (it1 == dp[1][i].begin())continue; it1--;
        int cos1 = it1->so;
        auto it2 = upper_bound(dp[i + 1][n].begin(), dp[i + 1][n].end(), make_pair(x, INF));
        if (it2 == dp[i + 1][n].begin())continue; it2--;
        int cos2 = it2->so;
        ans[i] = cost + cos1 + cos2;
    }
    for (int i = 1; i < n; i++)cout << ans[i] << " "; cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    for (int i = 0; i < 63; i++)st.pb(1ll << i);
    cin >> _;
    while (_--)Raze(); return 0;
}
