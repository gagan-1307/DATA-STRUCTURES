#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int exp, coeff;
    struct node *next;
} node;
node *inputPoly(node **head)
{
    node *temp, *current;
    int choice;
    printf("Enter 1 to create a start node and 0 to exit.\n");
    scanf("%d", &choice);
    if (choice == 0)
        return NULL;
    *head = (node *)malloc(sizeof(node));
    printf("Enter the exp and coeff : ");
    scanf("%d%d", &((*head)->exp), &((*head)->coeff));
    current = *head;
    do
    {
        printf("Enter 1 to create a new node and  0 to exit.\n");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        else
        {
            temp = (node *)malloc(sizeof(node));
            printf("Enter the exp and coeff : ");
            scanf("%d%d", &(temp->exp), &(temp->coeff));
            current->next = temp;
            current = temp;
        }
    } while (choice != 0);
    current->next = NULL;
    return *head;
}

node *addpoly(node *poly1, node *poly2)
{
    node *temp1 = poly1, *temp2 = poly2, *poly3 = NULL, *last = NULL;

    while ((temp1 != NULL) && (temp2 != NULL))
    {
        if (temp1->exp > temp2->exp)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->coeff = temp1->coeff;
            temp->exp = temp1->exp;
            if (poly3 == NULL)
            {
                poly3 = temp;
                last = temp;
            }
            else
            {
                last->next = temp;
                last = temp;
            }
            temp1 = temp1->next;
        }
        else if (temp2->exp > temp1->exp)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->coeff = temp2->coeff;
            temp->exp = temp2->exp;
            if (poly3 == NULL)
            {
                poly3 = temp;
                last = temp;
            }
            else
            {
                last->next = temp;
                last = temp;
            }
            temp2 = temp2->next;
        }
        else
        {
            if ((temp1->coeff + temp2->coeff) != 0)
            {
                node *temp = (node *)malloc(sizeof(node));
                temp->coeff = temp1->coeff + temp2->coeff;
                temp->exp = temp1->coeff;
                if (poly3 == NULL)
                {
                    poly3 = temp;
                    last = temp;
                }
                else
                {
                    last->next = temp;
                    last = temp;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }

    while (temp1 != NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->coeff = temp1->coeff;
        temp->exp = temp1->exp;
        if (poly3 == NULL)
        {
            poly3 = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    while (temp2 != NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->coeff = temp2->coeff;
        temp->exp = temp2->exp;
        if (poly3 == NULL)
        {
            poly3 = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    last->next = NULL;
    return poly3;
}

void displayPoly(node *poly3)
{
    node *temp = poly3;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }
}

int main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;
    node *poly3 = NULL;

    printf("Enter details for polynomial 1:\n");
    inputPoly(&poly1);

    printf("Enter details for polynomial 2:\n");
    inputPoly(&poly2);

    poly3 = addpoly(poly1, poly2);

    printf("Resulting polynomial after addition: ");
    displayPoly(poly3);
    return 0;
}