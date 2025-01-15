#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int s[], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        j = i;
        while ((j > 0) && (s[j] < s[j - 1])) {
            swap(&s[j], &s[j - 1]);
            j = j - 1;
        }
    }
}

void print_array(int s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main() {
    int s[] = {9, 8, 7, 6, 5, 4, 3, 2};
    int n = sizeof(s) / sizeof(s[0]);
    printf("Original array: ");
    print_array(s, n);

    insertion_sort(s, n);

    printf("Sorted array: ");
    print_array(s, n);
    return 0;
}
