#include<stdio.h>

struct student
{
    char name[20];
    int roll_no,marks;
    struct student *next;
};

void get_data(struct student*);
void print_data(struct student*);

int main()
{
    struct student s1,s2,s3;
    get_data(&s1);
    s1.next=&s2;
    get_data(&s2);
    s2.next=&s3;
    get_data(&s3);
    s3.next=NULL;
    print_data(&s1);

}

void get_data(struct student *s)
{
    printf("Enter name: ");
    scanf("%s",s->name);
    printf("Enter roll number: ");
    scanf("%d",&s->roll_no);
    printf("Enter marks: ");
    scanf("%d",&s->marks);
}

void print_data(struct student *s)
{
    struct student *current = s;
    printf("Name \t Roll No. \t Marks\n");
    while( current != NULL)
    {
        printf("%s \t %d \t\t %d\n",current->name,current->roll_no,current->marks);
        current = current->next;
    }
}
