#include <iostream>
using namespace std;
template <class T>//typename,class都行
T myMax(T a,T b){
    return max(a,b);
}

int main(){

    //myMax(10,20);
    //myMax((int)10.0,20);
    myMax<int> (10.1,20);
    //模板也可重载

    //string a=myMax("aaaaa","ggg");//这是比较了初始地址，不对
    //cout<<a<<"\n";
    //a=myMax<string>("aaaaa","ggg")
    //cout<<a<<"\n";
    //因为一个是char [6],一个是char[4],类型无法判断，即使判断出来是指针（这里确实是这样），也是地址相比，所以要么重载，要么转化为string;

    
}