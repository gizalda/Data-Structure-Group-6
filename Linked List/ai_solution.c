#include <stdio.h>
#include <stdlib.h>

// Struktur simpul (node)
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* buatNode(int data) {
    struct Node* nodeBaru = (struct Node*)malloc(sizeof(struct Node));
    nodeBaru->data = data;
    nodeBaru->next = NULL;
    return nodeBaru;
}

// Fungsi untuk menambahkan node ke akhir linked list
void tambahNode(struct Node** head, int data) {
    struct Node* baru = buatNode(data);
    if (*head == NULL) {
        *head = baru;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
}

// Fungsi untuk menemukan node tengah
int simpulTengah(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // bergerak 1 langkah
        fast = fast->next->next;   // bergerak 2 langkah
    }
    return slow->data;
}

// Fungsi utama
int main() {
    struct Node* head = NULL;

    // Contoh input: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    tambahNode(&head, 10);
    tambahNode(&head, 20);
    tambahNode(&head, 30);
    tambahNode(&head, 40);
    tambahNode(&head, 50);
    tambahNode(&head, 60);

    int hasil = simpulTengah(head);
    printf("Simpul tengah: %d\n", hasil);  // Output: 40

    return 0;
}
