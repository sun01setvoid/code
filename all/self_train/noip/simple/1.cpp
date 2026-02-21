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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
//这种太难了，应该是不定数字，只考虑这样的定义，求得的方案数
// 假设我们用一个函数 C(x,y) 表示：
// 显然由指向终点的状态转移过来更方便
// x : 当前还未入栈的数字个数。
// y : 当前栈中的数字个数
// dp
//     for (int x = 0; x <= n; x++)
//     {
//         for (int y = 0; y <= n; y++)
//         {
//             if (!x)
//                 f[x][y] = 1;
//             else if (!y)
//                 f[x][y] = f[x - 1][y + 1];
//             else
//                 f[x][y] = f[x - 1][y + 1] + f[x][y - 1];
//         }
//     }
// cout<<f[n][0];

// catlan 阔号序列
// 不妨设最后一个出栈的是第k个数字
// c(n)=sum(k>=1 && k<=n |c(k-1)*c(n-k))
int c[40][40];
void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++)
        c[2 * i][i] = c[2 * (i - 1)][i - 1] * (4 * (i - 1) + 2) / i;
    cout << c[2 * n][n] / (n + 1) << endl;
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