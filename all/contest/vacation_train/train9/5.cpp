#include <iostream>
using namespace std;
string str[120];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    string s;
    cin>>m;
    int i=0;
    while (m--)    cin>>s,str[++i]=s;
    int st;
    cin>>st;
    cin.ignore();
    getline(cin,s);
    int cnt=0;
    for (int j=1;j<=i;j++){
        int t=s.find(str[j]);
        while(t!=string::npos){
            cnt++;
            s.replace(t,str[j].size(),"_");
            t=s.find(str[j],t+1);
        }
    }//防止违禁词子串被更新，所以改成"_",而且将字符串变长不利于遍历
    if (cnt>=st)   {cout<<cnt<<endl<<"He Xie Ni Quan Jia!";}
    else{
        int t=s.find("_");
        while(t!=string::npos){
            cnt++;
            s.replace(t,1,"<censored>");
            t=s.find("_",t+10);
        }
        cout<<s;
    }
}