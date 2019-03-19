#include <stdio.h>

/* merge sort function prototype */
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);

int main(void){

	int i; //counter for array input loop
	int arr[] = {5, 2, 4, 1, 6, 3};

	//print the entered array
	printf("Before sorting \n");
	for(int j = 0; j < 6; j++){
		if(j==0){
			printf("[ %d,",arr[j]);
		}
		else if((j > 0) && (j <= 4)){
			printf("%d,",arr[j]);
		}
		else if(j==5){
			printf("%d ] \n",arr[j]);
		}
	}

	mergeSort(arr, 0, 5); //call merge sort (length -1 because index starts at 0, do not want to go out of bounds)

	//print the sorted array
	printf("Sorted:");
	for(int k = 0; k < 6; k++){
		if(k==0){
			printf("[ %d,",arr[k]);
		}
		else if((k > 0) && (k <= 4)){
			printf("%d,",arr[k]);
		}
		else if(k==5){
			printf("%d ] \n",arr[k]);
		}
	}
}

/* merge sort function */
void mergeSort(int arr[], int left, int right){

	int middle;

	/* Base case: make sure more than one value in array, if only one element it is already sorted */
	if(left == right){
		return;
	}

	else{
		/* Find the middle point of the array */
		middle = (left + right) / 2; //index of the midpoint of the array to divide it in half
		mergeSort(arr, left, middle); //sort the left half
		mergeSort(arr, middle + 1, right); //sort the right half
		merge(arr, left, middle, right); //merge the two halves 
	}
	
}

/* merge function */
void merge(int arr[], int left, int middle, int right){
	int leftStart = left; //starting index of left half of array
	int leftEnd = (left + right) / 2; //ending index of left half of the array
	int rightStart = leftEnd + 1; //starting index of right half of the array
	int arrLeftSize = (middle - left) + 1;
	int arrRightSize = right - middle;
	int arrLeft[arrLeftSize];
	int arrRight[arrRightSize];
	int i, j, k;

	/* Copy data to temporary left and right arrays */
	for(i=0; i < arrLeftSize; i++ ){
		arrLeft[i] = arr[left + i];
	}
	for(j=0; j < arrRightSize; j++){
		arrRight[j] = arr[j + middle + 1];
	}

	/*reset counters */
	i = 0;
	j = 0;
	k = left; //initial index of array merging left and right halves
	
	/* copy temporary arrays into initial array */
	while( (i < arrLeftSize) && (j < arrRightSize)){
		if(arrLeft[i] <= arrRight[j]){
			arr[k] = arrLeft[i];
			i++;
		}
		else{
			arr[k] = arrRight[j];
			j++;
		}
		k++;
	}

	/* copy any remaining elements of right and left sides */
	while( i < arrLeftSize){
		arr[k] = arrLeft[i];
		i++;
		k++;
	}

	while(j < arrRightSize){
		arr[k] = arrRight[j];
		j++;
		k++;
	}

}

