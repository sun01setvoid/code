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
int pop(int x)
{
    return __builtin_popcountll(x);
}
//-----------------------------------------------------//
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> ans;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += pop(a[i]);
        int x = a[i];
        set<int> seen_positions;
        int max_try = 0;
        while (true)
        {
            int pos = __builtin_ctzll(~x);
            if (seen_positions.count(pos))
                break;
            seen_positions.insert(pos);
            long long cost = 1LL << pos;
            if (cost > k)
                break;
            int new_beauty = pop(x + cost);
            int gain = new_beauty - pop(x);
            if (gain > 0)
            {
                ans.emplace_back(gain, cost);
            }

            x += cost;
            if (++max_try > 60)
                break;
        }
    }
    sort(ans.begin(), ans.end(), [](auto &a, auto &b)
         {
            double eff1 = (double)a.first / a.second;
            double eff2 = (double)b.first / b.second;
            return eff1 > eff2; });

    for (auto [gain, cost] : ans)
    {
        if (k >= cost)
        {
            k -= cost;
            sum += gain;
        }
        else
        {
            continue;
        }
    }

    cout << sum << '\n';
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