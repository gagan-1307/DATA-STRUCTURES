#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;


node *create()
{
    node* temp,*current;
    int val;
    printf("enter data for head node and -1 to exit.\n");
    scanf("%d", &val);
    if (val == -1)
        return NULL;
    node *head = (node *)malloc(sizeof(node));
    head->data=val;
    current= head;
    do
    {
        printf("enter data for head node and -1 to exit.\n");
        scanf("%d", &val);
        if (val == -1) break;
        else{
            temp=(node*)malloc(sizeof(node));
            temp->data=val;
            current->link=temp;
            current=temp;
        }
    } while (val != -1);
    current->link=NULL;
    return head;
}

node* reverse(node *head){
    if(head==NULL) return NULL;
    node* curr=head->link;
    node* prev=head;
    head->link=NULL;
    while (curr!=NULL)
    {
    node* nextnode=curr->link;
        curr->link=prev;
        prev=curr;
        curr=nextnode;
    }
    head=prev;
    return head;
}


void trav_forward(node *head)
{
    node *curr = head;
    printf("Reverse Traversal :");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}

int main(){
    node* head=create();
    head=reverse(head);
    trav_forward(head);
    return 0;

}
