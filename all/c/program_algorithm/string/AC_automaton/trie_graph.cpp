// hdu 2222 acw1282
//fail没有的时候都是指向根节点,根节点自环
//优化是trie图，不优化就是普通AC自动机
#include <iostream>
using namespace std;
const int N = 1e6+10, M = 2e6 + 10;
int tr[N][26], ne[N], cnt[N], idx, q[N];
char str[M];
int n;
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        if (!tr[p][t])
            tr[p][t] = ++idx;
        p = tr[p][t];
    }
    cnt[p]++;
}
void getFail()
{
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i++)
    {
        if (tr[0][i])
            q[++tt] = tr[0][i];
    }
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = 0; i < 26; i++)
        {
            //优化  没有后续的话,tr[t][i]持续往后退，少一个循环
            int p=tr[t][i];
            if (!p) tr[t][i]=tr[ne[t]][i];//前面的层数已经做过之前的tr[ne[t]][i],所以这是不断（之前做过操作）跳跃的指针
            else{
                ne[p]=tr[ne[t]][i];//本次只做新的是否能匹配，不能匹配，则调用之前的跳跃
                q[++tt]=p;
            }
            /*
            int c = tr[t][i];
            if (!c)
                continue;
            int j = ne[t]; // ne[t]=0是根节点，因为从根节点开始，可以找到他们，所以是对的
            while (j && !tr[j][i])
                j = ne[j];
            if (tr[j][i])
                j = tr[j][i];
            ne[c] = j;
            q[++tt] = c;
            */
        }
    }
}
int query(char *str)
{
    int res = 0;
    for (int i = 0, j = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        /*
        while (j && !tr[j][t])
            j = ne[j];
        if (tr[j][t])
            j = tr[j][t];
        int p = j;
        */
       int p=j=tr[j][t];
        while (p && ~cnt[p])
        {
            res += cnt[p];
            cnt[p] = -1;//标记为走过，0不行因为j这个点可能没有，但他的后缀可能是出现的
            p = ne[p];
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        insert(str);
    }
    scanf("%s", str);
    getFail();
    printf("%d", query(str));
}
