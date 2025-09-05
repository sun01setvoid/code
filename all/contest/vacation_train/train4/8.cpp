#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;
int main(){
    int n;
    cin>>n;
    getchar();
    while (n--){
        string s1,s;
        string p="";
        string str[1010];
        int i=0;
        getline(cin,s1);
        cout<<s1<<endl;
        stringstream s2(s1);
        while (s2>>s){
            if (s=="I" || s=="me")    s="you";
            for (int j=0;j<s.size();j++){
                if (isalpha(s[j]) && s[j]!='I')    s[j]=tolower(s[j]);
                if (s[j]=='?')    s[j]='!';
            }
            int k=0,t,l=s.size();
            while (k<l && s.find("I",k)!=string::npos){
                t=s.find("I",k);
                if (t+1<l && !isalpha(s[t+1]) && s[t+1]!='\''){
                    s.erase(t,1);
                    s.insert(t,"you");
                    k=t+3;
                    l=l+2;
                }
                else k+=1;
            }
            str[i++]=s;
        }
        p+=str[0];
        for (int j=1;j<i;j++){
            if (str[j]=="!" || str[j]=="," || str[j]=="." || str[j][0]=='\''){
                p+=str[j];
            }
            else    p+=" ",p+=str[j];
        }
        int k=0,t,l=p.size();
        while (k<l && p.find("can you",k)!=string::npos){
            t=p.find("can you",k);
            p.erase(t,7);
            p.insert(t,"I can");
            k=t+5;
            l=l-2;
        }
        k=0;
        while (k<l && p.find("could you",k)!=string::npos){
            t=p.find("could you",k);
            p.erase(t,9);
            p.insert(t,"I could");
            k=t+7;
            l=l-2;
        }
        cout<<"AI: "<<p<<endl;
    }
}