#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
struct node
{
    int num;
    int cnt;
};
int fpow(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
void dfs(vector<node> &ans, vector<int> &cp, int pos, int mul)
{
    if (pos == ans.size())
    {
        cp.push_back(mul);
        return;
    }
    for (int i = 0; i <= ans[pos].cnt; i++)
    {
        dfs(ans, cp, pos + 1, mul * pow(ans[pos].num, i));
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, tmp;
        cin >> n;
        memset(a, 0, sizeof a);
        // 分解质因数，分别存储每个因数的个数
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            int x = tmp;
            vector<node> ans;
            vector<int> cp;
            for (int j = 2; j <= x / j; j++)
                if (x % j == 0)
                {
                    int s = 0;
                    while (x % j == 0)
                        x /= j, s++;
                    ans.push_back({j, s});
                }
            if (x > 1)
                ans.push_back({x, 1});
            dfs(ans, cp, 0, 1);
            for (int j = 0; j < cp.size(); j++)
            {
                res += a[tmp / cp[j] * (cp[j] - 1)];
            }
            ++a[tmp];
        }
        cout << res << "\n";
    }
}