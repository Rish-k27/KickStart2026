#include <stdio.h>


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoid overflow

        if (arr[mid] == key) {
            return mid;  // found at index mid
        }
        else if (arr[mid] < key) {
            low = mid + 1;  // search right half
        }
        else {
            high = mid - 1; // search left half
        }
    }

    return -1;  // not found
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}
