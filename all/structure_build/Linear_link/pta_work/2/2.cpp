#include <iostream>
#include <iomanip>
using namespace std;
struct node
{
    int id;
    node *ne;
};
typedef pair<node *, node *> PII;
PII build(int m)
{
    node *h = nullptr, *pre, *cur, *t;
    for (int i = 1; i <= m; i++)
    {
        cur = new node;
        cur->id = i;
        cur->ne = nullptr;
        if (i == 1)
            h = cur;
        else
            pre->ne = cur;
        pre = cur;
    }
    t = cur;
    cur->ne = h; // 末尾
    return {h, t};
}
int main()
{
    int m, n;
    cin >> m;
    PII t1 = build(m);
    node *cur = t1.first, *pre = t1.second;
    node *h=cur;
    int cnt = 0;
    while (cin>>n){
        node *h2 = nullptr, *pre2, *cur2, *t2;
        while (cur->ne != cur)
        {
            cnt++;
            if (cnt == n)
            {
                cur2 = new node;
                cur2->id = cur->id;
                cur2->ne = nullptr;
                if (h2 == nullptr)    h2 = cur2;
                else    pre2->ne = cur2;
                pre2 = cur2;
                pre->ne = cur->ne, cnt = 0, cur = pre->ne;
            }
            else
            pre = cur, cur = pre->ne;
        }
        t2 = cur, t2->ne = h2,cur2->ne=t2;
        pre = t2, cur = h2;
    }
    h=cur;
    do{
        cout<<setw(4)<<cur->id;
        pre=cur;
        cur=cur->ne;
    }
    while (cur!=h);
}