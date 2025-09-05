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
void print_new(node *h){
    for (node *i = h; i != nullptr; i = i->ne)
    {
        if (i == h)
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
node * reverse(node *h){    //也可以空出一个头指针，不断地把后面的节点插在head的后面
    node* pre=h,*cur=h->ne,*Next;//问题在于反向指针后,后一个位置无法到达
    if (cur==nullptr)    return nullptr;//空链表
    while (cur != nullptr){
        Next=cur->ne;
        cur->ne=pre;
        if (pre==h)    cur->ne=nullptr;
        if (Next==nullptr)    return cur; //记录新的头结点
        pre=cur;
        cur=Next;
    }
}
int main()
{
    int tmp;
    node *h1 = new node, *h2 = new node, *cur;
    h1->ne = nullptr; h2->ne = nullptr; // 空置头结点,防止更改头结点的特殊情况
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
    print(h1);cout << endl;
    print(h2);cout<<endl;
    node *h3,*h4;
    h3=reverse(h1);h4=reverse(h2);
    print_new(h3);cout<<endl;
    print_new(h4);cout<<endl;
    delete h1;delete h2;
    del(h3);del(h4);
}