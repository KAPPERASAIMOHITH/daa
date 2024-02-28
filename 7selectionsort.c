#include <stdio.h>
void selectionsort(int arr[],int size){
	int i,j,minindex;
	for(i=0;i<size-1;i++){
		minindex=i;
		for(j=i+1;j<size;j++){
			if(arr[j]<arr[minindex]){
			minindex=j;
		}
		}
		int temp=arr[i];
		arr[i]=arr[minindex];
		arr[minindex]=temp;
	}
	
}
int main(){
	int size,i;
	printf("enter the size of an array");
	scanf("%d",&size);
	int arr[size];
	printf("enter %d elements of the array",size);
	for(i=0;i<=size-1;i++){
		scanf("%d",&arr[i]);
	}
	selectionsort(arr,size);
	printf("the sequential arrangement of array is");
	for(i=0;i<=size-1;i++){
		printf("%d",arr[i]);
	}
}
