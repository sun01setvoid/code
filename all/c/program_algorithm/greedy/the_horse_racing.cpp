#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
//要考虑最大能否赢最大，最小能否赢最小
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    int a[1000];
    int b[1000];
    while (cin>>n && n!=0)
    {
        int money=0;
        for (int i=0;i<n;i++)    cin>>a[i]; 
        for (int i=0;i<n;i++)    cin>>b[i];
        sort(a,a+n,cmp);sort(b,b+n,cmp);
        int h1=0,t1=n-1,h2=0,t2=n-1;
        int flag[1000]={0};
        while (h1<=t1 && h2<=t2){
            if (a[h1]>b[h2]){
                money+=200;
                h1++,h2++;
            }
            else if (a[h1]==b[h2]){
                if (a[t1]>b[t2])    money+=200,t1--,t2--;
                //如果不处理这样，只有最多会是0，但是如果这样是由可能净胜200的
                //不写这个,那么3 3 2，3 3 1的话就会使代码错误
                else{
                    if(a[t1]<b[h2])    money-=200;
                    t1--,h2++;
                }
            }
            else{
                money-=200;
                t1--,h2++;
            }
        }
        printf("%d\n",money);
    }

}