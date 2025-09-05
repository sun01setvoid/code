#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int e[N];
struct node
{
    int a, b;
};
map<int, node> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t,n;
    cin >> t;
    int tmp;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> e[i];
            mp[e[i] + 1].a = mp[e[i] + 1].b = 0;
        }
        sort(e+1,e+n+1);
        for (int i = 1; i <= n; i++)
        {
            tmp = e[i];
            if (mp[tmp + 1].a == 0 && mp[tmp + 1].b == 0)
            {
                mp[tmp + 1].a++;
            }
            else if (mp[tmp + 1].a == 1 && mp[tmp + 1].b == 0)
            {
                mp[tmp + 1].b++;
                if (mp.count(tmp+2)) mp[tmp + 2].a = 2;
            }
            else if (mp[tmp + 1].a == 1 && mp[tmp + 1].b == 1)
            {
                mp[tmp + 1].a++;
            }
            else if (mp[tmp + 1].a == 2 && mp[tmp + 1].b == 1)
            {
                mp[tmp + 1].b++;
            }
            else if (mp[tmp + 1].a == 2 && mp[tmp + 1].b == 0)
            {
                mp[tmp + 1].b++;
                if (mp.count(tmp+2)) mp[tmp + 2].a = 2;
            }
        }
        bool f = 0;
        for (int i=1;i<=n;i++)
        {
            if (mp[e[i]+1].a == 2 && mp[e[i]+1].b == 2){
                f = 1;break;
            }
        }
        if (f)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}