//positive number
//高斯消元（普通消元一个一个看位数）
//lg3812 最大异或和
//把很多数的异或转换为较少的线性基的异或
#include <iostream>
using namespace std;
typedef long long LL;
const int N=100010;
LL a[N];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%lld",&a[i]);
    int k=0;
    for (int i=62;i>=0;i--){
        for (int j=k;j<n;j++){
            if (a[j]>>i&1){
                swap(a[j],a[k]);
                break;
            }
        }
        if (!(a[k]>>i&1))  continue;
        for (int j=0;j<n;j++){  //这是整条一起做
            if(j!=k && (a[j]>>i&1)){
                a[j]^=a[k];
            }
        }
        k++;
        if (k==n)   break;
    }
    LL res=0;
    for (int i=0;i<k;i++) res^=a[i];
    printf("%lld\n",res);
    return 0;
}