#include <iostream>
#include <map>
using namespace std;
map <string ,int> mp;
int main(){
    int t,n;
    string s,tmp;
    cin>>t;
    while (t--){
        cin>>n>>s;
        for (int i=1;i<=n;i++){
            cin>>tmp;
            mp[tmp]=i;
        }
        if(mp.count(s)) cout<<mp[s]<<endl;
        else   cout<<-1<<endl;
    }
}