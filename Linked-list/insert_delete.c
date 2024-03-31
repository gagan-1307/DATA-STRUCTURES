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
    int choice;
    printf("enter 1 to create start node and 0 to exit.\n");
    scanf("%d", &choice);
    if (choice == 0)
        return NULL;
    node *head = (node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d", &head->data);
    current= head;
    do
    {
        printf("enter 1 to create new node and  0 to exit\n");
        scanf("%d", &choice);
        if (choice == 0) break;
        else{
            temp=(node*)malloc(sizeof(node));
            printf("\nEnter the data : ");
            scanf("%d",&temp->data);
            current->link=temp;
            current=temp;
        }
    } while (choice != 0);
    current->link=NULL;
    return head;
}


void insert_after_val(node *head, int value)
{
    if (head==NULL)
    {
        printf("The list is empty.\n");
        return ;
    }
    
    node *p1;
    p1 = head;
    while (p1->data!=value)
    {
        p1=p1->link;
        if (p1==NULL)
        {
            printf("No such element found in the list.\n");
            return;
        }
    }
    
    node *newNode = (node*) malloc(sizeof(node));
    if (newNode==NULL)
    {
        printf("memory allocation failed!!");
        return ;
    }
    int newval;
    printf("enter value to insert: ");
    scanf("%d",&newval);
    p1->data=newval;
    newNode->data=newval;
    newNode->link=p1->link;
    p1->link=newNode;
    
}

int delete_after_val(int val,node* head){
    if (head==NULL)
    {
        printf("linked list is empty.\n"); 
        exit(0); 
    }
    node* p1,*temp;
    p1=head;
    temp=NULL;
    while(p1->data != val){
        p1=p1->link;
        if(p1 == NULL)     /*element not present in linked list */
        {
            return -100;
        }
    }
    temp = p1->link;
    if(temp!=NULL){
    int newval=temp->data;
    p1->link = temp->link;    
    free(temp);  
    return newval;
    }

    else{
        printf("deletion not possile\n");
        return -100;
    }
}


void traverse(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    node *start;
    start = create();
    printf("Linked list created:\n");
    traverse(start); 

    int val;
    printf("Enter a value after which you want to insert: ");
    scanf("%d", &val);
    insert_after_val(start, val);
    printf("Linked list after insertion:\n");
    traverse(start); 

    int delval;
    printf("Enter a value after which you want to delete: ");
    scanf("%d", &delval);
    int deleted_value = delete_after_val(delval, start); 
    if (deleted_value != -100) {
        printf("Deleted value: %d\n", deleted_value);
        printf("Linked list after deletion:\n");
        traverse(start); 
    }

    return 0;
}
