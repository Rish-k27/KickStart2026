/*Implement a C program that utilises fork() system
 call to perform a distributed search for two distinct key within an array.
The program must demonstrate sequentiam process synchronization and use process exist 
statuses to comunicate the result back to the parent.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main() {
int arr[30], key1, key2, status;
pid_t p1, p2;
srand(time(NULL));
printf("Array: ");
for (int i = 0; i < 30; i++) {
arr[i] = rand() % 50 + 1;
printf("%d ", arr[i]);
}
printf("\n\nEnter Key 1 and Key 2: ");
scanf("%d %d", &key1, &key2);
//Child 1
p1 = fork();
if (p1==0) {
    for (int i = 0; i <= 14; i++)
    {
      if(arr[i]==key1){
        return i;
      }
      else{
        exit(255);
      }
    }
    
}
// Parent waits for Child 1
waitpid(p1, &status, 0);
int res1 = WEXITSTATUS(status);

//Child 2
p2 = fork();
if (p2==0) {
for (int i = 15; i <=29 ; i++)
    {
      if(arr[i]==key2){
        return i;
      }
      else{
        return 255;
      }
      exit(0);
    }
}
//Parent waits for Child 2
waitpid(p2, &status, 0);
int res2 = WEXITSTATUS(status);
return 0;
}
