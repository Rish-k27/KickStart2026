#include <stdio.h>
#define S 100


void input_array(int *array) {
    for (int i = 0; i < S; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}


void reverse_array(int *array) {
    int temp;
    for (int i = 0; i < S / 2; i++) {
        temp = array[i];
        array[i] = array[S - i - 1];
        array[S - i - 1] = temp;
    }
}

// Function to print array
void print_array(int *array) {
    for (int i = 0; i < S; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[S];

    printf("Max size of array = %d\n", S);

    input_array(array);

    printf("Original array:\n");
    print_array(array);

    reverse_array(array);

    printf("Reversed array:\n");
    print_array(array);

    return 0;
}
