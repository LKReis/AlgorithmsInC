#include <stdio.h>

/* insertion sort function declaration */
void insertionSort(int arr[]);

int main(void){
int arr[5];

printf("Enter 5 numbers \n"); //prompt user for array

//loop to get input numbers
for(int i = 0; i < 5; i++){
	scanf("%d",&arr[i]);
}

//use insertion sort method to sort the array
insertionSort(arr);

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

void insertionSort(int arr[]){
	
	int value; //variable for value of current element

	//iterate through array starting from second element because there is nothing to the left of the 0th element to compare it to
	for(int i=1; i < 5 ; i++){
		//get the value of the current element being considered
		value = arr[i];
		
		int j=i-1;

		//compare current element to elements before it
		while(j>=0){
			if(value < arr[j]){
				arr[j+1] = arr[j];//move element on left to the right
				arr[j] = value;//move element in current location to left
			}		
		j--;//decrement j to compare next item to left	
		}
	}
}
