#include <iostream>
using namespace std;
void Hanoi(int n,char x, char y,char z){    //x借助y到z
    if (n==1)   printf("%d号圆盘从%c到%c",n,x,z);
    Hanoi(n-1,x,z,y);
    printf("%d号圆盘从%c到%c",n,x,z);
    Hanoi(n-1,y,x,z);
}