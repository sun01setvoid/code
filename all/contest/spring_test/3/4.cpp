//?????
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 3e5 + 10;
int a[N];
LL dp[N][2]; // 0偶,1奇,//最后一个位置不一定要合法，因为它在传递过程中会取到前一个位置，保证前面的状态合法
struct node
{
    LL v;
    int id;
} c[N];
LL p(LL x)
{
    return x * x;
}
bool cmp(node &a, node &b)
{
    return a.v < b.v;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    LL tmp;
    int n, m;
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> tmp, c[i] = {tmp, i};
        sort(c + 1, c + n + 1, cmp);
        for (int i = 1; i <= m; i++)
            cin >> tmp, a[tmp] = 1;
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i][1] = inf;
        dp[1][0] = 0;
        dp[2][1] = p(c[2].v - c[1].v);
        if (!a[c[1].id]) dp[2][0]=0;
        // 思考dp
        for (int i = 3; i <= n; i++)
        {
            dp[i][1] =dp[i - 1][0] + p(c[i].v - c[i - 1].v);
            if (a[c[i - 1].id])
            {
                dp[i][0] = dp[i - 1][1];
            }
            else
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(p(c[i].v - c[i - 2].v) + dp[i - 2][0], dp[i][1]);
            }
        }
        LL ans = dp[n][1];
        if (!a[c[n].id])
            ans = min(dp[n][0], ans);
        cout << ans << "\n";
    }
}