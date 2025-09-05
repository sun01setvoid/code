#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
long long pre[N];

long long getMinD()
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % 2 == 1)
            a[i] = -a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    long long mn = abs(pre[2 * n]);

    multiset<long long> ms;

    const long long INF = 1e18;
    auto f = [&](long long x)
    {
        long long res = INF;
        auto it = ms.lower_bound(x);
        if (it != ms.end())
        {
            res = min(res, (*it) - x);
        }
        if (it != ms.begin())
        {
            it--;
            res = min(res, x - (*it));
        }
        return res;
    };

    ms = multiset<long long>();
    for (int i = 2 * n; i >= 2; i -= 2)
    {
        ms.insert(2 * pre[i]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i]));
        // for(int j=i; j<=2*n; j+=2)
        // {
        //     mn = min(mn, abs( pre[2*n] + 2*pre[i] - 2*pre[j] ) );
        // }
    }

    ms = multiset<long long>();
    for (int i = 2 * n; i >= 2; i -= 2)
    {
        if (i + 1 <= 2 * n)
            ms.insert(2 * pre[i + 1]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i] - 2 * a[i]));
        // for(int j=i+1; j<=2*n; j+=2)
        // {
        // mn = min(mn, abs( pre[2*n] + 2*pre[i] - 2*a[i] - 2*pre[j] ) );
        // }
    }

    ms = multiset<long long>();
    for (int i = 2 * n - 1; i >= 1; i -= 2)
    {
        ms.insert(2 * pre[i]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i]));
        // for(int j=i; j<=2*n; j+=2)
        // {
        //     mn = min(mn, abs( pre[2*n] + 2*pre[i] - 2*pre[j] ) );
        // }
    }

    ms = multiset<long long>();
    for (int i = 2 * n - 1; i >= 1; i -= 2)
    {
        if (i + 1 <= 2 * n)
            ms.insert(2 * pre[i + 1]);
        mn = min(mn, f(pre[2 * n] + 2 * pre[i] - 2 * a[i]));
        // for(int j=i+1; j<=2*n; j+=2)
        // {
        //     mn = min(mn, abs( pre[2*n] + 2*pre[i] - 2*a[i] - 2*pre[j] ) );
        // }
    }

    for (int i = 1; i <= 2 * n; i++)
        if (i % 2 == 1)
            a[i] = -a[i];
    return mn;
}

void solve()
{
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i], sum += a[i];

    long long ans = (sum - getMinD()) / 2;

    for (int i = 1; i <= n; i++)
        swap(a[i], a[2 * n + 1 - i]);

    ans = max(ans, (sum - getMinD()) / 2);

    cout << ans << "\n";

    return;
}
/*

*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
/*
6
1
1
3
1 2 2
5
1 3 4 5 2
7
1 2 3 5 6 7 4
9
9 9 8 2 4 4 3 5 3
9
4 4 9 2 9 5 8 3 3
*/