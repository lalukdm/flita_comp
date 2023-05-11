*arr = realloc(*arr, ++size * sizeof(int));
        (*arr)[size-1] = d;
        for (int i = 0; i < size; i++) {
            printf("%d ", (*arr)[i]);
        