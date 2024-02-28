#include<stdio.h>
int binarysearch(int arr[],int left,int right,int target){
	while(left<=right){
		int mid=left+(right-left)/2;
		if(arr[mid]==target){
			return mid;
		}
		else if(arr[mid]<target){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return -1;
}

int main(){
	int target,n;
	printf("enter the size of an array");
	scanf("%d",&n);
	int arr[n];
	
	printf("enter the elements of an array of size %d ",n);
	for(int i=0;i<=n-1;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the target element");
	scanf("%d",&target);
	int res=binarysearch(arr,0,n-1,target);
	
	if(res!=-1){
		printf("the element found at %d\n",res);
	}
	else{
		printf("element not found \n ");
	}
}
