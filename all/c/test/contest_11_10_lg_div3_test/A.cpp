#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    int ans=200;
    ans=min(ans,p);
    ans=min(ans,q);
    ans=min(ans,x-p);
    ans=min(ans,y-q);
    cout<<ans;
    system("pasue");
}