#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    int n;
    cin >> n;
    LL f1 = 0, m1, a1;
    m1 = 1, a1 = 0;
    for (int i = 0; i < n; i++)
    {
        LL m2, a2;
        cin >> m2 >> a2;
        LL k1, k2;
        LL d = exgcd(m1, m2, k1, k2);
        if ((a2 - a1) % d)
        {
            f1 = -1;
            continue;
        }
        k1 *= (a2 - a1) / d; 
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);
        LL m = abs(m1 / d * m2);
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