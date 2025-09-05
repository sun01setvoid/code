#include <iostream>
using namespace std;
struct node
{
    int x;
    node *ne;
};
void print(node *h){
    for (node *i = h->ne; i != nullptr; i = i->ne)
    {
        if (i == h->ne)
            cout << i->x;
        else
            cout << "->" << i->x;
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
void merge(node * t1,node* t2){
    node*i;
    for(i=t2;i->ne!=nullptr;i=i->ne);//找负数最后一个
    i->ne=t1->ne;
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
    print(h1);cout << endl;//输出+
    print(h2);cout<<endl;//输出-
    merge(h1,h2);//合并
    print(h2);cout<<endl;//输出-+
    del(h2);delete h1;//删除一次就好，且不能落下h1
}