#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int cnt[55][367], cnt0; // 60是闰年2.29
bool check(int x)
{
    if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
    {
        return true;
    }
    return false;
}
void compute()
{
    int r = 2; // 5,6是周六周日
    for (int i = 2025; i <= 2075; i++)
    {
        bool f = 0;
        f = check(i); // 闰年
        for (int j = 1; j <= 366; j++)
        {
            if (!f && j == 60)
                cnt[i - 2024][j]++;
            else if (r == 5 || r == 6)
            { // 不是闰年，选2月29
                cnt[i - 2024][j]++;
            }
            if (!f && j != 60 || f)
                r = (r + 1) % 7;
        }
    }
    for (int i = 1; i <= 51; i++)
        for (int j = 1; j <= 366; j++)
        {
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j];
        }
}
void solve()
{
    int k, l, r;
    cin >> k >> l >> r;
    int sum = (r - l + 1) * k;
    vii tmp(367);
    for (int j = 1; j <= 366; j++)
    {
        tmp[j] = cnt[r - 2024][j] - cnt[l - 2024 - 1][j];
    }
    sort(tmp.begin() + 1, tmp.begin() + 367);
    for (int i = 366; i >= 366 - k + 1; i--)
    {
        sum -= tmp[i];
    }
    cout << sum << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    compute();
    while (_--)
    {
        solve();
    }
    return 0;
}