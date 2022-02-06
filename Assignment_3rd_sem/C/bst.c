
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *newN;
struct node *new_node()
{
    struct node *temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
void insertnode(struct node *root,struct node *newN)
{
    if (newN->data < root->data)
    {
        if (root->left==NULL)
        {
            root->left=newN;
        }
        else
        insertnode(root->left,newN);
    }
    if (newN->data > root->data)
    {
        if (root->right == NULL)
        {
            root->right=newN;
        }
        else
        insertnode(root->right,newN);
    }
    
    
}

void create_tree()
{
    root=NULL;
    char ch='y';
    while (ch=='y')
    {
        newN=new_node(root);
        printf("Enter data for new node:\n");
        scanf("%d",&newN->data);
        if (root==NULL)
        {
            root=newN;
        }
        else
        {
            insertnode(root,newN);
        }
        printf("Do you want to create more nodes?\n");
        scanf(" %c",&ch);
    }
        
}
void inoder(struct node *root)
{
    if (root!=NULL)
    {
        inoder(root->left);
        printf("%d ",root->data);
        inoder(root->right);
    }
    
}
void preoder(struct node *root)
{
    if (root!=NULL)
    {
        printf("%d ",root->data);
        preoder(root->left);
        preoder(root->right);
    }
    
}
void postoder(struct node *root)
{
    if (root!=NULL)
    {
        postoder(root->left);
        postoder(root->right);
        printf("%d ",root->data);
    }
    
}
void travesal(struct node *root)
{
    printf("\nInoder Traversal:\n");
    inoder(root);
    printf("\nPreoder Traversal:\n");
    preoder(root);
    printf("\nPostoder Traversal:\n");
    postoder(root);
    
}
int main()
{
    int choice;
    while (1)
    {
        printf("1.For Tree creation:\n");
        printf("2.For Traversal:\n");
        printf("3.To Exit:\n");
        printf("Enter Choice:\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            create_tree(root);
            break;
        case 2:
            if (root==NULL)
                printf("Tree not created:\n");
            else
                travesal(root);
            break;
        case 3:
            exit(1);
        }
    }
    
    return 0;
}
