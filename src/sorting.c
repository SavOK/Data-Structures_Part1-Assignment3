#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void exch(long* A, long* B);

int compare(const void* a, const void* b) {
    const long* A = a;
    const long* B = b;
    if (*A < *B) return -1;
    if (*A == *B) return 0;
    if (*A > *B) return 1;
}

/*!
 * \brief 3-way partition quick sort
 *  <pre>
 *
 *  move from left to find an element that is not less
 *  move from right to find an element that is not greater
 *  stop if pointers have crossed
 *  swap
 *  if left element equal, swap to left end
 *  if right element equal, swap to right end
 *  Swap equals to center after partition
 *
 * <pre>
 * */

void quicksort(long a[], long left, long right) {
    long i = left - 1, j = right, p = left - 1, q = right;
    long v = a[right];
    if (right <= left) return;
    for (; ;) {
        while (a[++i] < v);
        while (v < a[--j]) if (j == left) break;
        if (i >= j) break;
        exch(&a[i], &a[j]);
        if (a[i] == v) {
            p++;
            exch(&a[p], &a[i]);
        }
        if (v == a[j]) {
            q--;
            exch(&a[j], &a[q]);
        }
    }
    exch(&a[i], &a[right]);
    j = i - 1;
    i += 1;
    for (long k = left; k < p; k++, j--) exch(&a[k], &a[j]);
    for (long k = right - 1; k > q; k--, i++) exch(&a[i], &a[k]);
    quicksort(a, left, j);
    quicksort(a, i, right);
}

int main() {
    long i, N, * Array;
    scanf("%lld", &N);
    Array = (long*) malloc(sizeof(long) * N);
    i = 0;
    while (i < N) {
        scanf("%lld", &Array[i]);
        i++;
    }
//        qsort(Array, N, sizeof(long), &compare);
    quicksort(Array, 0, N - 1);
    for (i = 0; i < N; ++i) {
        printf("%lld ", Array[i]);
    }
    printf("\n");
    free(Array);
}

void exch(long* A, long* B) {
    long temp = *A;
    *A = *B;
    *B = temp;
}
