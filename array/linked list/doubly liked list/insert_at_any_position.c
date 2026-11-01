
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
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
    insertPosition(10, 1);
    insertPosition(30, 2);
    insertPosition(20, 2);

    display();

    return 0;
}
