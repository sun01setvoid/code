#include <iostream>
#include <cstring>
using namespace std;
int a[110];
int stk[110];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        memset(a, 0, sizeof a);
        memset(stk, 0, sizeof stk);
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (!stk[a[i]])
                ans++, stk[a[i]] = 1;
        }
        cout << ans << "\n";
    }
}