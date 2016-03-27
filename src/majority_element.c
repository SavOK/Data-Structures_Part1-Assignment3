#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * \brief Check if majority element present
 * Check if majority element is present in array.
 * __IMPORTANT__ O(N) 
 *
 * \param[in] A array of integers (long*)
 * \param[in] size_a size of array (size_t)
 * \return 1 is majority element present 0 otherwise (int)
 * */
int majority_element(long* A, size_t size_a);

/*
 * \brief Check if majority element present
 * Check if majority element is present in array.
 * __IMPORTANT__ O(ln(N)) 
 *
 * \param[in] A array of integers (long*)
 * \param[in] size_a size of array (size_t)
 * \return 1 is majority element present 0 otherwise (int)
 * */
int majority_element_sort(long* A, size_t size_a);

int compare(const void* a, const void* b) {
    const long* A = a;
    const long* B = b;
    if (*A < *B) return -1;
    if (*A == *B) return 0;
    if (*A > *B) return 1;
}

int main() {
    long i, N;
    long* Array;
    scanf("%ld", &N);
    Array = (long*) malloc(sizeof(long) * N);
    i = 0;
    int count = 0;
    long test = 0;
    while (i < N) {
        scanf("%ld", &Array[i]);
        i++;
    }
    //check simplest cases
    if (N == 1) {
        count = 1;
    } else {
        count = majority_element(Array, N);
//        maj = majority_element_sort(Array, N);
    }

    printf("%d\n", count);
    free(Array);
}

int majority_element(long* a, size_t size_a) {

    long count, i, curr_num;
    curr_num = a[0];
    count = 0;

    // get element with the biggest frequency 
    // 
    for (i = 1; i < size_a; i++) {
        if (a[i] == curr_num) count++;
        else if (count == 0) {
            curr_num = a[i];
            count = 0;
        } else count--;
    }
    // check if element is majority element
    count = 0;
    for (i = 0; i < size_a; ++i) {
        if (curr_num == a[i]) count++;
    }
    if (count > size_a / 2)
        return 1;
    else return 0;
}

int majority_element_sort(long* A, size_t size_a) {

    long Mid, median, count;
    long i;

    Mid = size_a / 2;
    count = 0;

    // sort array
    qsort(A, size_a, sizeof(long), &compare);
    median = A[Mid];

    // check if median is majority element
    for (i = 0; i < size_a; ++i) {
        if (median == A[i]) count++;
    }
    if (count > Mid) return 1;
    else return 0;
}

