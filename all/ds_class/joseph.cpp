#include <iostream>
using namespace std;
struct lNode
{
    int id;
    int val;
    lNode *ne;
};
int main()
{
    int n, m;
    cout << "请输入（人数）n" << endl;
    cin >> n;
    cout << "请输入（初始报数上限）m" << endl;
    cin >> m;
    lNode *head = nullptr, *cur, *pre;
    for (int i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "个人的密码" << endl;
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
    int idx = 0;
    while (p2->ne != p2)
    {
        cnt++;
        if (cnt == m)
        {
            ++idx;
            cout << "第" << idx << "个出列的人是" << p2->id << endl;
            m = p2->val;
            p1->ne = p2->ne;
            cnt = 0;
            delete p2;
            p2 = p1->ne;
        }
        else
        {
            p1 = p2;
            p2 = p1->ne;
        }
    }
    ++idx;
    cout << "第" << idx << "个出列的人是" << p2->id << endl;
    delete p2;
    return 0;
}