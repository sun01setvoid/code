// lg P5410
// 类似与 manacher+kmp
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e7 + 10;
typedef long long ll;
int az[N], bz[N];
char a[N], b[N];
int n;
void exkmp(char *s, char *p, int *z, int *k) // 主原主原
{
    int n = strlen(s + 1);
    ll sum = 0;
    int l = 0, r = 0; // r表示为开区间好了,与manacher一样
    // 模式串自我匹配求z函数的话第一个位置不该做，这样的话就没用了，r一开始就到了最远端
    //如果使用模式串匹配别的串就没什么问题
    while (s[1 + z[1]] && s[1 + z[1]] == p[1 + z[1]])
        z[1]++;
    sum ^= (z[1] + 1);
    for (int i = 2; i <= n; i++)    //！！！！！！求z函数从二开始
    {
        if (i < r)
            z[i] = min(k[i - l + 1], r - i); // 对应的位置，且不超出边界 且i-l+1应该<i！！！！！！！
        while (s[i + z[i]] && p[1 + z[i]] && p[1 + z[i]] == s[i + z[i]])
            z[i]++; // 注意检验不要超出字符串
        if (i + z[i] > r)
        {
            r = i + z[i];
            l = i;
        }
        sum ^= 1LL * i * (z[i] + 1);
    }
    cout << sum << endl;
}
int main()
{
    scanf("%s %s", a + 1, b + 1);
    exkmp(b, b, bz, bz); // 内部+1
    exkmp(a, b, az, bz); // 内部+1
}