#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
// #define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 2e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, k, a[maxn], b[maxn], tr[maxn];
inline int lowbit(int x) { return x & -x; }
inline void add(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += val;
}
inline int q(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += tr[i];
    return sum;
}
void Raze()
{
    cin >> n >> k;
    map<int, int> mp1, mp2;
    int tot1 = 0, tot2 = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp1[a[i]]++;
    for (int i = 1; i <= n; i++)
        cin >> b[i], mp2[b[i]]++;
    for (auto it : mp1)
    {
        if (mp2[it.fi] != it.so)
        {
            NO;
            return;
        }
    }
    if (k % 2 == 0)
    {
        YES;
        return;
    }
    for (auto it : mp1)
    {
        if (it.so > 1)
        {
            YES;
            return;
        }
    }
    for (auto &it : mp1)
        it.so = ++tot1;
    int val1 = 0, val2 = 0;
    for (int i = 1; i <= n; i++)
        tr[i] = 0;
    for (int i = n; i >= 1; i--)
    {
        val1 = (val1 + q(mp1[a[i]])) & 1;
        add(mp1[a[i]], 1);
    }
    for (int i = 1; i <= n; i++)
        tr[i] = 0;
    for (int i = n; i >= 1; i--)
    {
        val2 = (val2 + q(mp1[b[i]])) & 1;
        add(mp1[b[i]], 1);
    }
    if ((val1 & 1) == (val2 & 1))
    {
        YES;
    }
    else
    {
        NO;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}