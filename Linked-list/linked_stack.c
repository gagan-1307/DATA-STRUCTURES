
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

void push(node** top,int val){
   node* temp=(node*)malloc(sizeof(node));
   temp->data=val;
   temp->link=*top;
   (*top)=temp;
}

int pop(node** top){
    if (*top==NULL)
    {
        printf("empty stack!!!");
        return -100;
    }
    int val=(*top)->data;
    node* temp=*top;
    *top=(*top)->link;
    free(temp);
    return val;
}

void display(node** top) {
    node* current = *top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}

int main() {
    node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    display(&top);

    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));
    
    display(&top);

    return 0;
}
