#include <iostream>
using namespace std;
class B
{
public:
    B() { cout << ++b << endl; }
    ~B() { cout << --b << endl; }
    static int Getb() { return b; }

private:
    static int b;
};
int B::b = 10;
int main()
{
    B b1, b2, b3;
    cout << B::Getb() << endl;
    return 0;
}