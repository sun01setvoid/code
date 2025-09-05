#include <iostream>
using namespace std;
class G{
    public:
    G() { std::cout << "G constructor called\n"; }
};
class A {
    public:
        A() { std::cout << "A constructor called\n"; }
};
    
class B : virtual public A {
    public:
        B() { std::cout << "B constructor called\n"; }
};
    
class C : virtual public A {
    public:
        C() { std::cout << "C constructor called\n"; }
};
    
class D : public C,public B {
    public:
        D() :B(),C(){ std::cout << "D constructor called\n"; }
};

int main(){
    
}
//

/*
A constructor called
B constructor called
A constructor called
C constructor called
D constructor called

A不是D的直接基类，所以不能在D种初始化，也不用，不可以用A中的元素
*/

/*
A constructor called
B constructor called
C constructor called
D constructor called
使B,C共用一个A，A是虚基类

A算是D的直接基类，需要在D中初始化,可以用A中的元素
*/

/*
A constructor called
C constructor called
B constructor called
D constructor called
构造
*/