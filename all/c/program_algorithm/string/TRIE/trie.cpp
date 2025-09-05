//lg P2580
#include <iostream>
using namespace std;
const int N=5e6+10;
struct node
{
    bool repeat;//查询时这个前缀是否重复
    int son[26];//26个字母
    int num;//这个前缀出现的次数,可以统计以此为前缀的单词个数;
    bool isend;//是否为单词的结尾
}tr[N];//tr可struct对每个点编码,多叉树每个点有自己的编号，根节点为0
int idx;
string str;
void Insert(string &str){
    int p=0;
    for (int i=0;i<str.size();i++){
        int u=str[i]-'a';
        if (!tr[p].son[u])  tr[p].son[u]=++idx;
        p=tr[p].son[u];
    }
    tr[p].isend=1;
}
int Find(string &str){
    int p=0;
    for (int i=0;i<str.size();i++){
        int u=str[i]-'a';
        if (!tr[p].son[u])  return 3;
        p=tr[p].son[u];   
    }
    if (!tr[p].isend)   return 3;
    if (tr[p].repeat)  return 2;
    tr[p].repeat=1;
    return 1;
}
int n,m;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>str;
        Insert(str);
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>str;
        int status=Find(str);
        if (status==1)  puts("OK");
        else if (status==2) puts("REPEAT");
        else   puts("WRONG");
    }
}