#include <iostream>
using namespace std;
int main(){
    string s;
    int t;
    cin>>t;
    int l;
    while (t--){
        cin>>l;
        cin>>s;
        int cnt=0,res=0;
        for (int i=0;i<l;i++){
            if (s[i]=='1') res++;
            else if (s[i]=='0' && res)   cnt+=2,res=0;
        }
        if (s[l-1]=='1')    cnt++;
        cout<<cnt<<endl;
    }
}