#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define ls p << 1
#define rs p << 1 | 1
#define fi first
#define se second
#define pii pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
const int maxn = 3e5 + 10;
const int inf = 1e12;
const int mod = 998244353;
stack<pii> stk;
pii p1[maxn];
pii p2[maxn];
void parse(string &s, pii *p)
{
    int n = s.size();
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            stk.push({cnt, cnt}), ++cnt;
        else if (s[i] == ')')
        {
            auto [l2, r2] = stk.top();
            stk.pop();
            auto [l1, r1] = stk.top();
            stk.pop();
            p[r1].fi = l1, p[r1].se = r2;
            stk.push({l1, r2});
        }
    }
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.size();
    int num = (len + 2) / 3;
    parse(s1, p1);
    parse(s2, p2);
    int ans = 1;
    for (int i = 1; i <= num - 1; i++)
    {
        // cout << p1[i].fi << " " << p1[i].se << " " << p2[i].fi << " " << p2[i].se << endl;
        int l = max(p1[i].fi, p2[i].fi), r = min(p1[i].se, p2[i].se);
        // cout << l << " " << r << endl;
        if (i < l || i > r)
            ans = 0;
        ans = ans * (i - l + 1) % mod * (r - i) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}