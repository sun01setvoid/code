#include <iostream>
#include <cstring>
using namespace std;
class Str{
    char *ptr;
    public:
        Str(char *s=""){
            ptr=new char[strlen(s)+1];
            memcpy(ptr,s,strlen(s)+1);    
        }
        char* getptr(){return ptr;}
        Str operator+(Str& obj){
            char* tmp=new char [strlen(ptr)+strlen(obj.getptr())+1];
            strcpy(tmp,ptr);
            strcat(tmp,obj.getptr());
            return Str(tmp);
        }
};
ostream & operator<< (ostream &os,Str&a){
    char *p=a.getptr();
    while (*p){
        cout<<*p;
        p++;
    }
}
int main(){
    Str s1("hello"),s2("hhhhj"),s3;
    s3=s1+s2;
    cout<<s3;
}