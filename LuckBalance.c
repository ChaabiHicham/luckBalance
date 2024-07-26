#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int luckBalance(int k, int contests_rows, int contests_columns, int** contests) {
    int totalchance = 0;
    int* importantContest = (int*)malloc(contests_rows * sizeof(int));
    int importantCount = 0;

   
    for (int i = 0; i < contests_rows; i++) {
        int luck = contests[i][0];
        int important = contests[i][1];
        
        if (important==1) {
            importantContest[importantCount++] = luck;
        } else {
            totalchance += luck;
        }
    }

    
    qsort(importantContest, importantCount, sizeof(int), compare);

    for (int i = 0; i < importantCount; i++) {
        if (i < k) {
            totalchance += importantContest[i];
        } else {
            totalchance -= importantContest[i];
        }
    }

   

    return totalchance;
}
