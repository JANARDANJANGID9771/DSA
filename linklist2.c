
#include <stdio.h>
#include <stdlib.h>

// for deleting first element of the linked list

struct Node
{
    int Data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->Data);
        ptr = ptr->next;
    }
}

// case1: Deleting for the  element from the linked list

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// case2: Deleting for first element at a given index from the linked list

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

// case3: Deleting the last  element      

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

// case4: Deleting for first element with a given value from the linked list

struct Node *deleteAtIndex(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data !=value && q->next!= NULL)
    
    {
        p = p->next;
        q = q->next;
    }

   if(q->data == value){
     p->next = q->next;
     free(q); 
     
   }
    

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

    head->Data = 9;
    head->next = second;

    second->Data = 23;
    second->next = third;

    third->Data = 33;
    third->next = fourth;

    fourth->Data = 88;
    fourth->next = NULL;

    printf("Linked list befor deletion\n");
    linkedListTraversal(head);

    // for deleting first element of the linklist
    // head = deleteFirst(head);
     head = deleteAtLast(head);
    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}