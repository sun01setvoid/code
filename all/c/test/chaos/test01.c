#include <stdio.h>
#include <string.h>
struct stu
{
char id[6];
char name[10]; 
int score;
};
int main()
{
    int num;
    int j=0;
    scanf("%d",&num);
    struct stu stuarr[num];
    int lavg[num];
    for (int i=0;i<num;i++)
    {
    
        scanf("%s %s %d",stuarr[i].id,stuarr[i].name,&stuarr[i].score);
    }
    double sum=0;
    for (int i=0;i<num;i++)
    {
        sum+=stuarr[i].score;
    }
    double avg=sum/num;
    printf("%.2f",avg);
    for (int i=0;i<num;i++)
    {
        if(avg>stuarr[i].score)
        {   
            lavg[j]=i;
            j++;}
    }
    for (int i=0;i<j;i++)
    {printf("%s %s\n",stuarr[lavg[i]].name,stuarr[lavg[i]].id);}
    system("pause");
}