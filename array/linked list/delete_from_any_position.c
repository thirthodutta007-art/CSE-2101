
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void deletePosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list\n");
        return;
    }

    if (pos == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));

    a->data = 10;
    a->next = b;

    b->data = 20;
    b->next = c;

    c->data = 30;
    c->next = NULL;

    head = a;

    printf("Before deletion: ");
    display();

    deletePosition(2);

    printf("After deletion: ");
    display();

    return 0;
}
