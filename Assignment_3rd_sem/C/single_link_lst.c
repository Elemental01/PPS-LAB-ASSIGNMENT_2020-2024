#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;
struct Node *new_node, *temp;

void add_pos()
{
    int pos;
    int n;
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);
    pos -= 1;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value you want to insert: ");
    scanf("%d", &n);
    new_node->data = n;
    struct Node *ptr = start;

    while (ptr != NULL && pos != 0)
    {
        ptr = ptr->next;
        pos--;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void del_pos()
{
    int pos, n;
    printf("Enter the postion you want to delete: ");
    scanf("%d", &pos);
    pos -= 2;
    struct Node *ptr = start;
    struct Node *temp = start->next;

    while (ptr != NULL && pos != 0)
    {
        ptr = ptr->next;
        temp = temp->next;
        pos--;

    }
    ptr->next = temp->next;
    free(temp);
}

void del_begin()
{
    struct Node *ptr = start;
    // struct Node * p = start
    start = start->next;
    free(ptr);
}

void del_between()
{
    int n;
    int x = 0;
    printf("Delete a nunber a given value: ");
    scanf("%d", &n);

    struct Node *ptr = start;
    while (ptr->next)
    {
        if (ptr->data == n)
        {
            struct Node *p = ptr->next;
            ptr->next = ptr->next->next;
            free(p);
            x = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (x == 0)
        printf("The given element is not present");
}

void del_end()
{
    struct Node *ptr = start;
    struct Node *temp = start->next;

    while (temp->next)
    {
        temp = temp->next;
        ptr = ptr->next;
    }

    ptr->next = NULL;
    free(temp);
}

void rev_list()
{
    struct Node *prev = NULL;
    struct Node *current = start;
    struct Node *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void add_begin()
{
    int data;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d", &new_node->data);
    new_node->next = start;
    start = new_node;
}

void add_between()
{
    int n, data, p = 0;
    printf("Insert a node after a given value: ");
    scanf("%d", &n);

    struct Node *ptr = start;
    while (ptr)
    {
        if (ptr->data == n)
        {
            new_node = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the data for the created Node: ");
            scanf("%d", &data);
            new_node->data = data;
            new_node->next = ptr->next;
            ptr->next = new_node;
            p = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (p == 0)
        printf("The given number is not present\n");
}

void add_end()
{
    int data;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d", &new_node->data);
    struct Node *ptr = start;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
}

void create_list()
{

    char ch = 'y';
    while (ch == 'Y' || ch == 'y')
    {

        new_node = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the value of new node: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        if (start == NULL)
            start = new_node;
        else
        {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
        printf("want to create another node?: ");
        scanf(" %c", &ch);
    }
}

void Display()
{

    struct Node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    int choice;
    char ch = 'y';
    while (1)
    {
        printf("\n Press 1- Create a Linked List");
        printf("\n Press 2- Insert the Node at the begin");
        printf("\n Press 3- Insert a Node at the between");
        printf("\n Press 4- Insert a Node at the end");
        printf("\n Press 5- Display the Linked List");
        printf("\n Press 6- Reverse the linked list");
        printf("\n Press 7- Delete a node from the begin");
        printf("\n Press 8- Delete a node after a given value");
        printf("\n Press 9- Delete a node from the end");
        printf("\n Press 10- Add a node a given position");
        printf("\n Press 11- remove a node a given position");
        printf("\n Press 12- Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_list();
            break;
        case 2:
            add_begin();
            break;
        case 3:
            add_between();
            break;
        case 4:
            add_end();
            break;
        case 5:
            Display();
            break;
        case 6:
            rev_list();
            break;
        case 7:
            del_begin();
            break;
        case 8:
            del_between();
            break;
        case 9:
            del_end();
            break;
        case 10:
            add_pos();
            break;
        case 11:
            del_pos();
            break;
        case 12:
            exit(1);
        }
    }
    return 0;
}