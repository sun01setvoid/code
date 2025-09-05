#include <iostream>
using namespace std;
const int N=1e6+10;
char p[N];
int n,ne[N];
void init(){
    for (int i=1,j=0;i<n;i++){
        while (j && p[i+1]!=p[j+1])  j=ne[j];
        if (p[i+1]==p[j+1]) j++;
        ne[i+1]=j;
    }
}
int main(){
    cin>>n;
    scanf("%s",p+1);
    init();
    int i,j;
    for (i=1,j=0;i<n;i++){
        while (j && p[i+1]!=p[j+1]) j=ne[j];
        if (p[i+1]==p[j+1]) j++;
    }//一定从过了一个最小循环节的位置率先全部匹配
    cout<<n-j;    
}