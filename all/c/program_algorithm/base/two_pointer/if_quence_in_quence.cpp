//贪心，一定是前面先匹配的可能性更大
#include <iostream>
using namespace std;
int a[100010];
int b[100010];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)   cin>>a[i];
    for (int i=0;i<m;i++)   cin>>b[i];
    int i,j;
    for (i=0,j=0;i<n && j<m;j++){//快指针自己动，与慢指针比较；
        if (a[i]==b[j]) i++;
    }
    if (i==n)
        cout<<"Yes";
    else
        cout<<"No";
}