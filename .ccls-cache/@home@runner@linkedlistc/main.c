#include <stdlib.h>
#include <stdio.h>

struct node_def
{
    int data;
    struct node_def *next;
};
typedef struct node_def node;

void printList(node *head);
int listLength(node *head);
node *insertEnd(node *head, int x);
node *insertFront(node *head, int x);
node *deleteEnd(node *head);
node *deleteFront(node *head);

int main()
{
    node *head = NULL;
    int length = listLength(head);
    printf("%d\n", length);

    head = insertEnd(head, 40);
    printList(head);
    head = insertFront(head, 5);
    printList(head);
    head = deleteEnd(head);
    printList(head);
    
    length = listLength(head);
    printf("%d\n", length);
    return 0;
}

node *insertEnd(node *head, int x)
{
    node *new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    node *temp = head;

    if(head == NULL)
    {
        head = new;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }

    return head;
}

node *insertFront(node *head, int x)
{
    node *new = malloc(sizeof(node));
    
    new->data = x;
    new->next = head;

    return new;
}

void printList(node *head)
{
    node *temp;
    temp = head;
    printf("HEAD->");
    while(temp != NULL)
    {
        printf("%3d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node *deleteEnd(node *head)
{
    node *temp = head;
    node *prev = head;
    if(head != NULL)
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        while(prev->next != temp)
        {
            prev = prev->next;
        }

        free(temp);
        prev->next = NULL;
    }

    return head;
}

node *deleteFront(node *head)
{
    node *temp = NULL;
    if(head != NULL)
    {
        temp = head->next;
        free(head);
    }
    
    return temp;
}

int listLength(node *head)
{
    int length = 0;
    node *temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    
    return length;
}
