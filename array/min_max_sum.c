#include <stdio.h>
#include <limits.h>

int main() {
    int arr[5] = {1, 3, 5, 7, 9};
    int min = INT_MAX;
    int max = INT_MIN;
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];

        if (arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        
    }
    int min_sum = sum - max;
    int max_sum = sum - min;
    printf("%d %d\n", min_sum, max_sum);

    return 0;
}