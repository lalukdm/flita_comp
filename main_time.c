// сщртировка шелла
// сортировка вставками
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int read_nums(FILE *file, int **arr, int str_point) {
    int size = 0;
    int d, count = 0;

    while (fscanf(file, "%d", &d) && !feof(file)) {
        
        *arr = realloc(*arr, ++size * sizeof(int));
        (*arr)[size-1] = d;
        
        if (getc(file) == '\n') break;
    }

    return size;
}


int main() {
    
    int *arr = NULL;
    int lenth;

    //read file input, SHELL sort for all str

    FILE *input = fopen("input.txt", "r");
    for (int i = 0; lenth = read_nums(input, &arr, i); i++) {
        
        FILE *out = fopen("out_shell.txt", "a");
        struct timeval start_time, end_time, elapsed_time;
        gettimeofday(&start_time, NULL);
    
        
        shellSort(arr, lenth);


        gettimeofday(&end_time, NULL);
        long int elapsed_time_us = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
        fprintf(out, "%d\t%ld\n", lenth, elapsed_time_us);
        fclose(out);

        for (int i = 0; i < lenth; i++) {
            printf("%d ", arr[i]);
        }
        
    }
    fclose(input);




    //read file input, INSERTION sort for all str

    input = fopen("input.txt", "r");
    for (int i = 0; lenth = read_nums(input, &arr, i); i++) {
        puts("dfas");
        FILE *out = fopen("out_insertion.txt", "a");
        struct timeval start_time, end_time, elapsed_time;
        gettimeofday(&start_time, NULL);
    
        
        insertionSort(arr, lenth);


        gettimeofday(&end_time, NULL);
        long int elapsed_time_us = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
        fprintf(out, "%d\t%ld\n", lenth, elapsed_time_us);
        fclose(out);

        for (int i = 0; i < lenth; i++) {
            printf("%d ", arr[i]);
        }
        puts("");
    }
    fclose(input);
    
    

    

    

    free(arr);
    

    return 0;
}