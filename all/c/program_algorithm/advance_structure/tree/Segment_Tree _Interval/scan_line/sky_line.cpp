// lg p1904
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
struct node
{
    int l, h, r;
};
bool cmp(node &a, node &b)
{
    return a.l < b.l;
}
priority_queue<PII, vector<PII>, less<PII>> heap;
vector<int> alls;
vector<node> query;
vector<int> ans;
int find(int x)
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}
int main()
{
    int l, h, r, cnt = 0;
    while (cin >> l >> h >> r)
    {
        alls.push_back(l);
        alls.push_back(r - 1);
        alls.push_back(r);//防止（r,0)成为边界时没有被计算
        query.push_back({l,h,r});
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    sort(query.begin(), query.end(), cmp);
    for (int i = 0, j = 0; i < alls.size(); i++)
    {
        while (j < query.size() && i >= find(query[j].l))
        {
            heap.push({query[j].h, find(query[j].r - 1)});
            j++;
        }
        while (heap.size() && i > heap.top().second)
        {
            heap.pop();
        }
        if (heap.size())
            ans.push_back(heap.top().first);
        else
            ans.push_back(0);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
            cout << alls[i] << " " << ans[i];
        else if (ans[i] != ans[i - 1])
            cout << " " << alls[i] << " " << ans[i];
    }
}