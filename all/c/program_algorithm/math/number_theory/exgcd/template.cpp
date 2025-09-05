//lgP4549
#include <iostream>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int n,mi=-1,tmp;
    cin>>n;
    while (n--){
        cin>>tmp;
        if (tmp==0) continue;
        if (mi==-1) mi=abs(tmp);
        else {
            mi=gcd(mi,abs(tmp));
        }
    }
    cout<<mi;
}