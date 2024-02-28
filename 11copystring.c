#include<stdio.h>
void copystring(char source[],char destination[],int index){
	if(source[index]=='\0'){
		destination[index]='\0';
		return;
	}
	destination[index]=source[index];
	copystring(source,destination,index+1);
}

int main(){
	char source[50],destination[50];
	printf("enter the string for source : ");
	scanf("%s",&source);
	copystring(source,destination,0);
	printf("source string is %s\n",source);
	printf("destination string is %s\n",destination);
	
	return 0;
}
