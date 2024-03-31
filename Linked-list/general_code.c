#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *start, *temp, *curr;
    int val, choice;
    printf("enter the value for head node of  linked list: ");
    scanf("%d", &val);
    start = (node*)malloc(sizeof(node));
    start->data = val;
    curr = start;

    do
    {
        printf("enter 1 to add node and 0 to stop: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        temp = (node *)malloc(sizeof(node));
        printf("Enter the data : ");
        scanf("%d", &val);
        temp->data = val;
        curr->next = temp;
        curr = temp;
    } while (choice != 0);
    curr->next = NULL;

    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}