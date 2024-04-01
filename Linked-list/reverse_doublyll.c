
#include <stdio.h>
#include<stdlib.h>
typedef struct dllnode
{
    int data;
    struct dllnode *next, *back;
} dllnode;


dllnode *create()
{
    dllnode* temp,*current;
    int val;
    printf("enter data for head dllnode and -1 to exit.\n");
    scanf("%d", &val);
    if (val == -1)
        return NULL;
    dllnode *head = (dllnode *)malloc(sizeof(dllnode));
    head->data=val;
    head->back=NULL;
    current= head;
    do
    {
        printf("enter data for head dllnode and -1 to exit.\n");
        scanf("%d", &val);
        if (val == -1) break;
        else{
            temp=(dllnode*)malloc(sizeof(dllnode));
            temp->data=val;
            current->next=temp;
            temp->back=current;
            current=temp;
        }
    } while (val != -1);
    current->next=NULL;
    return head;
}

dllnode* reverse(dllnode* head){
    if(head==NULL) return NULL;
    dllnode* ptr1=head;
    dllnode* ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->back=ptr2;
    while (ptr2!=NULL)
    {
        ptr2->back=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->back;
    }
    head=ptr1;
    return head;
}


void trav_forward(dllnode *head)
{
    dllnode *curr = head;
    printf("Reverse Traversal :");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    dllnode* head=create();
    head=reverse(head);
    trav_forward(head);
    return 0;
}
