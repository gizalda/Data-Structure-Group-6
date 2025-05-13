#include <stdio.h>
#include <stdlib.h>

int gameOfTwoStacks(int maxSum, int firstCount, int* first, int secondCount, int* second) {
    int count = 0;
    int sum = 0;
    int i = 0, j = 0;

    // Ambil elemen dari kedua stack selama memungkinkan
    while (i < firstCount && sum + first[i] <= maxSum) {
        sum += first[i];
        i++;
        count++;
    }

    int maxCount = count;

    // Coba kembalikan elemen dari stack pertama dan ambil dari stack kedua
    while (j < secondCount) {
        sum += second[j];
        j++;

        while (sum > maxSum && i > 0) {
            i--;
            sum -= first[i];
        }

        if (sum <= maxSum && count < i + j) {
            count = i + j;
            if (count > maxCount) {
              maxCount = count;
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
