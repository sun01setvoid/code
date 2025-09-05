#include <iostream>
using namespace std;
class Array {
    int *data;
    int len;
    public:
        Array(int l=0):len(l){data=new int [len];}
        int& operator[](int idx){
            if (idx>=len)   {
                int *tmp=new int[len+1];
                for (int i=0;i<len;i++) tmp[i]=data[i];
                delete []data;
                len=len+1;
                data=tmp;
            } 
            return data[idx];
        }
        ~Array(){delete[]data;}
        void show(){
            for (int i=0;i<len;i++) cout<<data[i]<<endl;
        }
};
ostream& operator<<(ostream& os,Array & a){
    a.show();
    return cout;
}
