//和的第k小 2016-2017 National Taiwan University World Final Team Selection Contest
//G
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
// #define int long long
#define ull unsigned long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 3e6 + 5;
const int mod = 998244353;
const ld eps = 1e-8;
//-----------------------------------------------------//
void solve()
{
    int n, k;
    cin >> n >> k;
    vii a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({a[1], 1});
    int cnt = 0;
    while (pq.size() && cnt < k)
    {
        auto [dis, u] = pq.top();
        pq.pop();
        ++cnt;
        if (cnt == k)
        {
            cout << dis << endl;
            break;
        }
        if (u == n)
            continue;
        pq.push({dis - a[u] + a[u + 1], u + 1});
        pq.push({dis + a[u + 1], u + 1});
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}