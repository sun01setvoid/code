#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
    repn(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n;
bool re(vii &a, int ma, int sum, vector<vector<ull>> &dp)
{
    if (a[0] > a[n - 2] && a[0] > a[n - 1])
        return true;
    bool f = true;
    ull type= 0x5555555555555555ULL;
    if (a[0]&1) type = 0xAAAAAAAAAAAAAAAAULL;
    for (int i = 1; i < n - 1 && f; i++)
    {
        int st = 2 * max(a[i], a[0]) - a[0];
        int en = min(sum - 2 * ma, 6 * ma - 1) - a[0];
        if (st > en)
            continue;
        int st_word = st / 64;
        int st_bit = st % 64;
        int en_word = en / 64;
        int en_bit = en % 64;
        for (int word = st_word + 1; word < en_word; word++)
        {
            if (word >= dp[i].size())
                break;
            ull masked = dp[i][word] & type;
            if (masked)
            {
                f = false;
                break;
            }
        }
        if (!f)
            break;
        if (st_word < dp[i].size())
        {
            ull mask = ~0ULL;
            if (st_word == en_word)
            {
                ull lower_mask = ~((1ULL << st_bit) - 1);
                ull upper_mask = (1ULL << (en_bit + 1)) - 1;
                mask = lower_mask & upper_mask;
            }
            else
            {
                mask = ~((1ULL << st_bit) - 1);
            }
            ull masked = dp[i][st_word] & type & mask;
            if (masked)
            {
                f = false;
                break;
            }
            if (st_word != en_word && en_word < dp[i].size())
            {
                mask = (1ULL << (en_bit + 1)) - 1;
                debug(dp[i][en_word]);
                debug(mask);
                masked = dp[i][en_word] & type & mask;
                debug(masked);
                if (masked)
                {
                    f = false;
                    break;
                }
            }
        }
    }
    return f;
}
void solve()
{
    cin >> n;
    vii a(n);
    int ma = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
        sum += a[i];
    }
    if (n < 4)
    {
        cout << "Yes\n";
        return;
    }
    int f1 = 0, f2 = 1;
    if (a[0] & 1)
        f1 = 1;
    for (int i = 1; i < n - 1; i++)
        if (a[i] & 1)
            f2 = 0;
    if (f1 && f2)
    {
        cout << "Yes\n";
        return;
    }
    if (sum >= 6 * ma)
    {
        cout << "No\n";
        return;
    }
    sort(a.begin() + 1, a.end() - 1);
    vector<vector<ull>> dp(n, vector<ull>((6 * ma + 63) / 64, 0));
    dp[1][0] = 1;
    int t = a[1] / 64, r = a[1] % 64;
    dp[1][t] |= (1ULL << r);
    if (t + 1 < dp[1].size())
        dp[1][t + 1] |= (1ULL >> (64 - r));
    for (int i = 2; i < n - 1; i++)
    {
        dp[i] = dp[i - 1];
        int t = a[i] / 64, r = a[i] % 64;
        for (int j = 0; j < dp[i].size(); j++)
        {
            if (j + t < dp[i].size())
            {
                dp[i][j + t] |= (dp[i - 1][j] << r);
                if (j + t + 1 < dp[i].size())
                {
                    dp[i][j + t + 1] |= (dp[i - 1][j] >> (64 - r));
                }
            }
        }
    }
    bool f = re(a, ma, sum,dp);
    if (!f)
    {
        cout << "No\n";
        return;
    }
    swap(a[0], a[n - 1]);
    f = re(a, ma, sum,dp);
    if (!f)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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