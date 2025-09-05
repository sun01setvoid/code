#include <iostream>
using namespace std;
struct node
{
    int x;
    node *ne;
};
void insert(node *h, node *now)
{
    node *pre = h, *i;
    for (i = h->ne; i != nullptr; i = i->ne)
    { // 因为头结点空置
        if (i->x > now->x)
        {
            now->ne = pre->ne;
            pre->ne = now;
            break;
        }
        pre = i;
    }
    if (i == nullptr)
    { // 结点>=所有数,放在末尾时特殊处理
        now->ne = nullptr;
        pre->ne = now;
    }
}
void del(node *p)
{
    node *pre, *cur = p;
    while (cur != nullptr)
    {
        pre = cur;
        cur = cur->ne;
        free(pre);
    }
}
int main()
{
    int tmp;
    node *h1 = new node, *h2 = new node, *cur;
    h1->ne = nullptr;
    h2->ne = nullptr; // 空置头结点,防止更改头结点的特殊情况
    while (cin >> tmp)
    {
        if (tmp > 0)
        {
            cur = new node;
            cur->x = tmp;
            insert(h1, cur);
        }
        else if (tmp < 0)
        {
            cur = new node;
            cur->x = tmp;
            insert(h2, cur);
        }
    }
    for (node *i = h1->ne; i != nullptr; i = i->ne)
    {
        if (i == h1->ne)
            cout << i->x;
        else
            cout << "->" << i->x;
    }
    cout << endl;
    for (node *i = h2->ne; i != nullptr; i = i->ne)
    {
        if (i == h2->ne)
            cout << i->x;
        else
            cout << "->" << i->x;
    }
    del(h1);
    del(h2);
}