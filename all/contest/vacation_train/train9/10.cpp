#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
const int N=1e5+10;
map <string,vector <string> > mp;
string G[N];
int n,q;
int main(){
    cin>>n;
    int cnt=0;
    getchar();
    string s,tmp;
    while (n--){
        getline(cin,s);
        stringstream s1(s);
        string p;
        while (s1>>tmp){
            p+=tmp[0];
        }
        if (!mp.count(p))   G[++cnt]=p;
        mp[p].push_back(s);
    }
    //对map迭代器遍历用!mp.end(),没有小于号的重载;
    //mp是pair类型，用迭代器遍历时要用first和end取得元素
    for (int i=1;i<=cnt;i++){
        sort(mp[G[i]].begin(),mp[G[i]].end());
    }
    cin>>q;
    getchar();
    while (q--){
        getline(cin,s);
        stringstream s1(s);
        string p;
        while (s1>>tmp){
            p+=tmp[0];
        }
        if (mp.count(p)){
            cout<<mp[p][0];
            for (int i=1;i<(int)mp[p].size();i++)    
                cout<<"|"<<mp[p][i];
            cout<<endl;
        }
        else
            cout<<s<<endl;
    }
}