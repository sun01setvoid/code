#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
char p[N], str[N];
int n, ne[N], ans[N];
void init()
{
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && p[i + 1] != p[j + 1])
            j = ne[j];
        if (p[i + 1] == p[j + 1])
            j++;
        ne[i + 1] = j;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s", p + 1);
        scanf("%s", str + 1);
        int n = strlen(str + 1);
        init();
        int i, j;
        for (i = 0, j = 0; i < n; i++)
        {
            while (j && p[i + 1] != str[j + 1])
                j = ne[j];
            if (p[i + 1] == str[j + 1])
                j++;
        }
        bool f = 1;
        for (int s = 1, t = j + 1; s <= n - j; s++, t++)
        {
            if (p[s] != str[t])
            {
                f = 0;
                break;
            }
        }
        if (f)
            cout << n - j + 1 << endl;
        else
            cout << "fool" << endl;
    }
}