#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int cnt=0;
    getchar();
    while (getline(cin,s)){
        if (s.find("easy")!= string::npos || s.find("qiandao")!=string::npos ){
            cnt++;
            if (cnt==n)    cout<<"Wo AK le";
            continue;
        }
        if (m)    cnt++;
        if (cnt==n)    cout<<"Wo AK le";
        if (m==0 && cnt<n)    cout<<s;
        m--;
    }
}