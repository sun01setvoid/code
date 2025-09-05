//只有n+1和n*（n+1)?
#include <iostream>
#define inf 1000000000000000000
using namespace std;
int main(){
    int t;
    long long n,l,r,mid,ans;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        if (n<2 || n*(n+1)>inf)
            cout<<"-1 -1\n";
        else
            cout<<n+1<<" "<<n*(n+1)<<endl;;
        }
}