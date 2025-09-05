// 查最前面的序列，分别存储，然后二分查找,比较好找吧，但是复杂度应该还是怎样？O(n)和O(tmp.size()logn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define inf 0x3f3f3f3f
int main()
{
    int t = 1;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        string s, tmp;
        vector<int> dp(n + 1, 0 );
        vector<int> num(n + 1, 0);
        vector<int> color(30, inf);
        vector<vector<int>> color_pos(30);
        cin >> s;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
                dp[i] = max(dp[i], color[j]);
            color[s[i] - 'a' + 1] = i;
        }
        for (int i = 0; i <= n - 1; i++)    color_pos[s[i] - 'a' + 1].push_back(i);
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] != inf) num[i] = num[dp[i]] + 1;
        }
        int q;
        cin >> q;
        while (q--)
        {
            cin >> tmp;
            int pos = 0;
            bool f = 1;
            for (auto it : tmp)
            {
                auto t = lower_bound(color_pos[it - 'a' + 1].begin(), color_pos[it - 'a' + 1].end(), pos);
                if (t == color_pos[it - 'a' + 1].end())
                {
                    f = 0;
                    break;
                }
                else
                    pos = *t + 1;
            }
            if (!f)
                cout << "0\n";
            else
            {
                cout << num[pos-1] + 1 << "\n";
            }
        }
    }
}