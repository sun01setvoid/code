#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int vis[N],j;
vector<int> G[N];
bool dfs(int u){    
    vis[u]=1;      
    for (int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==1) return false; 
        if(!vis[v]&&!dfs(v)) return false; 
    }
    vis[u]=2;
    j++;
    return true;
}//dfs版
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n, m, x, y, col;
    string tmp;
    cin >> t;
    while (t--)
    {
        j=0;
        cin >> n >> m;
        for (int i = 1; i <= 3 * n; i++)
            vis[i] = false, G[i].clear();
        vector<int> din(3 * n + 1, 0);
        int f1 = 1, f2 = 1;
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y >> col;
            int a = 2 * n - x + 1, b = (y + 1) / 2, c = 2*n + (2*x-y+1) / 2;//  x-y/2  因为负号的话会+1
            if (col == a)
                ;
            else if (col == b)
                swap(a, b);
            else if (col == c)
                swap(a, c);
            else
                f1 = 0;
            if (f1)
                G[b].push_back(a), G[c].push_back(a), din[a] += 2;
        }
        if (!f1)
            cout << "No" << endl;
        else
        {
            for (int i=1;i<=3*n;i++)    if (!vis[i])    dfs(i);
            if (j==3*n)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}