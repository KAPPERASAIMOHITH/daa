#include <stdio.h>


void bubblesort(int arr[],int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<=size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(){
	int size,i;
	printf("enter the size of array");
	scanf("%d",&size);
	
	int arr[size];
	printf("enter the %d elements",size);
	for(i=0;i<=size-1;i++){
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,size);
	printf("sorted array is");
	for(i=0;i<=size-1;i++){
		printf("%d ",arr[i]);
	}
	return 0;
	
}
