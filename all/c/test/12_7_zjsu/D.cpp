#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,idx;
    string s;
    cin>>n;
    getchar();
    for (int i=0;i<n;i++){
        getline(cin,s);
        for (int j=0;j<=n/3;j++){
            idx=s.find("ljl");
            if (idx==string::npos)
                break;
            else{
                s.erase(idx,3);
                s.insert(idx,"ncljr");
            }
        }
        cout<<s<<endl;
    }
}