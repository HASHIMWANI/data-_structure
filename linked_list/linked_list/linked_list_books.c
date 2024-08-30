#include<stdio.h>
#include<string.h>

struct Books
{
    char name[200];
    char author[200];
    int edition;
    int pages;
    int price;
    struct Books *next;
};

void get_data(struct Books*);
void print_details(struct Books*);

int main()
{
    struct Books b1,b2,b3;
    get_data(&b1);
    b1.next=&b2;
    get_data(&b2);
    b2.next=&b3;
    get_data(&b3);
    b3.next=NULL;
    print_details(&b1);
}

void get_data(struct Books *b)
{
    printf("Enter the name of the book: ");
    fgets(b->name, 200, stdin);
    // Remove newline character if present
    if ((strlen(b->name) > 0) && (b->name[strlen(b->name) - 1] == '\n'))
    {
        b->name[strlen(b->name) - 1] = '\0';
    }

    printf("Enter the author of the book: ");
    fgets(b->author, 200, stdin);
    // Remove newline character if present
    if ((strlen(b->author) > 0) && (b->author[strlen(b->author) - 1] == '\n'))
    {
        b->author[strlen(b->author) - 1] = '\0';
    }
    printf("Enter the edition: ");
    scanf("%d",&b->edition);
    getchar();
    printf("Enter number of pages: ");
    scanf("%d",&b->pages);
    getchar();
    printf("Enter price: $");
    scanf("%d",&b->price);
    getchar();
}

void print_details(struct Books *b)
{
    printf("%-30s %-20s %-10s %-10s %-10s\n\n", "Name", "Author", "Edition", "Pages", "Price");

    struct Books *x = b;
    while (x != NULL)
    {
        printf("%-30s %-20s %-10d %-10d $%-9d\n", x->name, x->author, x->edition, x->pages, x->price);
        x = x->next;
    }
}

