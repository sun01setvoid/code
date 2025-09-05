#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        bool f=0;
        int sum=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='(') sum--;
            else sum++;
            if (i!=s.size()-1 && sum==0) {
                f=1;
                break;
            }
        }
        if (f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}