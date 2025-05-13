#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Gagal mengalokasikan memori.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* new_node = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void printList(struct Node* head) {
    printf("Isi linked list: ");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void printMiddle(struct Node* head) {
    int count = countNodes(head);
    if (count == 0) {
        printf("List kosong.\n");
        return;
    }

    int middleIndex = count / 2;
    struct Node* current = head;
    for (int i = 0; i < middleIndex; i++) {
        current = current->next;
    }

    printf("Simpul tengah: %d\n", current->data);
}

void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head_ref = NULL;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);

    printList(head);
    printMiddle(head);

    freeList(&head);
    return 0;
}
