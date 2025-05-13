#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Fungsi untuk mencetak middle node (kedua jika genap)
void printMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Fast bergerak 2 langkah, slow 1 langkah
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow sekarang berada di middle (atau second middle jika jumlah genap)
    if (slow != NULL)
        printf("Middle node: %d\n", slow->data);
}

// Fungsi untuk menambahkan node ke akhir linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Main program
int main() {
    struct Node* head = NULL;

    // Contoh input: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);

    printMiddle(head);  // Output: 40

    return 0;
}
