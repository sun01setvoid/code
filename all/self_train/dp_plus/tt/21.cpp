// P2602  数字计数
#include <iostream>
using namespace std;
#define int long long
//-----------------------------------------------------//
int dp[20], ten[20], cnta[20], cntb[20], num[20]; // dp表示单个数，ten表示数量
void solve(int x, int *cnt)  //小心没有返回值gg
{
    ten[0] = 1;
    int len = 0;
    while (x)
    {
        len++;
        num[len] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= len; i++)
    {
        dp[i] = dp[i - 1] * 10 + ten[i - 1];
        ten[i] = ten[i - 1] * 10;
    }
    for (int i = len; i >= 1; i--)
    {
        for (int j = 0; j < num[i]; j++)
            cnt[j] += ten[i - 1];
        for (int j = 0; j <= 9; j++)
            cnt[j] += num[i] * dp[i - 1];
        int val = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            val = val * 10 + num[j];
        }
        cnt[num[i]] += val + 1;
        cnt[0] -= ten[i - 1]; // 第一次的要减
    }
}
signed main()
{
    int a, b;
    // cin >> _;
    cin >> a >> b;
    solve(a - 1, cnta);
    solve(b, cntb);
    cout<<cntb[0]-cnta[0];
    for (int i = 1; i <= 9; i++)
        cout << " " << cntb[i] - cnta[i];
    return 0;
}