#include <iostream>
using namespace std;

//类模板（模板，不具体，可以根据类型参数生成类）也可以定义静态成员和静态函数，
//由相同类型参数生成的模板类（由具体的类型参数）所共享

/*类模板与有元*/
//普通函数与普通类做类模板的有元，那么就是每个类模板的实例的友元
//普通类的友元模板，每个模板的实例都是他的友元
//多对多关系的类模板和友元模板，<T>对<X>每个对每个
//一对一关系的类模板和友元模板 <T>对 <T>

template <class T,int sz1> // 这里的typename可以用class替代
class Array
{
    T *elem;
    int sz;

public:
    Array(int s) : sz(s)
    {
        elem = new T[sz];
    }
    ~Array() { delete[] elem; }
    T &operator[](int i);
    bool operator+(int a);
};

//在类模板中还可以有非类型参数，template <class T,int MaxSz>
//重载（）运算符，可以是不确定目数的运算符，仿函数
//在本类作用域中，模板类可以省略为类模板名，作用域外则必须绑定模板参数
//界定符前一定要写类模板，后面可以省略写，写类模板名，比如Array

template <typename T,int sz1>
T &Array<T,sz1>::operator[](int i)
{
    if (i < 0 || i >= sz)
    {
        throw " Invalid Index";
    }
    return elem[i];
}

/*
bool Array::operator>(int a,int b){
    return a>b;
}
缺少Array后的参数列表不对，界定符前一定要写模板类，后面可以省略写，写类模板名，比如Array
*/


template class Array<int,10>;//模板类定义，只可一次，防止空间浪费
extern template class Array<int,10>;//找外部声明

template <typename T,int sz1>
bool Array<T,sz1>::operator+(int a)
{
    //Array b;
    return a;
} // 这样才行
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    Array<int,6> obj(n); //有时候要const类型，因为是数组长度
    int i;
    for (i = 0; i < n; i++)
        obj[i] = a[i];
    for (i = 0; i < n; i++)
        cout << obj[i] << " ";
    //cout<<obj[-1];
}