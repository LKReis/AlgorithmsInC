#include <stdio.h>

/* bubble sort function declaration */
void bubbleSort(int arr[]);

int main(void){
int arr[5];

printf("Enter 5 numbers \n"); //prompt user for array

//loop to get input numbers
for(int i = 0; i < 5; i++){
	scanf("%d",&arr[i]);
}

//use bubble sort method to sort the array
bubbleSort(arr);

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

void bubbleSort(int arr[]){
	
	int i,j;//counters for the array
	int temp; //variable to store when swapping values

	//walk through the array comparing two elements at a time
	//if element on left is larger than element on the right, swap
	for(i=0; i < 4 ; i++){ //compare two values at a time, -1 on length to prevent out of bounds
		//step through the unsorted array to see if there is a smaller number
		for(j=0;j<4-i;j++){
			if(arr[j] > arr[j+1]){ //if element on left is larger than element on right 
				temp = arr[j];//store larger number
				arr[j] = arr[j+1]; //move smaller number to left
				arr[j+1] = temp; //move larger number to right
			}
		}		
	}
}
