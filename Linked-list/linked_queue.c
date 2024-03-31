#include<stdio.h>
#include<stdlib.h>

// node structure
typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct Queue{
    node* front;
    node* rear;
} Queue;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void insertq(Queue* q, int value) {
    node* newNode = createNode(value);
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int deleteq(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete.\n");
        exit(EXIT_FAILURE);
    }
    int deletedValue = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return deletedValue;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);

    insertq(&q, 10);
    insertq(&q, 20);
    insertq(&q, 30);

    display(&q);

    printf("Deleted element: %d\n", deleteq(&q));
    printf("Deleted element: %d\n", deleteq(&q));

    display(&q);

    return 0;
}
