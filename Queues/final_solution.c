#include <stdio.h>

void MovetoLeft(int element[], int n, int k) {
    int temporary[k];
    for (int i = 0; i < k; i++) {
        temporary[i] = element[i];
    }

    for (int i = k; i < n; i++) {
        element[i - k] = element[i];
    }

    for (int i = 0; i < k; i++) {
        element[n - k + i] = temporary[i];
    }
}

int main() {
    int n, k;
    printf("Masukkan jumlah mutiara (n): ");
    scanf("%d", &n);
    
    int element[n];
    printf("Masukkan bilangan bulat pada mutiara: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element[i]);
    }

    printf("Masukkan jumlah rotasi ke kiri (k): ");
    scanf("%d", &k);

    k = k % n;
    MovetoLeft(element, n, k);

    printf("Kalung setelah dimodifikasi:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", element[i]);
    }
    printf("\n");

    return 0;
}
