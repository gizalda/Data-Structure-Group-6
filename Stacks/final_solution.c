#include <stdio.h>
#include <stdlib.h>

int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum = 0;
    int count = 0;
    int temp = 0;
    int i = 0, j = 0;
    
    
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }
    count = i;
    
   
    while (j < m && i >= 0) {
        sum += b[j];
        j++;
        
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }
        
     
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }
    
    return count;
}

int main() {
    int g;
    printf("Masukkan jumlah test case: ");
    scanf("%d", &g);
    
    while (g--) {
        int n, m, maxSum;
        printf("\nMasukkan n m maxSum: ");
        scanf("%d %d %d", &n, &m, &maxSum);
        
        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(m * sizeof(int));
        
        printf("Masukkan elemen stack A (%d angka): ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        printf("Masukkan elemen stack B (%d angka): ", m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        
        int result = twoStacks(maxSum, a, n, b, m);
        printf("Jumlah maksimum elemen: %d\n", result);
        
        free(a);
        free(b);
    }
    
    return 0;
}
