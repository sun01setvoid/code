#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int a[maxn], b[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int ans = 0;
    for (int i = n, j = m; i >= 1; i--)
    {
        while (j >= 1 && b[j] >= a[i])
            pq.push(b[j]), j--;
        if (pq.size())
            ans += pq.top(), pq.pop();
        else
        {
            cout << "you died!" << endl;
            return;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}