#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<vector<int>> tmp;
        for (int i=1;i<=n;i++){
            int li;
            cin>>li;
            vector<int> vec;
            for (int j=1;j<=li;j++){
                int x;
                cin>>x;
                vec.push_back(x);
            }
            reverse(vec.begin(),vec.end());
            tmp.push_back(vec);
        }
        while (tmp.size()){

        }
    }
}