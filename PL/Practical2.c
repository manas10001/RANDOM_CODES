/*
 ============================================================================
Roll No: 23343	Batch: G11 Class: SEIT 11
Name: Manas Nitin Patil
Assignment number: 2
Problem Statement: Perform following operations on matrix using two dimensional
			       array
				   1.Addition
				   2.Multiplicaton
				   3.Tanspose
				   4.Saddle Point
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
# define MAXSZ 100

int main(void) {
	int mat1[MAXSZ][MAXSZ],mat2[MAXSZ][MAXSZ],ad[MAXSZ][MAXSZ],mul[MAXSZ][MAXSZ],tr[MAXSZ][MAXSZ];
	int ch,r1,r2,c1,c2,i,j,sd;
//PROTOTYPES
	void input(int r,int c,int mat1[MAXSZ][MAXSZ]);
	void disp(int mat[MAXSZ][MAXSZ],int r,int c);
	void Add(int mat1[MAXSZ][MAXSZ],int mat2[MAXSZ][MAXSZ],int r1,int c1,int ad[MAXSZ][MAXSZ]);
	void multiply(int mat1[MAXSZ][MAXSZ],int mat2[MAXSZ][MAXSZ],int mul[MAXSZ][MAXSZ],int r1,int c1,int c2);
	void trans(int mat1[MAXSZ][MAXSZ],int r,int c,int tr[MAXSZ][MAXSZ]);
	int sdpt(int mat1[MAXSZ][MAXSZ],int r,int c);
	printf("Choose the operation to be done on matrix: ");
do{
	printf("\n 1.Create Matrix\n 2.Addition\n 3.Multiplication\n 4.Transpose\n 5.Saddle Point\n 6.Display Matrix\n 7.Exit\n");
	scanf("%d",&ch);
	switch(ch){
	case 1: //Input for matrix
			printf("Enter number of rows and column of matrix 1 :");
			scanf("%d %d",&r1,&c1);//no of rows validations remaining
			input(r1,c1,mat1);
			printf("Enter number of rows and column of matrix 2 :");
			scanf("%d %d",&r2,&c2);
			input(r2,c2,mat2);
		break;
	case 2: //Adition for matrix
			if(r1!=r2 || c1!=c2){
				printf("Adition is invalid because the size of matrices dont match!\n ");
				break;
			}
			printf("Addition of A and B = \n");
			Add(mat1,mat2,r1,c1,ad);
			disp(ad,r1,c1);
		break;
	case 3: //Multiplication of matrix
			if(c1!=r2){
				printf("Multiplication not possible! ");
				break;
			}
			multiply(mat1,mat2,mul,r1,c1,c2);
			disp(mul,r1,c2);
		break;
	case 4: //Transpose of matrix
			printf("Transpose for matrix 1 :\n");
			trans(mat1,r1,c1,tr);
			disp(tr,c1,r1);
		break;
	case 5: //Saddle point of matrix
			sd=sdpt(mat1,r1,c1);
			if(sd!=999){
				printf("Saddle Point is = %d",sd);
			}else{
				printf("Saddle Point Not found!");
			}
		break;
	case 6: //Display matix
			printf("Matrix1: \n");
			disp(mat1,r1,c1);
			printf("Matrix2: \n");
			disp(mat2,r2,c2);
		break;
	case 7:printf("Exiting...");
		exit(0);
	default:
		printf("Wrong Input");
		exit(0);
	}
}while(1);
}
//FUNCTION FOR INPUT
void input(int r,int c,int mat1[MAXSZ][MAXSZ]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter element %d,%d: ",i,j);
			scanf("%d",&mat1[i][j]);
		}
	}
}
//FUNCTION FOR DISPLAY
void disp(int mat[MAXSZ][MAXSZ],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		printf("|  ");
			for(j=0;j<c;j++){
				printf("  %d  ",mat[i][j]);
			}
		printf("|  \n");
	}
}
//ADDITION OF TWO MATRIX
void Add(int mat1[MAXSZ][MAXSZ],int mat2[MAXSZ][MAXSZ],int r1,int c1,int ad[MAXSZ][MAXSZ]){
	int i,j;
	for(i=0;i<c1;i++){
		for(j=0;j<r1;j++){
			ad[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}
//MULTIPLICATION OF TWO MATRIX
void multiply(int mat1[MAXSZ][MAXSZ],int mat2[MAXSZ][MAXSZ],int mul[MAXSZ][MAXSZ],int r1,int c1,int c2){
	int i,j,k;
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<r1;k++){
				mul[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
}
//TRANSPOSE F MATRIX
void trans(int mat1[MAXSZ][MAXSZ],int r,int c,int tr[MAXSZ][MAXSZ]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			tr[j][i]=mat1[i][j];
		}
	}	
}
//SADDLE POINT
int sdpt(int mat1[MAXSZ][MAXSZ],int r,int c){
	int i,j,min,nmin,lc=0,lr=0;
	min=mat1[0][0];
	//FIRST FIND THE MINIMUM NUMBER IN ROW
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(mat1[i][j]<min){
				min=mat1[i][j];
				lc=j;
				lr=i;
			}
		}
		nmin=min;
	//CHECK IF THAT ELEMENT IS GREATEST IN THE COLUMN IF IT IS THE RETURN THE SADDLE
	//POINT ELSE CONTINUE
		do{
			lr++;
			if(nmin<mat1[lr][lc]){
				nmin=mat1[lr][lc];
			}
		}while(lr<r-1);
			return nmin;
	}
	return 999;
}
