/*Implement insertion sort using Binary search as key*/
#include <stdio.h>
int binarySearch(int arr[], int n, int low,int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == n)
            return mid; 
        else if (arr[mid] < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++){
      int key=arr[i];
      int j=i-1;

      int pos=binarySearch(arr,key,0,j);

      while (j>=pos)
      {
        arr[j+1]=arr[j];
       j--;
      }

      arr[j+1]=key;
      
    }

}
void printArr(int arr[],int n){
  for(int i=0;i<n;i++){
    printf("%d",arr[i]);
    printf("\n");
  }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printf("\nsorted array : \n");
    printArr(arr,n);
    

    return 0;
}
