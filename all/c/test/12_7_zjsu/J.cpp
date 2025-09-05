#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt=0;
    int len=s.size();
    int flag=0;
    for (int i=0;i<len;i++){
        if (s[i]=='?'){
            unordered_map <int,int> S;
            if (i>=1)   S[s[i-1]-'A']=1;
            if (s[i+1]!='?')  S[s[i+1]-'A']=1;
            for (int j=0;j<3;j++){
                if (!S.count(j)){
                    s[i]=j+'A';
                    break;
                }
            }
        }   
        else {
            if (i>=1 && s[i]==s[i-1]){
                flag=1;
                break;
            }
        }
    }
    if (flag)
        cout<<-1;
    else 
        cout<<s;
}