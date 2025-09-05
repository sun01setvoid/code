#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100000 + 10;
int a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ans = n;
        if (n == 1)
        {
            cout << ans << "\n";
            continue;
        }
        int m = 2 * n - 1;
        vector<int> d(m), p(m);
        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
            {
                d[i] = LLONG_MIN;
            }
            else
            {
                int k = (i - 1) / 2;
                d[i] = a[k + 2] - a[k + 1];
            }
        }
        int mid, r = 0;
        for (int i = 0; i < m; i++)
        {
            if (i < r)
            {
                p[i] = min(p[2 * mid - i], r - i);
            }
            else
            {
                p[i] = 0;
            }
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && d[i - p[i] - 1] == d[i + p[i] + 1])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                mid = i;
                r = i + p[i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            ans += (p[i] + 1) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
