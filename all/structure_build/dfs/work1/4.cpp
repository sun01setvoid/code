#include <iostream>
using namespace std;
void Hanoi(int n,char a,char b,char c){
    if (n==1)    {cout<<a<<"->"<<c<<endl;return;}
    Hanoi(n-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    Hanoi(n-1,b,a,c);
}
int main(){
    int n;
    cin>>n;
    Hanoi(n,'A','B','C');
}