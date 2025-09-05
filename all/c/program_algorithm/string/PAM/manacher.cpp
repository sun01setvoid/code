//manacher
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2.2e7 + 10;
int n;
char a[N],b[N];
int p[N];
void init()
{
    n=strlen(a);   //n 个 -> 2*n+3个
    int k = 0;
    b[k++] = '^', b[k++] = '#';
    for (int i = 0; i < n; i++)
        b[k++] = a[i], b[k++] = '#';
    b[k++] = '$';//防溢出
    n=k;
}
void manacher()
{
    int r = 0, mid; // 开区间
    for (int i = 1; i < n-1; i++)
    {
        if (i < r)
            p[i] = min(p[2 * mid - i], r - i); // 无法延伸出去，可以反证
        else p[i]=1;  //p[i]=0
        while (b[i-p[i]] == b[i+p[i]])//防越界两边不同     // i-p[i]-1    i+p[i]+1
            p[i]++;
        if (i + p[i] > r)
        {
            r = p[i] + i, mid = i;
        }
    }
}
//以'#'号结尾
//奇数串以字母为中心，偶数串以'#'号为中心
//偶数索引是原字母
//p[i]=1     p[i]-1是回文串长度
//p[i]=0     p[i]是回文串长度
int main()
{
    cin >> a;
    init();
    manacher();
    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, p[i]);
    cout << res - 1;
}