#include <stdio.h>
#include <stdlib.h>

int *read() {
    int n, size, val;
    scanf("%d", &n);
    int *array = (int *)malloc((n + 1) * size);
    if (array == NULL) {
        return NULL;
    }
    int cnt = 0;
    while (scanf("%d", &val) == 1) {
        cnt++;
        if (cnt > n) {
            n *= 2;
            array = realloc(array, n * sizeof(int));
            if (array == NULL) {
                return NULL;
            }
        }
        array[cnt] = val;
    }

    if (cnt < size) {
        array = realloc(array, (cnt + 1) * sizeof(int));
        if (array == NULL) {
            return NULL;
        }
    }
    array[0] = cnt;
    return array;
}