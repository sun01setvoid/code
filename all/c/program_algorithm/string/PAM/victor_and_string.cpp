#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int s[N]; // 字符串
struct node
{
    int son[26];
    int len;
    int fail; // 当前位置的更小的回文串的后缀的位置，没有时为0，也标志着中间的回文串长度为0,也是从中间回文串长度为0开始找;
    int siz;
    void init(int _len){
        memset(son,0,sizeof(son));
        fail=siz=0;
        len=_len;
    }
} tr[N];
ll L, R, num, ans, last[2];
// last存开始找最长回文后缀的地方，因为有插入到最前面的情况,所以要记录前面的最长回文串
//至于是回文串的头和尾，那并不重要，只要是回文串记录到就行
//回文串不光是两边，要求中间的子串也是回文串
void init()
{
    memset(s,-1,sizeof s);//值里有0
    L = 1e5 + 8, R = 1e5 + 7;
    ans = 0, num = 1;//0和1都有树了
    last[0] = last[1] = 0;
    tr[1].init(-1);// 可以符合单个时的奇数情况，很符合
    tr[0].init(0);
    //初始化在前面要不要tr[0].fail会变成0
    tr[0].fail = 1; // 0指向1:一开始从0开始找，后来找，1不可能找不到，tr[1].fail不用管,也有偶数更小找不了了，开始找奇数的意思
    //1->0必不可能,1的时候一定会处理，0的时候更小的回文后缀就是1了，至于比1更小的没有了，我们不妨就另它为0
}
int getfail(int p, int d)
{
    // 到达偶回文树根节点0了还会往奇回文树跳,奇数的时候一定存在单个的回文串
    if (d)
        while (s[R - tr[p].len - 1] != s[R])
        {
            p = tr[p].fail;
        }
    else
        while (s[L + tr[p].len + 1] != s[L])
        {
            p = tr[p].fail;
        }
    return p;
}
void insert(int x, int d)
{
    if (d)
        s[++R] = x;
    else
        s[--L] = x;
    int fa = getfail(last[d], d); // 不断跳回寻找，一定能找到
    int now = tr[fa].son[x];//可能这个回文串已经出现过了，不用记录？感觉是不一样的位置回文串一定不一样
    if (!now)
    {
        now = ++num; // 不同回文串个数
        tr[now].init(tr[fa].len + 2);
        tr[now].fail = tr[getfail(tr[fa].fail, d)].son[x];
        //存在时，直接记下当前位置下一个最长的要跳的位置，不存在时，就是跳到0（代表中间的回文串长度为0）
        //接下来再跳到1（代表中间的回文串长度为-1,也就是自己和自己）
        tr[now].siz = tr[tr[now].fail].siz + 1;
        tr[fa].son[x] = now;
        //先找，后赋值（因为可能找到自己），fail指针为0（就是找不到了中间有回文串,也确定了当前回文后缀没有可匹配的更小，就将他设为0，所以长度<=0）
    }
    last[d] = now;
    if (R - L + 1 == tr[now].len)
        last[d ^ 1] = now;//达到了另一边的位置，导致另一边的最大回文串更新
    ans += tr[now].siz;//以now为终点的回文串等于他的fail的回文串数量再加1（最新找到的最长回文串），总的回文串数量就等于所有的加起来了
    //char ch=x+'a';
    //cout<<"fa= "<<fa<<",me="<<now<<",char="<<ch;
    //cout<<",fail="<<tr[now].fail<<",len="<<tr[now].len<<endl;
}
int main()
{
    int op, n;
    while (scanf("%d", &n) != EOF)
    {
        init();
        while (n--)
        {
            char c;
            scanf("%d", &op);
            if (op == 1)
                scanf(" %c", &c),insert(c - 'a', 0);//" %c"可以防读入空白符
            else if (op == 2)
                scanf(" %c", &c),insert(c - 'a', 1);
            else if (op == 3)
                printf("%lld\n", num - 1);
            else if (op == 4)
                printf("%lld\n", ans);
        }
    }
    return 0;
}