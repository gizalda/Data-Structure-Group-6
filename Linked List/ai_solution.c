#include <stdio.h>
#include <stdlib.h>

// Struktur simpul (node)
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk membuat simpul baru
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Fungsi untuk mencari simpul tengah
int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Gunakan dua pointer: fast dan slow
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // maju 1 langkah
        fast = fast->next->next;    // maju 2 langkah
    }

    return slow->data; // slow akan berada di tengah (kedua jika genap)
}

// Fungsi utama (contoh penggunaan)
int main() {
    // Buat daftar tertaut: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);
    head->next->next->next->next->next = newNode(60);

    int middle = findMiddle(head);
    printf("Simpul tengah: %d\n", middle); // Output harusnya 40

    return 0;
}

