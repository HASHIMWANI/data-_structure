#include <stdio.h>
#include <stdlib.h>

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
    return 1;
}


int create()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if(temp == NULL){
            printf("Memory allocation failed for %d node", i+1);
            exit(0);
        }

        printf("Enter the %d data: ",i+1);
        scanf("%d",&temp->data);

        temp->next = NULL;
        temp->prev = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    tail->next = head;
    head->prev = tail;
    return n;
}


void insert(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation failed");
        exit(0);
    }
    printf("Enter the data to be inserted: ");
    scanf("%d",&temp->data);
    int p,i=1;
    while(1){
        printf("Enter the position at which you want to insert this node: ");
        scanf("%d",&p);
        if(p<1 || p>n+1)
            printf("invalid position\n");
        else
            break;
    }

    if(p==n+1){
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        tail = temp;
        return;
    }

    struct node *trav = head;
    while(i<p+1){

        if(i==p){
            if(i==1){
                temp->next = head;
                temp->prev = tail;
                head->prev = temp;
                tail->next = temp;
                head = temp;
            }else{
                trav->prev->next = temp;
                temp->prev = trav->prev;
                trav->prev = temp;
                temp->next = trav;
            }
            return;
        }i++;
        trav = trav->next;
    }
}

void show()
{
    struct node *temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}


void _delete()
{
    int data;
    printf("Enter the data you want to delete: ");
    scanf("%d",&data);
    struct node *trav = head;
    while(trav->next != head){
        struct node *temp = trav;
        if(temp->data == data){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            if(temp == head){
                head = temp->next;
            }
            free(temp);
        }
        trav = trav->next;
    }
    if(trav == head && trav == tail && trav->data == data){
        head = NULL;
        tail = NULL;
        free(trav);
        printf("The list is empty\n");
        exit(1);
    }
    if(trav->data == data){
        trav->next->prev = trav->prev;
        trav->prev->next = head;
        tail = trav->prev;
        free(trav);
    }
}
