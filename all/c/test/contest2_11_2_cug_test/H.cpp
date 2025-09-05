#include <iostream>
using namespace std;
long long fac(long long x){
    long long ans=1;
    for (long long i=x;x!=0;x--){
        ans=(ans*x)%(1000000007);
    }
    return ans;
}
int a[27];
int main(){
    int n;
    long long ans=1;
    cin>>n;
    string s;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        a[s.size()]++;
    }
    for (int i=1;i<=26;i++){
        ans=(ans*fac(a[i]))%(1000000007);
    }
    cout<<ans;
    getchar();
    getchar();
}