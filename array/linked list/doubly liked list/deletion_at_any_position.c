
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void deletePosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list\n");
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));

    a->data = 10;
    a->prev = NULL;
    a->next = b;

    b->data = 20;
    b->prev = a;
    b->next = c;

    c->data = 30;
    c->prev = b;
    c->next = NULL;

    head = a;

    printf("Before deletion: ");
    display();

    deletePosition(2);

    printf("After deletion: ");
    display();

    return 0;
}
