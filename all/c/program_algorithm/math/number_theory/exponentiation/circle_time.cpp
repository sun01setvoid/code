//非矩阵快速幂找规律
#include <iostream>
#include <cstring>
using namespace std;
int f[60], h[60];
int main()
{
    int a, b, n;
    f[1] = 1, f[2] = 1;
    while (cin >> a >> b >> n, a || b || n)
    {
        memset(h, 0, sizeof h);
        h[8] = 1;
        int i, id;
        bool flag = 0;
        for (i = 3; i <= min(51, n); i++)
        {
            f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
            id = f[i - 1] * 7 + f[i]; // 进制
            if (h[id])
            {
                flag = 1;
                break;
            }
            else
                h[id] = i - 1;
        }
        if (flag)
        {
            int res = (n - h[id]) % (i - 1 - h[id]) + h[id];
            cout << f[res] << endl;
        }
        else
            cout << f[n] << endl;
    }
    return 0;
}