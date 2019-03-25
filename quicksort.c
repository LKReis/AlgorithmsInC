#include <stdio.h>

void quickSort(int arr[], int p, int r);
int partition(int arr[], int p, int r);
void swap(int arr[], int p, int r);

int main(void){

int arr[5];

printf("Enter 5 numbers \n"); //prompt user for array

//loop to get input numbers
for(int i = 0; i < 5; i++){
	scanf("%d",&arr[i]);
}

quickSort(arr, 0, 4);

//print the sorted array
for(int j = 0; j < 5; j++){
	if(j==0){
		printf("[ %d,",arr[j]);
	}
	else if((j > 0) && (j < 4)){
		printf("%d,",arr[j]);
	}
	else if(j==4){
		printf("%d ] \n",arr[j]);
	}
}


}

void quickSort(int arr[], int p, int r){

	if( p < r){ // if there is more than one item in the array
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}

}

int partition(int arr[], int p, int r){

	int q = p;

	for(int j=p; j < r; j++){ 

		if(arr[j] <= arr[r]){ //if arr[j] <= the pivot, move it to the right end of the group of elements that are less than the pivot
			swap(arr, j, q);
			q++;
		}
	}

	swap(arr, r, q); //put the pivot into its correct position
	return q;
}

void swap(int arr[], int p, int r){
	int temp;

	temp = arr[p];
	arr[p] = arr[r];
	arr[r] = temp;

}