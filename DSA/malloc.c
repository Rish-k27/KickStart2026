#include<stdio.h>
#include<stdlib.h>
int main(){
   int n ;
   printf("Enter the size of array : ");
   scanf("%d",&n);

    int* arr=(int*)malloc(n*4);
    if (arr == NULL) {
        printf("Memory not allocated");
        return 1;
    }



    for (int i = 0; i <n; i++)
    {
      printf("Enter the element : ");
      scanf("%d",& arr[i]);

    }
    int key;

    printf("Enter the key :");
    scanf("%d",&key);
   // printf("\n");
    
    int found=0;
    for (int i = 0; i < n; i++)
    {
      if(arr[i]==key){
          printf("Key is on the index : %d",i+1); 
          found=1;
          break;
        }}

        if (!found)
        {
          printf("Not found");
        }
        
    
    free(arr);
  return 0; 

}
