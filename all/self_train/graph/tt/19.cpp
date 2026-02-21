//遍历全部二叉树的复杂度是O(nlogn)
//方法二中序遍历manacher
//方法三求一遍左右根，和右左根，用dfs和随机哈希判断是否相同
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
int a[maxn];
int lv[maxn], rv[maxn];
bool dfs(int l, int r)
{
    if (l == -1 && r == -1)
        return 1;
    if (l == -1 && r != -1 || l != -1 && r == -1)
        return 0;
    if (a[l] != a[r])
        return 0;
    if (!dfs(lv[r], rv[l]))
        return 0;
    if (!dfs(lv[l], rv[r]))
        return 0;
    return 1;
}
int sum(int rt)
{
    if (rt == -1)
        return 0;
    int ans=1;
    return ans+sum(lv[rt]) + sum(rv[rt]);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> lv[i] >> rv[i];
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dfs(i, i))
        {
            ans = max(ans, sum(i));
        }
    }
    cout<<ans<<endl;
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