#include <iostream>
using namespace std;
const int N = 60;
struct lNode
{
    int id;
    int val;
    lNode *ne;
};
int main()
{
    int n, m = 20;
    cin >> n;
    lNode *head = nullptr, *cur, *pre;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cur = new lNode;
        cur->id = i, cur->val = x, cur->ne = nullptr;
        if (head == nullptr)
            head = cur;
        else
            pre->ne = cur;
        pre = cur;
    }
    cur->ne = head;
    lNode *p1 = cur, *p2 = head;
    int cnt = 0;
    while (p2->ne != p2)
    {
        cnt++;
        if (cnt == m)
        {
            cout << p2->id << " ";
            p1->ne = p2->ne;
            cnt = 0;
            m = p2->val;
            p2 = p1->ne;
        }
        else
        {
            p1 = p2;
            p2 = p1->ne;
        }
    }
    cout << p2->id << " ";
}