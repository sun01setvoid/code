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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a[maxn], p[maxn], cur[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) a[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        a[p[i]]++;
    }
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % i)
        {
            f = 0;
            break;
        }
    }
    if (!f)
    {
        cout << -1 << endl;
        return;
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[p[i]] % p[i] == 0)
            cur[p[i]] = cnt++, a[p[i]]--;
        else
            a[p[i]]--;
        cout << cur[p[i]] << " ";
    }
    cout << endl;
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