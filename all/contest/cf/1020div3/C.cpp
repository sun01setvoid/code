#include <iostream>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
LL a[N], b[N];
int main()
{
    int t;
    int n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        LL mi = a[1], ma = a[1];
        LL x = -1;
        LL cnt = 0;
        bool f = 1;
        for (int i = 1; i <= n; i++)
        {
            if (mi > a[i])
                mi = a[i];
            if (ma < a[i])
                ma = a[i];
            if (b[i] != -1)
            {
                if (x == -1)
                    x = a[i] + b[i], cnt++;
                else
                {
                    if (x == a[i] + b[i])
                        f = 1, cnt++;
                    else
                        {f = 0;break;}
                }
            }
        }

        if (!f)
            cout << 0 << "\n";
        else
        {
            if (x != -1)
            {
                if (n - cnt == 0)
                    cout << 1 << "\n";
                else
                {
                    bool f = 1;
                    for (int i = 1; i <= n; i++)
                    {
                        if (b[i] == -1)
                        {
                            if (!(x - a[i] >= 0 && x - a[i] <= k))
                                f = 0;
                        }
                    }
                    if (f)
                        cout << 1 << "\n";
                    else
                        cout << 0 << "\n";
                }
            }
            else
            {
                LL l = ma, r = mi + k;
                if (l <= r)
                    cout << r - l + 1 << "\n";
                else
                    cout << 0 << "\n";
            }
        }
    }
}