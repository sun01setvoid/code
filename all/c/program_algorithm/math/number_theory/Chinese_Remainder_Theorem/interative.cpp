#include <bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    int n;
    cin >> n;
    int f1 = 0, m1, a1;
    m1 = 1, a1 = 0;
    for (int i = 0; i < n; i++)
    {
        int m2, a2;//前面是模数，后面是值
        cin >> m2 >> a2;
        int k1, k2;
        int d = exgcd(m1, m2, k1, k2);
        if ((a2 - a1) % d)
        {
            f1 = -1;
            continue;
        }
        k1 *= (a2 - a1) / d; 
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);
        int m = abs(m1 / d * m2);
        a1 = (k1 * m1 + a1) % m;
        m1 = m;
    }
    if (f1 == -1)
        cout << -1;
    else
    {
        cout << a1;//最小特解，m1是lcm
    }
    return 0;
}