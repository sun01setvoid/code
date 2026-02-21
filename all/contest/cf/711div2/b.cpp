#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a[maxn];
void solve()
{
    int n, w;
    cin >> n >> w;
    multiset<int> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int nw = w;
        while (nw)
        {
            auto idx = s.upper_bound(nw);
            if (idx == s.begin())
                break;
            --idx;
            int val = *idx;
            nw -= val;
            s.erase(idx);
        }
        if (s.size() == 0)
        {
            cout << i << endl;
            return;
        }
    }
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