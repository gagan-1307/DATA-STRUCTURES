
#include <stdio.h>
#include<stdlib.h>
typedef struct dllnode
{
    int data;
    struct dllnode *next, *back;
} dllnode;

dllnode *create()
{
    dllnode *temp, *curr;
    int val;
    printf("Enter val for head node: ");
    scanf("%d", &val);
    if (val == -1)
    {
        return NULL;
    }
    dllnode *head = (dllnode *)malloc(sizeof(dllnode));
    head->data = val;
    head->back = NULL;
    curr = head;
    do
    {
        printf("Enter the data to be added(-1 to stop) : ");
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        dllnode *temp = (dllnode *)malloc(sizeof(dllnode));
        temp->data = val;
        curr->next = temp;
        temp->back = curr;
        curr = temp;
    } while (val != -1);
    curr->next = NULL;
    return head;
}

dllnode *insert_before_val(dllnode *head, int val, int newval)
{
    if (head == NULL)
    {
        printf("empty list. can't insert before val");
        return head;
    }
    dllnode *curr, *temp, *temp2;
    curr = head;
    while ((curr != NULL) && (curr->data) != val)
    {
        curr = curr->next;
    }

    temp = (dllnode *)malloc(sizeof(dllnode));
    temp2 = curr->back;
    temp->data = newval;
    curr->back = temp;
    temp->next = curr;
    temp->back = temp2;
    if (temp2 != NULL)
    {
        temp2->next = temp;
    }
    else
    {
        head = temp;
    }
    return head;
}

dllnode *delete_before_val(dllnode* head,int val)
{
    int delval;
    dllnode *curr, *temp;
    curr=head;
    while ((curr != NULL) && (curr->data) != val)
    {
        curr = curr->next;
    }
    temp=curr->back;
    delval=temp->data;
    printf("deleted value:%d",delval);
    curr->back=temp->back;
    if (temp->back!=NULL)
    {
        temp->back->next=curr;
    }
    else head=curr;
    free(temp);
    return head;
}

void insertAfterVal(dllnode *head, int val, int newval)
{
    dllnode *temp, *curr;
    curr=head;
    while (curr->data != val)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("val not found!");
    }
    temp = (dllnode *)malloc(sizeof(dllnode));
    temp->data = newval;
    temp->next = curr->next;
    if (curr->next != NULL)
    {
        (curr->next)->back = temp;
    }
    curr->next = temp;
    temp->back = curr;
}

int delAfterVal(dllnode *head, int val)
{
    int delval;
    dllnode *temp, *curr;
    curr = head;
    while (curr->data != val)
    {
        curr = curr->next;
    }
    temp = curr->next;
    delval = temp->data;
    curr->next = temp->next;
    (temp->next)->back = curr;
    free(temp);
    return delval;
}

void trav_forward(dllnode *head)
{
    dllnode *curr = head;
    printf("Forward Traversal :");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void trav_backward(dllnode *head)
{
    dllnode *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    printf("Backward Traversal :");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->back;
    }
    printf("\n");
}

int main()
{
    dllnode* head = NULL;
    int choice, val, newval, len, delval;

    do {
        printf("Enter the choice :\n");
        printf("1. Create new LL\n");
        printf("2. Traverse forward and backward\n");
        printf("3. Insert after val\n");
        printf("4. Delete after val\n");
        printf("5. Insert before val\n");
        printf("6. Delete before val\n");
        printf("7. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = create();
                break;
            case 2:
                printf("Forward traversal:\n");
                trav_forward(head);
                printf("Backward traversal:\n");
                trav_backward(head);
                break;
            case 3:
                printf("Enter the value after which you want to insert: ");
                scanf("%d", &val);
                printf("Enter the new value to insert: ");
                scanf("%d", &newval);
                insertAfterVal(head, val, newval);
                break;
            case 4:
                printf("Enter the value after which you want to delete: ");
                scanf("%d", &val);
                delval = delAfterVal(head, val);
                printf("Deleted value: %d\n", delval);
                break;
            case 5:
                printf("Enter the value before which you want to insert: ");
                scanf("%d", &val);
                printf("Enter the new value to insert: ");
                scanf("%d", &newval);
                head = insert_before_val(head, val, newval);
                break;
            case 6:
                printf("Enter the value before which you want to delete: ");
                scanf("%d", &val);
                head = delete_before_val(head, val);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while(choice != 7);

    return 0;
}