#include <iostream>
void uuu(int *p [2] ){
    printf("%d",&p[0][0]);
}
using namespace std;
int main(){
    int a[3][2],b[2][3];
    int (*p)[2]=a;
    p=a;
    int (*s)[3]=b;

}