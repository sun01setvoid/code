#include <iostream>
using namespace std;
int n,m;
char p[100010],s[1000010];
int ne[1000010];
void pre(){
    ne[1]=0;
    for (int i=1,j=0;i<n;i++){
        while (j && p[i+1]!=p[j+1]) j=ne[j];//隐形指针
        if (p[i+1]==p[j+1]) j++;
        ne[i+1]=j;//若以0为下标起始就是这里有问题，0代表1了(换元)，空用-1换更麻烦
    }
}
int main(){
    cin>>n>>p+1;
    cin>>m>>s+1;
    pre();
    for (int i=0,j=0;i<m;i++){
        while (j && s[i+1]!=p[j+1]) j=ne[j];//隐指针的位置
        if (s[i+1]==p[j+1]) j++;
        if (j==n)   cout<<i-n+2<<" ",j=ne[j];//隐指针的位置
    }
}