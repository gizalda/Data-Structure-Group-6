#include <stdio.h>

void rotateLeft(int arr[], int n, int k) {
    int temp[k];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int n, k;
    printf("Masukkan jumlah mutiara (n): ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Masukkan elemen kalung:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Masukkan jumlah rotasi ke kiri (k): ");
    scanf("%d", &k);

    k = k % n;
    rotateLeft(arr, n, k);

    printf("Kalung setelah dimodifikasi:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
