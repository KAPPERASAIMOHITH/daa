#include<stdio.h>
int isprime(int num,int divisor){
	if(divisor<=1){
		return 1;
	}if(num%divisor==0){
		return 0;
	}
	return isprime(num,divisor-1);
	
}

void generateprimes(int currentnum,int limit){
	if(currentnum>limit){
		return;
	}
	if(isprime(currentnum,currentnum/2)==1){
		printf("%d ",currentnum);
	}
	generateprimes(currentnum+1,limit);
}
int main(){
	int limit;
	printf("enter the limit to generate prime numbers:");
	scanf("%d",&limit);
	printf("prime numbers upto %d are :\n",limit);
	generateprimes(2,limit);
	
	return 0;
}
