#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_L sizeof(long)

struct Segment {
    long start;
    char end;
};

/*!
 * \brief Prints array of Segments
 * Check function prints the array of Segments for debugging and testing purposes
 *
 * \param[in] segments array of Segments (Segment*).
 * \param[in] size of array (size_t)
 */
void print_segments(const struct Segment *segments, size_t size);

int compareSegment(const void *a, const void *b);

int comparePoint(const void *a, const void *b);

void count_inside(const struct Segment *segments, size_t size_s,
                  long *SortPoints, size_t NumPoints);

int main() {
    long num_seq, i, num_p;

    int K = scanf("%ld %ld", &num_seq, &num_p);

    long Max = num_seq * 2 + num_p;
    struct Segment *segments =
            (struct Segment *) malloc(sizeof(struct Segment) * Max);
    if (!segments) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < num_seq) {
        scanf("%ld %ld", &segments[2 * i].start, &segments[2 * i + 1].start);
        segments[2 * i].end = 'l';
        segments[2 * i + 1].end = 'r';
        i++;
    }

    long *pointSort = (long*) calloc((size_t) num_p, SIZE_L);
    long *pointInput =(long*) calloc((size_t) num_p, SIZE_L);
    long *pointMatch = (long*) calloc((size_t) num_p, SIZE_L);
    if (!pointMatch) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < num_p) {
        scanf("%ld", &segments[num_seq * 2 + i].start);
        segments[num_seq * 2 + i].end = 'p';
        pointInput[i] = segments[num_seq * 2 + i].start;
        i++;
    }

    memcpy(pointSort, pointInput, SIZE_L * num_p);

    qsort(segments, (size_t) Max, sizeof(struct Segment), &compareSegment);
    qsort(pointSort, (size_t) num_p, SIZE_L, &comparePoint);

    count_inside(segments, (size_t) Max, pointMatch, (size_t) num_p);
    long *curr_p, pos, temp;
    for (i = 0; i < num_p; ++i) {
        curr_p = (long*) bsearch(&pointInput[i], pointSort, (size_t) num_p,
                                  SIZE_L, comparePoint);
        temp = (long) (curr_p - pointSort);
        printf("%ld ", pointMatch[temp]);

    }
    printf("\n");
    free(segments);
    free(pointMatch);
    free(pointInput);
    free(pointSort);
}

void print_segments(const struct Segment *segments, size_t size) {
    for (long i = 0; i < size; ++i) {
        printf("[%ld %c] ", segments[i].start, segments[i].end);
    }
    printf("\n");
}

int compareSegment(const void *a, const void *b) {
    const struct Segment *A = a;
    const struct Segment *B = b;
    if (A->start < B->start)
        return -1;
    else if (A->start > B->start)
        return 1;
    else {
        if (A->end < B->end)
            return -1;
        else if (A->end > B->end)
            return 1;
        else
            return 0;
    }
}

int comparePoint(const void *a, const void *b) {
    if (*(long*) a < *(long*) b)
        return -1;
    else if (*(long*) a == *(long*) b)
        return 0;
    else
        return 1;
}

void count_inside(const struct Segment *seg, size_t size_s,
                  long *sortP, size_t num_p) {
    long curr_s, curr_p, inside;
    curr_p = inside = curr_s = 0;
    for (; curr_s < size_s; ++curr_s) {
        if (seg[curr_s].end == 'l') {
            inside++;
        } else if (seg[curr_s].end == 'r') {
            inside--;
        } else if (seg[curr_s].end == 'p') {
            if (curr_p == num_p) {
                printf("SOMETHING IS WRONG WENT OUTSIDE OF ARRAY\n");
                return;
            }
            sortP[curr_p++] = inside;
//            curr_p++;
        }
    }
}
