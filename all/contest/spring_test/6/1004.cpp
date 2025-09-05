#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long LL;
const LL INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        LL x;
        cin >> n >> x;
        vector<LL> a(n), absa(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        LL sum = 0;
        for (int i = 1; i < n; i++) absa[i] = absa[i - 1] + abs(a[i] - a[i - 1]), sum += abs(a[i] - a[i - 1]);
        if (sum <= x)
        {
            cout << 0 << '\n';
            continue;
        }
        LL num = sum - x;
        vector<int> lpos(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && a[st.top()] <= a[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                lpos[i] = st.top();
            }
            st.push(i);
        }
        vector<int> rpos(n, n);
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && a[st.top()] < a[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                rpos[i] = st.top();
            }
            st.push(i);
        }
        LL mi = INF;
        for (int i = 0; i < n; ++i)
        {
            int l = lpos[i] + 1;
            int r = rpos[i] - 1;
            if (l > r)
                continue;
            LL sum1 = absa[r] - absa[l];
            LL disl = 0;
            if (l > 0)
            {
                LL d1 = abs(a[l] - a[l - 1]);
                LL d2 = abs(a[i] - a[l - 1]);
                disl = d1 - d2;
            }
            LL disr = 0;
            if (r < n - 1)
            {
                LL d1 = abs(a[r + 1] - a[r]);
                LL d2 = abs(a[r + 1] - a[i]);
                disr = d1 - d2;
            }
            LL dis = sum1 + disl + disr;
            if (dis >= num)
            {
                if (r - l + 1 < mi)
                {
                    mi = r - l + 1;
                }
            }
        }
        if (mi != INF)
        {
            cout << mi << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}