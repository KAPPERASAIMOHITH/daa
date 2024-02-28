#include<stdio.h>
int isprime(int num,int div){
	if(num<=2){
		return (num==2);
	}
	else if(div==1){
		return 1;
	}
	else if(num%div==0){
		return 0;
	}
	else{
		return isprime(num,div-1);
	}
}
int main(){
	int num,div;
	printf("enter the number ");
	scanf("%d",&num);
	div=num/2;
	if(isprime(num,div)){
		printf("%d is prime",num);
	}
	else{
		printf("%d is not prime",num);
	}
	return 0;
}
