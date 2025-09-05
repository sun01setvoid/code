#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n;
vector<int> a(N, 0), p(N,0);
void dfs(vector<int> pos, vector<int> num, int layer)
{
    sort(num.begin(), num.end());
    if (pos.size() == 1)
    {
        p[pos[0]] = num[0];
        return;
    }
    vector<int> npos, nnum;
    if (layer % 2 == 1)
    {
        reverse(num.begin(), num.end());
    }
    for (auto i : pos)
    {
        if (a[i] > layer)
        {
            nnum.push_back(num.back());
            num.pop_back();
            npos.push_back(i);
        }
    }
    // 前后缀,以下一层的点为划分(一定有)，分前后缀
    int last ;
    reverse(num.begin(), num.end());
    for (auto i : pos)
    {
        last = i;
        if (a[i] > layer)
        {
            break;
        }
        p[i] = num.back();
        num.pop_back();
    }
    reverse(num.begin(), num.end());
    for (auto i : pos)
    {
        if (i < last)
            continue;
        if (a[i] > layer)
            continue;
        p[i] = num.back();
        num.pop_back();
    }
    dfs(npos, nnum, layer + 1);
}
int main()
{
    int t;
    cin >> t;
    int tmp;
    while (t--)
    {
        vector <int> A;
        cin >> n; 
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            if (tmp == -1)
                a[i] = 1e9;
            else
                a[i] = tmp;
            A.push_back(i);
        }
        dfs(A, A, 1);
        for (int i = 1; i <= n; i++)
            cout << p[i] << " \n"[i==n];//数组[1]
    }
}