#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int main(){
    int t=1;
    cin>>t;
    cin.ignore();
    while (t--){
        string s;
        while (getline(cin,s)){
            istringstream iss(s);
            string word;
            while (iss >> word) {
                cout << word[0];
            }
            cout<<endl;  
        }
    }
}