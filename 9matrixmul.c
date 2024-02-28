#include<stdio.h>
#include<time.h>
void multiplymatrices(int matrix1[][100],int matrix2[][100],int result[][100],int rows1,int cols1,int cols2){
	int i,j,k;
	for(i=0;i<rows1;i++){
		for(j=0;j<cols2;j++){
			result[i][j]=0;
			for(k=0;k<cols1;k++){
				result[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
}
int main(){
	int rows1,cols1,rows2,cols2;
	printf("enter the number of rows and coloumns for matrix 1:");
	scanf("%d%d",&rows1,&cols1);
	printf("enter the number of rows and coloumns for matrix 2:");
	scanf("%d%d",&rows2,&cols2);
	
	if(cols1!=rows2){
		printf("matrix multiplication not possible");
		return 0;
	}
	
	int matrix1[100][100],matrix2[100][100],result[100][100];
	printf("enter the elements of matrix 1");
	for(int i=0;i<rows1;i++){
		for(int j=0;j<cols1;j++){
			scanf("%d",&matrix1[i][j]);
		}
	}
	printf("enter the elements of matrix 2");
	for(int i=0;i<rows2;i++){
		for(int j=0;j<cols2;j++){
			scanf("%d",&matrix2[i][j]);
		}
	}
	
	multiplymatrices(matrix1,matrix2,result,rows1,cols1,cols2);
	printf("resultant matrix \n");
	for(int i=0;i<rows1;i++){
		for(int j=0;j<cols2;j++){
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	return 0;
	
	
}
