#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    int t1,t2;
    string tmp,s;
    while (t--){
        t1=string::npos,t2=string::npos;
        cin>>n;
        cin>>tmp;
        s='0'+tmp;
        int cnt=0;
        for (int i=1;i<=n;i++){
            if (s[i]!=s[i-1]) cnt++;
        }
        cnt+=n;
        t1=s.find("01",0);
        if (t1!=string::npos) t2=s.find("01",t1+1);
        if (t1!=string::npos && t2!=string::npos){cout<<cnt-2<<"\n";continue;}
        else if (t1!=string::npos && s[n]=='0') {cout<<cnt-1<<"\n";continue;}
        t1=s.find("10",0);
        if (t1!=string::npos) t2=s.find("10",t1+1);
        if (t1!=string::npos && t2!=string::npos){cout<<cnt-2<<"\n";continue;}
        else if (t1!=string::npos && s[n]=='1') {cout<<cnt-1<<"\n";continue;}
        cout<<cnt<<"\n";
    }
}