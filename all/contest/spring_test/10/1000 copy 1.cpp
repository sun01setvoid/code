#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int m;
        cin>>m;
        int a,b;
        char ch;
        string s;
        while (m--){
            cin>>a>>ch>>b;
            cin>>s;
            if (s[0]=='+'){
                a=(a+stoi(s.substr(1,s.size()-1)))%24;
            }
            else{
                a=(((a-stoi(s.substr(1,s.size()-1)))%24)+24)%24;
            }
            printf("%02d:%02d\n",a,b);
        }
    }
}