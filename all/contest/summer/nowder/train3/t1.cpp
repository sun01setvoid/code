#include <bits/stdc++.h>
using namespace std;
const int N = 5e6;
bool vis[N];
vector<unordered_map<int,int>> pri;
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (vis[i])
            continue;
        pri[i][i] = 1;
        for (int j = i * 2; j < N; j += i)
        {
            vis[j] = 1;
            int t = j;
            while (t % i)
            {
                t /= i;
                pri[j][i]++;
            }
        }
    }
}