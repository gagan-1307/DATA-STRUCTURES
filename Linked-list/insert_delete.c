#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *create() {
    node *temp, *current;
    int choice;
    printf("Enter 1 to create head node and 0 to exit.\n");
    scanf("%d", &choice);
    if (choice == 0)
        return NULL;
    node *head = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &head->data);
    current = head;
    do {
        printf("Enter 1 to create new node and 0 to exit\n");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        else {
            temp = (node *)malloc(sizeof(node));
            printf("\nEnter the data: ");
            scanf("%d", &temp->data);
            current->link = temp;
            current = temp;
        }
    } while (choice != 0);
    current->link = NULL;
    return head;
}

node *insert_after_val(node *head, int value) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    node *p1 = head;
    while (p1->data != value) {
        p1 = p1->link;
        if (p1 == NULL) {
            printf("No such element found in the list.\n");
            return head;
        }
    }

    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!!");
        return head;
    }
    int newval;
    printf("Enter value to insert: ");
    scanf("%d", &newval);
    newNode->data = newval;
    newNode->link = p1->link;
    p1->link = newNode;
    return head;
}

int delete_after_val(int val, node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return -1; // Indicate failure
    }
    node *p1 = head, *temp = NULL;
    while (p1->data != val) {
        p1 = p1->link;
        if (p1 == NULL) { /* Element not present in linked list */
            printf("No such element found in the list.\n");
            return -1; // Indicate failure
        }
    }
    temp = p1->link;
    if (temp != NULL) {
        int deletedVal = temp->data;
        p1->link = temp->link;
        free(temp);
        return deletedVal;
    } else {
        printf("Deletion not possible.\n");
        return -1; // Indicate failure
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
    int choice, val, delval;
    do {
        printf("1. Create linked list\n2. Insert any element\n3. Delete any element\n4. Traverse\n5. Stop: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = create();
                break;
            case 2:
                printf("Enter the element to insert after: ");
                scanf("%d", &val);
                head = insert_after_val(head, val);
                break;
            case 3:
                printf("Enter the value of element after which to delete: ");
                scanf("%d", &val);
                delval = delete_after_val(val, head);
                if (delval != -1)
                    printf("Deleted value: %d\n", delval);
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
