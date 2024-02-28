#include<stdio.h>
int linearsearch(int arr[],int n,int key){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}
int main(){
	int n,key;
	printf("enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of an array");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the element to search in array:");
	scanf("%d",&key);
	int index=linearsearch(arr,n,key);
	if(index!=-1){
		printf("element found at %d",index);
	}
	else{
		printf("element not found\n");
	}
	return 0;
}
