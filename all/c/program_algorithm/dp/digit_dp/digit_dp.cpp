// lg p2602 数位dp
// 注意前导0和最高位的限制
#include <iostream>
using namespace std;
typedef long long LL;
int num[20];
LL dp[20], ten[20], cnta[20], cntb[20];
// dp是无高位限制时每个数的数量
void solve(LL x, LL *cnt)
{
    int len = 0;
    while (x)
    {
        ++len;
        num[len] = x % 10;
        x /= 10;
    }
    ten[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        dp[i] = dp[i - 1] * 10 + ten[i - 1]; // 或者dp[i]=i*ten[i-1];
        ten[i] = 10 * ten[i - 1];
    }
    for (int i = len; i >= 1; i--) // 对在该位上的数字进行操作和统计<?x0000中有多少这个，?号是处理过的
    {
        for (int j = 0; j < num[i]; j++)
            cnt[j] += ten[i - 1]; // 外部的
        for (int j = 0; j <= 9; j++)
            cnt[j] += num[i] * dp[i - 1]; // 内部的,000~(num[i]-1)99
        LL num1 = 0;
        for (int j = i - 1; j >= 1; j--)
            num1 = num1 * 10 + num[j]; // 高位限制，即是统计xyzcd中yzcd个
        cnt[num[i]] += num1 + 1;       // 最后在+1
        cnt[0] -= ten[i - 1];          // 因为是从1开始，0不行
        // 因为查询必须从0开始，输入不会为0,所以不会有问题，所以一开始就有00000，0xxxx,00xxx,000xx,0000x
        // 这样的数需要删去，于是我们每个位置需要减去ten[i-1]
    }
}
int main()
{
    LL a, b;
    cin >> a >> b;
    solve(b, cntb);
    solve(a - 1, cnta);
    for (int i = 0; i <= 9; i++)
        cout << cntb[i] - cnta[i] << " ";
}
