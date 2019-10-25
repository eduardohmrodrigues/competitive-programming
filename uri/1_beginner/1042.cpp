#include <cstdio>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int arr[], int l, int r){
	// No need to sort an array with length < 1
	if(l >= r-1){
		return;
	}

	int pivot = arr[r-1];
	int index = l;

	for(int i=l; i<r; i++){
		if(arr[i] <= pivot){
			swap(&arr[i], &arr[index]);
			index++;
		}
	}

	quicksort(arr, l, index-1);
	quicksort(arr, index, r);
}

int main(){
	int arr[] = {0, 0, 0};
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	int a = arr[0]; int b = arr[1]; int c = arr[2];
	quicksort(arr, 0, 3);
	
	printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", arr[0], arr[1], arr[2], a, b, c);	

	return 0;
}
