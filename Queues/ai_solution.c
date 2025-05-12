#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    printf("Masukkan jumlah manik-manik (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah manik-manik harus positif.\n");
        return 1;
    }

    int *necklace = (int *)malloc(n * sizeof(int));

    printf("Masukkan nilai untuk setiap manik-manik:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &necklace[i]);
    }

    printf("Masukkan jumlah geseran ke kiri (k): ");
    scanf("%d", &k);

    int *modified_necklace = (int *)malloc(n * sizeof(int));

    // Melakukan pergeseran
    for (int i = 0; i < n; i++) {
        int new_position = (i - k % n + n) % n;
        modified_necklace[new_position] = necklace[i];
    }

    printf("Kalung setelah modifikasi: ");
    for (int i = 0; i < n; i++) {
        printf("%d", modified_necklace[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(".\n");

    free(necklace);
    free(modified_necklace);

    return 0;
}
