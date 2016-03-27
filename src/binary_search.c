#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

long binary_req(const long* a, long low, long high, long key) {
    if (high < low) {
        return low - 1;
    }
    long mid = low + (high - low) / 2;
    if (key == a[mid]) {
        return mid;
    }
    else if (key > a[mid]) {
        return binary_req(a, mid + 1, high, key);
    }
    else {
        return binary_req(a, low, mid - 1, key);
    }
}

long binary_search(const long* a, size_t arr_size, long x) {
    size_t left, right;
    left = 0;
    right = arr_size;
    long out = binary_req(a, left, right, x);
    if (out >= 0) {
        // check if element is present or went outside of range
        if (x != a[out])
            return -1;
    }
    return out;
}


int main() {
    long N, K, i;
    long* Array;
    long* Keys;
    scanf("%ld", &N);
    Array = (long*) malloc(sizeof(long) * N);
    i = 0;
    while (i < N) {
        scanf("%ld", Array + i);
        i++;
    }

    scanf("%ld", &K);
    Keys = (long*) malloc(sizeof(long) * K);
    i = 0;
    while (i < K) {
        scanf("%ld", Keys + i);
        i++;
    }

    for (i = 0; i < K; ++i) {
        printf("%ld ", binary_search(Array, N, Keys[i]));
    }
    printf("\n");
    free(Array);
    free(Keys);
    Array = NULL;
    Keys = NULL;
}
