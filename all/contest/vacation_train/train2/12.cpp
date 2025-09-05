#include <iostream>
#include <sstream>
using namespace std;
int main(){
    stringstream ss;
    int num;
    ss<<4<<5;
    ss>>num;
    cout<<ss.str()<<" "<<num<<endl;
}