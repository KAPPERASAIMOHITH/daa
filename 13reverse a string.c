#include<stdio.h>
#include<string.h>
void reversestring(char str[],int start,int end){
	if(start>=end){
		return;
	}
	
	char temp=str[start];
	str[start]=str[end];
	str[end]=temp;
	reversestring(str,start+1,end-1);
}

int main(){
	char str[100];
	printf("enter the string: ");
	scanf("%s",str);
	int len=strlen(str);
	
	printf("original string %s\n",str);
	reversestring(str,0,len-1);
	printf("reversed string:%s",str);
	
	return 0;
}
