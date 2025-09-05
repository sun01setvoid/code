#include <iostream>
using namespace std;
int inf=1e9+7;
long long fpow(int a,int k,int p){
    long long res=1;
    while (k){
        if (k&1)    res=res*a%p;
        k>>=1;
        a=(long long)a*a%p;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n,p,q;
        cin>>n>>p>>q;
        long long t=fpow(q,inf-2,inf);
        cout<<p*t%inf<<endl;
    }
}