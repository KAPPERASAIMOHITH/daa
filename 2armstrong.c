#include <stdio.h>
#include <math.h>
int isarmstrong(int num,int originalnum,int digitcount){
	if(originalnum==0){
		return 0;
	}
	else{
		return pow(originalnum%10,digitcount)+isarmstrong(num,originalnum/10,digitcount);
	}
}

int main(){
	int num,originalnum,digitcount=0,sumofdigits=0;
	printf("enter the number");
	scanf("%d",&num);
	originalnum=num;
	
	while(originalnum!=0){
		originalnum/=10;
		digitcount++;
	}
	originalnum=num;
	sumofdigits=isarmstrong(num,originalnum,digitcount);
	if(sumofdigits==num){
		printf("%d is armstrong number",num);
	}
	else{
		printf("%d is not armstrong number",num);
	}
	return 0;
}
