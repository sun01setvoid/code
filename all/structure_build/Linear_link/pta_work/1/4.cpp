#include <iostream>
using namespace std;
struct node
{
    int x;
    node *ne;
};
void print(node *h)
{
    for (node *i = h->ne; i != nullptr; i = i->ne)
    {
        if (i == h->ne)
            cout << i->x;
        else
            cout << "->" << i->x;
    }
}
void Split(node *h1, node *h2)
{
    node *pre1 = h1, *pre2 = h2;
    for (node *i = h1->ne; i != nullptr; i = pre1->ne)
    {
        // i=pre1->ne可防止丢失删掉的偶数结点
        if (i->x % 2 == 0)
        {
            pre1->ne = i->ne; // list1(pre1不动,指向后一个结点)
            i->ne = nullptr;
            pre2->ne = i;
            pre2 = i; // list2
        }
        else
            pre1 = i;
    }
}
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
        cur = new node;
        cur->x = tmp;
        insert(h1, cur);
    }
    print(h1);
    cout << endl;
    Split(h1, h2);
    print(h1);
    cout << endl;
    print(h2);
    cout << endl;
    del(h1);
    del(h2);
}