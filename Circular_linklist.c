
/*
circular linklist
circular linklist are use for while and do while loop
Allter native link list

this link list are head pointer

Empty singly Linklist

this difine pointer = NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkListTraversal(struct Node *head)
{
    // pointer
    struct Node *ptr = head;

    // using for loop for do while loop

    do
    {
        printf("Element  is  %d \n ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// memory allocate  in ptr
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 88;
    second->next = third;

    // Link third and fourth nodes ;
    third->data = 33;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 44;
    fourth->next = head;
    
    printf("circular Link list befor  insertion\n");
    linkListTraversal(head);
    head = insertAtFirst(head, 54);
    printf(" circular Link list  after insertion\n");
    linkListTraversal(head);
    return 0;
}