// сщртировка шелла
// сортировка вставками
#include <stdio.h>
#include <stdlib.h>

// void shellSort(int arr[], int n) {
//     int gap = n / 2;
//     while (gap > 0) {
//         for (int i = gap; i < n; i++) {
//             int temp = arr[i];
//             int j;
            
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                 arr[j] = arr[j - gap];

//             arr[j] = temp;
//         }
//         gap /= 2;
//     }
// }

int increment(long inc[], long size) {
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2)
            inc[s] = 8 * p1 - 6 * p2 + 1;
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);

    return s > 0 ? --s : 0;
}

void shellSort(int a[], long size) {
    long inc, j, seq[40];
    int gap = increment(seq, size);

    while (gap >= 0) {
        inc = seq[gap--];

        for (long i = inc; i < size; i++) {
            int temp = a[i];
            for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
                a[j + inc] = a[j];

            a[j + inc] = temp;
        }
    }
}

int read_nums(FILE *file, int **arr) {
    int size = 0;
    int d;
    char c;
    while (c != '\n' && fscanf(file, "%d", &d) == 1) {
        *arr = realloc(*arr, ++size * sizeof(int));
        (*arr)[size-1] = d;
        c = getc(file);
    }
    return size;
}

int main() {
    
    int *arr = NULL;

    FILE *file = fopen("input.txt", "r");
    int lenth = read_nums(file, &arr);
    fclose(file);

    shellSort(arr, lenth);

    for (int i = 0; i < lenth; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

// int main() {
//     FILE *file;
//     int *array;
//     int size = 0;

//     // Open the file
//     file = fopen("file.txt", "r");
//     if (file == NULL) {
//         printf("Error opening file...\n");
//         exit(1);
//     }

//     // Read the first line and get the array size
//     char line[100];
//     fgets(line, sizeof(line), file);
//     sscanf(line, "%d", &size);

//     // Allocate memory for the array
//     array = (int*)malloc(size * sizeof(int));

//     // Read the array elements from the file and store them in the array
//     for (int i = 0; i < size; i++) {
//         fscanf(file, "%d", &array[i]);
//         printf("%d\n", array[i]);
//     }

//     // Close the file
//     fclose(file);

//     // Print the array elements
//     for (int i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     // Free memory
//     free(array);

//     return 0;
// }


