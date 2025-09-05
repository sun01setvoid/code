#include <stdio.h>
int main()
{
int count =0;
int i=2;
int L;
int sum=0;
scanf("%d",&L);
while (sum<=L)
{
     if (i==2 )
    {
      sum+=i;
if (sum<=L)
      {printf("%d",i);
     count+=1;}
     }
     else
    {
          int flag=1;
           for (int j=2;j<i;j++)
           { 
          if (i%j==0)
          {
                 flag=0;
            }
          }
          if (flag)
           {
           sum+=i;
         if (sum<=L)
          {printf(" %d",i);
         count+=1;}
           }
          
     }
     i++;
}
printf("\ncount = %d",count);
return 0;
}