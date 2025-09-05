//总共有增删改查的操作。分为更新位置在头节点和不在头结点，遍历时应该要有前指针（更新时在步骤最后）和后指针，这时头节点和非头结点的同异
//同在于插入结点的自身属性都要操作
//异①头结点的更新②链接的更新（前) 前头前链接（先连后删），先连后断(后是一样的，若在头节点成立，后链接就是一开始的头结点，前后指针还没开始)
//初始查询先置后指针为head(解决头位置后链接的情况),在过程中建立前后指针，
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lnode{
    int data;
    int pos;
    struct lnode *next;
};                  
//设置一个空头节点可以使链表使用更简单因为不会遇到处理头节点的情况，p1=head,p2=head->next;!!!!!!!!!!!!
/*输入
struct lnode *readlist(){
    int n;
    struct lnode *head,*p1,*p2;
    head=p1=NULL;//初始化
    while(scanf("%d",&temp) && n!=-1){
        p2=(struct lnode *)malloc(sizeof(struct lnode));
        p2->data=temp;p2->next=NULL;
        if (head==NULL)    head=p2;
        else p1->next=p2;
        p1=p2;//前后指针
    }
    return head;
}
*/
/*
按要求更改
struct lnode *updatelist( struct lnode *head, int pos,x){
    struct lnode *p1,*p2;
    for (struct lnode * p2=head;p2;p2=p2->next){
        if (pos==p2->pos){
            p2->data=x;
        }
        p1=p2;
    }
    return head;
}
*/
/*  按要求删除
struct lnode *deletelist( struct lnode *head, int min_score ){
    struct lnode *p1,*p2;
    for (struct lnode * p2=head;p2;p2=p2->next){
        if (min_score>p2->score){
            if (p2==head)    head=p2->next;
            else     p1->next=p2->next;
            free(p2);
        }
        else    p1=p2;
    }
    return head;
}
*/
