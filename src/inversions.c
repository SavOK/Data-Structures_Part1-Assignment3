#include <stdio.h>
#include <stdlib.h>

/*!
 * \brief merges two list
 */
long merge(long *A, size_t left, size_t mid, size_t right);

long merge_sort(long *A, long left, long right);

int main() {
    long N, i, *Array;
    scanf("%ld", &N);
    Array = (long *) malloc(sizeof(long) * N);
    i = 0;
    while (i < N) {
        scanf("%ld", &Array[i]);
        i++;
    }
    long count;
    count = merge_sort(Array, 0, N);
    printf("%ld\n", count);
}

long merge(long *A, size_t left, size_t mid, size_t right) {
    size_t curr_l, curr_r, curr_b;
    size_t max_b = right - left;
    curr_l = left;
    curr_r = mid;
    curr_b = 0;
    long count = 0; //count inverse

    // temp array to store sorted list
    long *B = (long *) calloc(max_b, sizeof(long));

    while ((curr_l < mid) && (curr_r < right)) {
        if (A[curr_l] <= A[curr_r]) {
            B[curr_b] = A[curr_l];
            curr_l++;
        }
        else {
            B[curr_b] = A[curr_r];
            curr_r++;
            count += (mid - curr_l); // count number of inversions
        }
        curr_b++;
    }
    while (curr_l < mid) {
        B[curr_b++] = A[curr_l++];
    }
    while (curr_r < right) {
        B[curr_b++] = A[curr_r++];
    }
    //
    for (long i = 0; i < max_b; ++i) {
        A[left + i] = B[i];
    }
    free(B);
    B = NULL;
    return count;
}

long merge_sort(long *A, long left, long right) {
    if (right - left < 2) {  // if run size == 1
        return 0;
    }
    long Count = 0;
    long mid = (right - left) / 2 + left;
    Count = merge_sort(A, left, mid);  // split / merge left  half
    Count += merge_sort(A, mid, right);  // split / merge right half
    Count += merge(A, left, mid, right);  // merge the two half runs
    return Count;
}
