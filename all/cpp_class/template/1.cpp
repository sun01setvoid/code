#include <iostream>
using namespace std;
template <class T>

class Complex
{
    T x, y;

public:
    Complex(T i, T j) : x(i), y(j) {};

    Complex operator+(Complex &obj)
    {
        Complex obj1(x + obj.x, y + obj.y);
        return obj1;
    }

    Complex operator-(Complex &obj)
    {

        Complex obj1(x - obj.x, y - obj.y);

        return obj1;
    }

    void show()
    {

        cout << "(" << x << "," <<y<< ")" << "\n";
    }
};
int main(){
    Complex <int> obj(1,2),obj1(2,3);
    Complex <int> obj2=obj-obj1;
    obj2.show();
}