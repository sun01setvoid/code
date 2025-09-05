#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=0;
    for (int i=1;i<s.size();i++){
        int a=s[i-1]-'0',b=s[i]-'0';
        if (a>=b) ans+=a-b;
        else ans+=10+a-b;
    }
    ans+=s[s.size()-1]-'0'+s.size();
    cout<<ans;
}