#include <bits/stdc++.h>
using namespace std;
template <class T>
class new_list
{
    class node
    {
        T num;
        node *ne;

    public:
        node(T x = 0, node *tmp = nullptr) : num(x), ne(tmp) {}
        T &get() { return num; }
        node *&getne() { return ne; }
    };
    node *head;

public:
    new_list(node *p = nullptr) : head(p) {};
    node *insert(T x)
    {
        node *tmp = new node(x, head);
        head = tmp;
        return tmp;
    }
    node *del(T x)
    {
        node *pre = nullptr;
        for (node *cur = head; cur != nullptr;)
        {
            if (cur->get() == x)
            {
                if (cur == head)
                    head = cur->getne();
                else
                {
                    pre->getne() = cur->getne();
                }
                break;
            }
            pre = cur;
            cur = cur->getne();
        }
        return head;
    }
    node *gethead() { return head; }
    node *&sethead() { return head; }
    void display(){
        for (node* i = head; i != nullptr; i = i->getne())
            cout << i->get() << endl;
    }
    ~new_list()
    {
        node *pre = nullptr;
        for (node *cur = head; cur != nullptr;)
        {
            pre = cur, cur = cur->getne();
            delete pre;
        }
    }
};
int main()
{
}