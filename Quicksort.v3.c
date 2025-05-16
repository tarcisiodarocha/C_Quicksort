#include<stdio.h>
#include <time.h>

void swap(int* a, int* b) {
   int t = *a;
   *a = *b;
   *b = t;
}

int partition (int arr[], int low, int high) {
   int pivot = arr[high];
   int i = (low - 1);
   for (int j = low; j <= high- 1; j++){
      if (arr[j] <= pivot){
         i++;
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i + 1], &arr[high]);
   return (i + 1);
}

void quickSort(int arr[], long int low, long int high){
   if (low < high){
      long int pi = partition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }
}

void printArray(int arr[], int size){
   int i;
   for (i=0; i < size; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

int main(){

   long int n = 300000000;
   int *arr = (int*)malloc(n * sizeof(int));
   srand(0);
   long int i;
   for (i = 0; i < n; i++) {
      arr[i] = rand() % n;
   }
   
   
   clock_t start, end;
   double cpu_time_used;
     
   start = clock();
   quickSort(arr, 0, n-1);
   end = clock();
  
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   
   printf("CLOCKS_PER_SEC: %ld \n", CLOCKS_PER_SEC);
   printf("CPU time used is: %f \n", cpu_time_used);
   
   
   return 0;
}