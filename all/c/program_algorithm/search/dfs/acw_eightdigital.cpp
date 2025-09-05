#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
unordered_map <string,int> d;//hash
void bfs(string s){
    string end="12345678x";
    queue <string> q;
    q.push(s);
    d[s]=0;
    while (!q.empty()){
        string cur=q.front();
        q.pop();
        int distance=d[cur];
        if (cur==end){
            cout<<d[cur];
            return;
        }
        int t=cur.find('x');//
        int x=t/3,y=t%3;
        for (int i=0;i<4;i++){
            int xi=x+dir[i][0];
            int yi=y+dir[i][1];
            if (xi < 0 || xi >3 || yi <0 || yi>3 )
                continue;
            else{
                swap(cur[t],cur[xi*3+yi]);
                if(!d.count(cur)){
                    q.push(cur);
                    d[cur]=distance+1;
                }
                swap(cur[t],cur[xi*3+yi]);
            }
        }
    }
    cout<<-1;
}
int main(){
    string s="";
    char ch;
    for (int i=0;i<9;i++){
        cin>>ch;
        s+=ch;
    }
    bfs(s);
    system("pause");
}