#include<stdio.h>
#include<stdlib.h>

void insert_ll();
void view_ll();
void free_ll();


struct employee
{
    char name[100];
    int id;
    int salary;
    struct employee *next;
};

struct employee *head = NULL, *tail = NULL;

int main()
{
    int ch;
    while(1){
        printf("enter your choice (1 -> insert, 2 -> view, any other exit) ");
        scanf("%d",&ch);
        if(ch==1)
            insert_ll();
        else if(ch==2)
            view_ll();
        else
            break;
    }
    free_ll();
    return 0;
}

void insert_ll()
{
    int number_of_employee;
    printf("Enter number of employees: ");
    scanf("%d",&number_of_employee);
    struct employee *temp;
    for(int i = 1; i <= number_of_employee; i++)
    {
        temp = (struct employee*)malloc(sizeof(struct employee));
        printf("Enter name and id of employee: ");
        scanf("%s%d",temp->name,&temp->id);
        printf("Enter salary of the employee: $");
        scanf("%d",&temp->salary);
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
}

void view_ll()
{
    struct employee *temp;
    temp=head;
    while (temp != NULL)
    {
        printf("Name: %s \nId: %d \nSalary: %d\n\n",temp->name,temp->id,temp->salary);
        temp=temp->next;
    }
    
}

void free_ll()
{
    struct employee *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL; 
}
