#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student{
    struct Student* next_by_class;
    struct Student* next;
    int class_id;
    char name[16];
};
struct Student* InsertStudent(
    int class_id,
    const char* name,
    struct Student* next,
    struct Student** classes
){
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    student->class_id = class_id;
    student->next = next;
    strcpy(student->name, name);
    student->next_by_class = classes[class_id-1];
    classes[class_id-1] = student;
    return student;
}
void QueryClass(
    int class_id,
    struct Student** classes
){
    for(struct Student* p = classes[class_id-1]; p; p = p->next_by_class){
        printf("%s\n", p->name);
    }
}
struct Student* classes[2] = {NULL};
int main(){
    struct Student* head = NULL;
    for(;;){
        char cmd[8] = {0};
        char name[128] = {0};
        int class_id = 0;
        scanf("%s", cmd);
        if(strcmp(cmd, "insert")==0){
            scanf("%d%s", &class_id, name);
            char* s = name;
            while(*s == ' '){s++;}
            head = InsertStudent(class_id, s, head, classes);
        }else if(strcmp(cmd, "query") == 0){
            scanf("%d", &class_id);
            QueryClass(class_id, classes);
        }else{
            break;
        }
    }
    for(struct Student* p=head; p; p = p->next){
        printf("%d %s\n", p->class_id, p->name);
    }
    return 0;
}