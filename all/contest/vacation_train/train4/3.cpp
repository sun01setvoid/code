#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    getchar();
    while (n--){
        string p[110];
        getline(cin,s);
        stringstream str1(s);
        int l1=s.find(",");
        int l2=s.find(".");
        if   (l1-3<0)    {cout<<"Skipped"<<endl;continue;}
        string s1,s2;
        s1=s.substr(l1-3,3);
        s2=s.substr(l2-3,3);
        int i=0;
        string temp;
        if (s1=="ong" && s2=="ong"){
            while (str1>>temp){
                p[i++]=temp;
            }
            p[i-3]="qiao",p[i-2]="ben",p[i-1]="zhong.";
            cout<<p[0];
            for (int j=1;j<i;j++)    
                cout<<" "<<p[j];
            cout<<endl;
        }
        else    cout<<"Skipped"<<endl;
    }
}