#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.14;
class Dot
{
    float x, y;

public:
    Dot(float x = 0, float y = 0) : x(x), y(y) // this指针不能写在这里,且这边不能用=，一定要用（）,这里是初始化的地方，所以知道x,y是什么
    {
        // this->x=x,this->y=y;这里要写this,不然不知道是哪一个
        cout << "Dot constructor called\n";
    }
    ~Dot()
    {
        cout << "Dot destructor called\n";
    }
};
int main()
{
    Dot *arry[4] = {new Dot(), NULL, new Dot()};
    return 0;
}