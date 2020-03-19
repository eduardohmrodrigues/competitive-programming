#include <cstdio>
#include <iostream>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void merge(int arr[], int l, int m, int r){
    int cl=0, sm=m-l, cr=sm+1, sr=r-l, size=(r-l)+1, ind = l;
    int arrCp[size];
    for(int i=0; i<size; ++i){
        arrCp[i] = arr[l+i];
    }
    
    while(ind < r+1){
       if(cl > sm || (cr <= sr && arrCp[cl] > arrCp[cr])){
            arr[ind] = arrCp[cr];
            ++cr;
       }else{
            arr[ind] = arrCp[cl];
            ++cl;
       }

       ++ind;
    }
}

void mergeSort(int arr[], int l, int r){
	// No need to sort an array with length < 2
	if(l < r){
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
	int arr[] = {10, 7, 8, 9, 1, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 99, 43, 129, 320, 1, 1, 0, -5, 44, 211, 5};
//   	int arr[] = {0, -1, 2, 0, 5, -5, 12, -122, 54, 234};
    int n = sizeof(arr) / sizeof(arr[0]);
//	printArray(arr, n);
   	mergeSort(arr, 0, n-1);
	printf("Sorted array: \n");
	printArray(arr, n);

	return 0;
}