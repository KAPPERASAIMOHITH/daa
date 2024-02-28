#include <stdio.h>
int fibonacci(int n){
	if(n<=1){
		return n;
	}else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
	
}

void printfibonacci(int limit){
	int i;
	for(i=0;i<=limit;i++){
		printf("%d, ",fibonacci(i));
	}
}

int main(){
	int limit;
	printf("enter the limit for fibonacci series");
	scanf("%d",&limit);
	printf("the fibonacci series upto %d is ",limit);
	printfibonacci(limit);
	return 0;
}
