/*
 ============================================================================
Roll No: 23343	Batch: G11 Class: SEIT 11
Name: Manas Nitin Patil
Assignment number: 1
Problem Statement: Represent sets using one dimensional array and perform the
				   followin operations.
 	 	 	 	 1. Union
 	 	 	 	 2. Intersection
 	 	 	 	 3. Difference
 	 	 	 	 4. Symmetric Difference
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//MAIN FUNCTION
int main(void)
{
	int sza,szb,no,i,j,ch,szc,szi,szadb,szbda,fsz;
	int A[100],B[100],C[100],In[100],Sydif[100],Di[100];
//PROTOTYPES DECLARATION
	void display(int A[100],int sza);
	void validate(int x[100],int sz);
	int dounion(int A[100],int sza,int B[100],int szb,int C[100]);
	int dointersection(int A[100],int sza,int B[100],int szb,int In[100]);
	int dodiff(int A[100],int sza,int B[100],int szb,int Di[100]);
	int dosydiff(int A[100],int sza,int B[100],int szb,int Sydif[100]);
//ACCEPTIG ARRAY A AND VALIDATING
	printf("Enter number of elements for set A: ");
	scanf("%d",&sza);
	while(sza>=100 || sza<0){
		printf("Sorry set size should be greater than 0 and less than 100\n Please enter again: ");
		scanf("%d",&sza);
	}
	printf("Elements should be between 1-100\n");
	for(i=0;i<sza;i++){
		printf("Enter element %d ",i+1);
		scanf("%d",&no);
		A[i]=no;
	}
	validate(A,sza);
//ACCEPTING ARRAY B AND VALIDATNG
	printf("Enter number of elements for set B: ");
	scanf("%d",&szb);
	while(szb>=100 || szb<0){
		printf("Sorry set size should be greater than 0 and less than 100\n Please enter again: ");
		scanf("%d",&szb);
	}
	printf("Elements should be between 1-100\n");
	for(j=0;j<szb;j++){
		printf("Enter element %d ",j+1);
		scanf("%d",&no);
		B[j]=no;
	}
	validate(B,szb);

do{
	printf("\nEnter Your Choice:\n1.Display sets\n2.Union\n3.Intersection\n4.Difference\n5.Symmetric Difference\n6.Exit\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:printf("Displaying Sets\nA={");
			display(A,sza);
			printf("\nB={");
			display(B,szb);
		break;
	case 2: printf("A U B= {");
			szc=dounion(A,sza,B,szb,C);
			display(C,szc);
		break;
	case 3: printf("A Intersection B= {");
			szi=dointersection(A,sza,B,szb,In);
			display(In,szi);
		break;
	case 4:		printf("A-B :{");
			szadb=dodiff(A,sza,B,szb,Di);
			display(Di,szadb);
			printf("\nB-A :{");
			szbda=dodiff(B,szb,A,sza,Di);
			display(Di,szbda);
		break;
	case 5:
			fsz=dosydiff(A,sza,B,szb,Sydif);
			display(Sydif,fsz);
		break;
	case 6: exit(0);
			break;
	default: printf("Wrong input");
			exit(0);
	}
}while(1);
	return EXIT_SUCCESS;
}


void display(int A[100],int sza){
	int j;
	for(j=0;j<sza;j++){
		printf(" %d ",A[j]);
	}
	printf("}\n");
}

void validate(int x[100],int sz){
	int i,j,count=0;
//UNIVERSAL SET VALIDATION
	for(i=0;i<sz;i++){
		while(x[i]<=0 || x[i]>99){
			printf("Element at index %d is out of the universal set please enter another: ",i);
			scanf("%d",&x[i]);
		}
	}
//UNIQUE ELEMENT VALIDATION
	for(i=0;i<sz;i++){
		for(j=0;j<sz;j++){
			if(j==i)
				continue;
			if(x[i]==x[j]){
				count++;
			}
			if(count>=1){
				printf("Element at index %d has to be unique please enter another :",i);
				scanf("%d",&x[i]);
				count=0;
			}
		}
	}
}

int dounion(int A[100],int sza,int B[100],int szb,int C[100]){
	int m,n,o,tmp=0,szc=0;
//First store array a in the union array
	for(m=0;m<sza;m++){
		C[m]=A[m];
		szc++;
	}
//Now add elements of array b to it which are not already present
	for(n=0;n<szb;n++){
		tmp=0;
		for(o=0;o<sza;o++){
			if(B[n]==A[o]){
				tmp++;
			}
		}
		if(tmp==0){
			C[szc]=B[n];
			szc++;
		}
	}
return szc;
}
//FUNCTION TO FING INTERSECTION
int dointersection(int A[100],int sza,int B[100],int szb,int In[100]){
	int p,q,szi=0;
	for(p=0;p<sza;p++){
 		for(q=0;q<szb;q++){
 			if(A[p]==B[q]){
 				In[szi]=A[p];
 				szi++;
 			}
 		}

 	}
	return szi;
}
//FUNCTION TO FIND DIFFERENCE
int dodiff(int A[100],int sza,int B[100],int szb,int Di[100]){
	int p,q,c=0,i=0;
		for(p=0;p<sza;p++)
		{
	 		c=0;
	 		for(q=0;q<szb;q++)
	 		{
	 			if(A[p]==B[q])
	 			{
	 				c++;
	 			}	 			
	 		}
	 		if(c==0)
	 		{
	 			Di[i]=A[p];
	 				i++;
	 		}
	 	}
		return i;
}
//SYMMETRIC DIFFERENCE (A-B)U(B-A)
int dosydiff(int A[100],int sza,int B[100],int szb,int Sydif[100]){
	int sad,sbd,fsz;
	int arad[100],arbd[100];
	sad=dodiff(A,sza,B,szb,arad);

	sbd=dodiff(B,szb,A,sza,arbd);
	
	printf("Symmetric difference: {");
	fsz=dounion(arad,sad,arbd,sbd,Sydif);
	return fsz;
}
