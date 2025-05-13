#include <stdio.h>
#include <stdlib.h>

int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum = 0;
    int count = 0;
    int temp = 0;
    int i = 0, j = 0;
    
    // Hitung berapa banyak yang bisa diambil dari stack A saja
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
        count++;
    }
    
    // Sekarang coba tambahkan dari stack B, sambil kurangi dari A jika perlu
    while (j < m && i >= 0) {
        sum += b[j];
        j++;
        
        // Jika melebihi maxSum, kurangi elemen dari A
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }
        
        // Update count jika kondisi terpenuhi
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }
    
    return count;
}

int main() {
    int g;
    scanf("%d", &g);
    
    while (g--) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);
        
        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(m * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        
        printf("%d\n", twoStacks(maxSum, a, n, b, m));
        
        free(a);
        free(b);
    }
    
    return 0;
}
