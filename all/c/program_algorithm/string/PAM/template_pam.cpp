// lg p5496
//回文自动机（PAM）
#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
struct node
{
    int fail;
    int len;
    int siz;
    int son[26];
} tr[N];
int s[N], cnt[N], idx, i,last;
char str[N];
void init()
{
    idx = 1;
    tr[0].len = 0;
    tr[1].len = -1;
    tr[0].fail = 1; // 注意，少了就超时
    s[0] = -1;      // 保证不相等
    i = 1;
    last=0;//是trie中节点的位置
    // memset(tr,0,sizeof tr);
}
int getfail(int p)
{ // 先是以他结尾的最大回文串为中间的回文串，然后再不断缩小中间回文串的长度
    while (s[i] != s[i - tr[p].len - 1])
    {
        p = tr[p].fail;
    }
    return p;
}
void insert(int x)
{
    int fa = getfail(last);
    int now = tr[fa].son[x];//相同的已经在字典树中的子串会被找到
    if (!now)
    {
        now = ++idx;
        tr[now].len = tr[fa].len + 2;
        tr[now].fail = tr[getfail(tr[fa].fail)].son[x];
        tr[now].siz = tr[tr[now].fail].siz + 1; // 这里的tr[now].fail因为是在大回文串中，且取得已经出现过的，所以是镜像对称过的
        tr[fa].son[x]=now;
    }
    cnt[i] = tr[now].siz;//之前找到过的回文串找到的已经有答案了
    last=now;
    //char ch=x+'a';
    //cout<<"fa= "<<fa<<",me="<<now<<",char="<<ch;
    //cout<<",fail="<<tr[now].fail<<",len="<<tr[now].len<<endl;
}
int main()
{
    init();
    scanf("%s", str + 1);
    int l = strlen(str + 1);
    s[1] = str[1];
    insert(s[1] - 'a');
    for (i = 2; i <= l; i++)
    {
        s[i]=(str[i]-'a'+cnt[i-1])%26+97;
        insert(s[i] - 'a');
    }
    for (int i=1;i<=l;i++)  cout<<cnt[i]<<" ";
}