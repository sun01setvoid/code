#include <iostream>
using namespace std;
class node{
    int v;
    node *ne;
    public:
    node(int val=0){v=val;ne=NULL;}
    node*& getne(){return ne;}
    int getval(){return v;}
};
class Link{
    node *head;
    node *tail;
    public:
    Link(){head=NULL;tail=NULL;}
    node* gethead(){return head;}
    node * gettail(){return tail;}
    void insert(int val){
        node *cur=new node(val);
        if (head==NULL){
            head=cur;
        }
        else{
            tail->getne()=cur;
        }
        tail=cur;
    }
    Link operator+(Link&lk){
        Link lk1;
        for (node *i=this->gethead();i!=NULL;i=i->getne()){
            lk1.insert(i->getval());
        }
        for (node *i=lk.gethead();i!=NULL;i=i->getne()){
            lk1.insert(i->getval());
        }
        return lk1;
    }
    ~Link(){for (node* i=head;i!=NULL;i->getne()) delete i;}
};
ostream & operator<<(ostream& os,Link&lk){
    for (node *i=lk.gethead();i!=NULL;i=i->getne()){
        cout<<i->getval()<<endl;
    }
}