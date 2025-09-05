#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        string s;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cin >> s;

        vector<int> b, c;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
                b.push_back(a[i]);
            else
                c.push_back(a[i]);
        }

        sort(b.begin(), b.end(), greater<int>());
        sort(c.begin(), c.end(), greater<int>());

        int rounds = min((int)b.size(), (int)c.size() + 1);
        LL ans = 0;
        for (int i = 0; i < rounds; ++i)
        {
            if (i < b.size())
                ans += b[i];
            if (i < b.size())
                ans += c[i];
        }
        cout << ans << "\n";
    }
    return 0;
}