/*Given an array A of length n that was orignally sortedin ascending order and then rotated by k steps ,
 it might now become unsorted now,determine the length of the contiguous sun-array A[i...j] such that ;
A[m]>=A[m-1] for all k in the range (0<m<=n-1)*/

#include <stdio.h>

int main() {
    int n, k;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    printf("Enter no. of rotation: ");
    scanf("%d", &k);

    int A[n], B[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the Element of A[%d] : ", i);
        scanf("%d", &A[i]);
    }

    
    for (int i = 0; i < n; i++) {
        B[(i+k)%n] = A[i];
    }


    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    // Print rotated array
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Find longest non-decreasing contiguous subarray
    int maxLen = 1;
    int currLen = 1;

    for (int i = 1; i < n; i++) {
        if (A[i] >= A[i-1]) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
            }
            currLen = 1;
        }
    }
    if (currLen > maxLen) {
        maxLen = currLen;
    }

    printf("Longest non-decreasing contiguous subarray length = %d\n", maxLen);

    return 0;
}
