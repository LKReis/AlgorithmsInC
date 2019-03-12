#include <stdio.h>

/* selection sort function declaration */
void selectionSort(int arr[]);

int main(void){
int arr[5];

printf("Enter 5 numbers \n"); //prompt user for array

//loop to get input numbers
for(int i = 0; i < 5; i++){
	scanf("%d",&arr[i]);
}

//use selection sort method to sort the array
selectionSort(arr);

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

void selectionSort(int arr[]){
	
	int i,j;//counters for the array
	int min = 0; //variable for minimum value in the array
	int minIndex = 0; //variable for index of minimum value in the array
	
	//walk through the array, find the minimum value, if it is smaller than the first unsorted element in the array swap
	for(i=0; i < 5 ; i++){
		//set the minimum value to the current element
		min = arr[i];
		minIndex = i; //set index of minimum value to current position

		//step through the unsorted array to see if there is a smaller number
		for(j=i;j<5;j++){
			if(arr[j] < min){ //if current element in unsorted array is smaller first element 
				min = arr[j]; //set minimum to current element
				minIndex = j; //set minimum index to current element index
			}
		}		
		
		//swap the minimum with the first unsorted element
		if(min < arr[i]){
			int temp = arr[i]; //store value of first unsorted element
			arr[i] = arr[minIndex]; //set first unsorted element to minimum
			arr[minIndex] = temp; //place first unsorted element in slot of minimum

		}
	}
}
