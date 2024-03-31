#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *create() {
    node *temp, *current;
    int choice;
    printf("enter 1 to create start node and 0 to exit.\n");
    scanf("%d", &choice);
    if (choice == 0)
        return NULL;
    node *head = (node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d", &head->data);
    current = head;
    do {
        printf("enter 1 to create new node and  0 to exit\n");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        else {
            temp = (node *)malloc(sizeof(node));
            printf("\nEnter the data : ");
            scanf("%d", &temp->data);
            current->link = temp;
            current = temp;
        }
    } while (choice != 0);
    current->link = NULL;
    return head;
}

node *insert_at_start(node *head, int newval) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = newval;
    temp->link = head;
    head = temp;
    return head;
}

node *delete_at_start(node *head, int *delval) {
    if (head == NULL) {
        printf("The Linked List is Empty \n");
        return NULL;
    }
    *delval = head->data;
    node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

node *insert_at_pos(node *head, int pos) {
    int newval;
    printf("enter value to insert: ");
    scanf("%d", &newval);
    if (pos == 1) {
        head = insert_at_start(head, newval);
        return head;
    }

    int count = 1;
    node *p1 = head;
    while (count < pos - 1 && p1 != NULL) {
        p1 = p1->link;
        if (p1 == NULL) {
            printf("No such position found in the list.\n");
            return head;
        }
        count++;
    }

    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("memory allocation failed!!");
        return head;
    }

    newNode->data = newval;
    newNode->link = p1->link;
    p1->link = newNode;
    return head;
}

node *delete_at_pos(int *val, node *head, int pos) {
    if (pos == 1) {
        *val = head->data;
        head = delete_at_start(head, val);
        return head;
    }
    node *p1 = head, *temp = NULL;
    int count = 1;
    while (count < pos - 1 && p1 != NULL) {
        p1 = p1->link;
        if (p1 == NULL) {
            printf("No such position found in the list.\n");
            return head;
        }
        count++;
    }
    temp = p1->link;
    if (temp != NULL) {
        *val = temp->data;
        p1->link = temp->link;
        free(temp);
        return head;
    } else {
        printf("deletion not possible\n");
        return head;
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

int main() {
    node *head = NULL;
    int choice, pos, delval;
    do {
        printf("1. create linked list \n2. insert any element \n3. delete any element \n4. traverse \n5. stop: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = create();
                break;
            case 2:
                printf("Enter the position to insert element : ");
                scanf("%d", &pos);
                head = insert_at_pos(head, pos);
                break;
            case 3:
                printf("Enter the position to delete element : ");
                scanf("%d", &pos);
                head = delete_at_pos(&delval, head, pos);
                printf("deleted value: %d\n", delval);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
