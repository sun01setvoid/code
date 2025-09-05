#include<stdio.h>
#include<string.h>
int main()
{
    int i, j=0, k=0, m, n=0, x;
    char str[500010], a[500010];
    gets(str);
    x = strlen(str);
    for(i=x-1, j=x-1;i>=0;i--)
        if(str[i]=='\x20' || i==0)
        {
            if(k == 1) a[n] = '\x20', n++, k=0;//k标记每次做完只输出一个' '，最后一次没有' '
            for(m=i;m<=j;m++)
                if(str[m] != '\x20')//要输出没有' ',可以在输出的时候把他省略，这是一种省略式编程，不追求精确性
                {
                    a[n] = str[m];
                    n++;
                    k=1;
                }
            j = i;
        }
    a[n] = '\0';
    for(i=n-1;i>=0;i--)
    {
        if(a[i] == '\x20') a[i] = '\0';
        else break;
    }
    puts(a);
    return 0;
}