// https://acm.hdu.edu.cn/contest/problem?cid=1177&pid=1007
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, k;
string s;
void Raze()
{
    cin >> n >> k >> s;
    int cnt = 0;
    vii pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            cnt++;
    if (cnt < k)
    {
        cout << "-1" << endl;
        return;
    }
    vector<pii> tmp;
    int l = 0, r = 0, now = 1, res = INF;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            l = i, r = i;
            break;
        }
    }
    while (r < n)
    {
        if (now == k)
        {
            tmp.pb({l, r});
            l++;
            now--;
            if (l == n - 1)
                break;
            while (l < n)
            {
                if (s[l] == '1')
                    break;
                l++;
            }
        }
        while (r < n && now < k)
        {
            r++;
            if (s[r] == '1')
                now++;
        }
    }
    if (s[0] == '1')
        pre[0] = 1;
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + (s[i] == '1');
    for (int i = 0; i < tmp.size(); i++)
    {
        int l = tmp[i].fi, r = tmp[i].so;
        int ans = 0;
        ans += l / k;
        int now = l / k * k - 1;
        int mi;
        if (l - 1 < 0)
            mi = 0;
        else
            mi = pre[l - 1];
        ans++;
        int step = k - (pre[now + k] - mi);
        now += k;
        while (now < r)
        {
            now += step;
            step = k - (pre[now] - mi);
            ans++;
        }
        res = min(res, ans);
    }
    cout << res << endl;
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
