#include <iostream>
using namespace std;
class Demo
{ 
    public:
        Demo(){data=1;}
        Demo(int d):data(d){ }
        void setData(int d){data=d;}
        int getData(){return data;}
        
     private:
        int data;
};
int main()
{
    Demo array[6]={10,20,30},*pa=array+5;
    pa->setData(pa->getData()+15);
    while(pa>array)
    {  
       int d=(pa--)->getData();
       pa->setData(d+pa->getData());
       cout<<pa->getData()<<'.';
    }
    return 0;
}
