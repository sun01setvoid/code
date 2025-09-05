#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    string s;
    while (t--){
        cin>>n;
        cin>>s;
        int cnt=0,a=0,b=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='0')  a++;
            else b++;
        }
        cnt=a*(b+1)+b*(b-1);
        cout<<cnt<<"\n";
    }
}