#include <stdio.h>
#include <stdlib.h>

int gameOfTwoStacks(int maxSum, int firstCount, int* first, int secondCount, int* second) {
    int count = 0;
    int sum = 0;
    int i = 0;

    // Ambil elemen dari stack pertama selama memungkinkan
    while (i < firstCount && sum + first[i] <= maxSum) {
        sum += first[i];
        i++;
        count++;
    }

    int maxCount = count;
    int j = 0;

    // Coba ambil elemen dari stack kedua setelah mengambil beberapa dari stack pertama
    while (j < secondCount) {
        sum += second[j];
        j++;

        while (sum > maxSum && i > 0) {
            i--;
            sum -= first[i];
        }

        if (sum <= maxSum) {
            if (i + j > maxCount) {
                maxCount = i + j;
            }
        }
    }
    return maxCount;
}

int main() {
    int g;
    scanf("%d", &g);

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int firstCount, secondCount, maxSum;
        scanf("%d %d %d", &firstCount, &secondCount, &maxSum);

        int *first = malloc(firstCount * sizeof(int));
        for (int i = 0; i < firstCount; i++) {
            scanf("%d", &first[i]);
        }

        int *second = malloc(secondCount * sizeof(int));
        for (int j = 0; j < secondCount; j++) {
            scanf("%d", &second[j]);
        }

        int result = gameOfTwoStacks(maxSum, firstCount, first, secondCount, second);
        printf("%d\n", result);

        free(first);
        free(second);
    }

    return 0;
}
