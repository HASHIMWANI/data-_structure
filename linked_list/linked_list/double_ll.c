#include<stdio.h>
#include<stdlib.h>

int create();
void show();
void insert(int);
void _delete();

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

int main()
{
    int n = create();
    show();
    insert(n);
    show();
    _delete();
    show();
    return 0;
}

int create(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i = 0; i <n; i++){

        struct node *temp = (struct node*)malloc(sizeof(struct node));
        if(temp == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter the %d data: ", i+1);
        scanf("%d",&temp->data);
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
            temp->prev = NULL;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    return n;
}

void insert(int n){
    struct node *temp =(struct node *)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter the data to be inserted: ");
    scanf("%d",&temp->data);

    int p,i=1;
    while(1){
        printf("Enter the position at which you want to insert it: ");
        scanf("%d",&p);
        if(p>n+1 || p<1){
            printf("Invalid position\n");
            continue;
        }
        else
            break;
    }

    if (p==n+1)
    {
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        return;
    }

    struct node *trav = head;
    while(trav != NULL){
        if(i==p){
            if(i==1){
                temp->prev = NULL;
                temp->next = trav;
                trav->prev = temp;
                head = temp;
                break;
            }
            else{
                trav->prev->next = temp;
                temp->prev = trav->prev;
                trav->prev = temp;
                temp->next = trav;
                break;
            }
        }
        i++;
        trav = trav->next;
    }
}

void _delete(){
    struct node *temp = head;
    int n;
    printf("Enter the data to be deleted: ");
    scanf("%d",&n);

    while (temp != NULL){
        if (temp->data == n){
            struct node *trav = temp;

            if (temp == head && temp == tail){
                free(temp);
                head = NULL;
                tail = NULL;
                printf("The list is empty");
                return;
            }

            else if (temp == head){
                temp->next->prev = NULL;
                head = temp->next;
            }
            else if (temp == tail){
                temp->prev->next = NULL;
                tail = temp->prev;
                temp = NULL;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(trav);
        }

        if (temp != NULL) {
            temp = temp->next;
        }
    }

    if (head == NULL){
        printf("The list is empty\n");
    }
}

void show(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}