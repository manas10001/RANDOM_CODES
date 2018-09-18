/*
 ============================================================================
 Name        : Practical4.c
 Author      : Manas
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : STUDENT DATABASE
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MX 100
struct date{
	int dd,yy,mm;
};

struct stud{
	int serno,rollno;
	float per;
	long mno;
	char name[30];
	struct date dob;
};

int main(void) {

struct stud s[MX];
int ch;
int norc=0,nrc,tmp,rt,i,fct;
//PROTOTYPES
	int createdb(struct stud s[],int norc);

//CALL TO CREATE DATABASE
	norc+=createdb(s,norc);
	fct=norc;//SECOND COUNTER TO ENSURE UNIQUENESS OF SERIAL NO
//MENU
	do{
	printf("\nEnter your choice:\n1.Insert record\n2.Modify record\n3.Delete record\n4.Search record\n5.Display records\n6.EXIT: ");
	scanf("%d",&ch);
		switch(ch){
		case 1://ins
			printf("Enter location to enter record, current no of records : %d :",norc);
			scanf("%d",&nrc);
			if(nrc>0 && nrc<=norc+1){
				if(nrc==norc+1){
					insert(s,nrc-1,fct);
					norc++;
					fct++;
				break;
				}
				if(nrc<=norc){
					tmp=norc-1;
					while(tmp>=nrc-1){
						s[tmp+1]=s[tmp];
						tmp--;
					}
					insert(s,nrc-1,fct);
					norc++;
					fct++;
				break;
				}
			}else{
				printf("Invalid location lease enter location between 0 & %d !",norc+1);
			}
			break;
		case 2://modify
				printf("Enter rollno to modify record:");
				scanf("%d",&tmp);
				rt=search(s,norc,tmp);
				if(rt==999){
					printf("Record not found! ");
				}else{
					printf("Original: \n");
					printf("SRNO\tROLLNO\tNAME\tPERCENTAGE\tMOBILE NO\tD.O.B.\n");
					disp(s,rt);
					modify(s,rt);
					printf("Modified: \n");
					printf("SRNO\tROLLNO\tNAME\tPERCENTAGE\tMOBILE NO\tD.O.B.\n");
					disp(s,rt);
				}
			break;
		case 3://del
				printf("Enter rollno to delete record: ");
				scanf("%d",&nrc);
				rt=search(s,norc,nrc);
				if(rt==999){
					printf("Record not present! ");
				}else{
					delrc(s,rt,norc);
					norc--;
					printf("Record deleted! ");
				}
			break;
		case 4://search
				printf("Enter rollno to search record: ");
				scanf("%d",&tmp);
				rt=search(s,norc,tmp);
				if(rt==999){
					printf("Record not found! ");
				}else{
					printf("SRNO\tROLLNO\tNAME\tPERCENTAGE\tMOBILE NO\tD.O.B.\n");
					disp(s,rt);
				}
			break;
		case 5://disp
				printf("****************************************************************\n");
				printf("SRNO\tROLLNO\tNAME\tPERCENTAGE\tMOBILE NO\tD.O.B.\n");
				for(i=0;i<norc;i++)
					disp(s,i);
			break;
		case 6://ex
			exit(0);
			break;
		default:
			printf("WRONG INPUT: ");
		}
	}while(1);
}
//CREATE DATABASE FUNCTION WILL RETURN NO OF RECORDS INSERTED AT START PARAMETERS ARE STRUCTURE OBJ AND TOTAL NO OF RECORDS PRESENT
int createdb(struct stud s[],int norc){
	int no,i;
	printf("How many number of records you want to insert: ");
	scanf("%d",&no);
	for(i=0;i<no;i++){
		printf("Enter data of student %d \n",i+1);
			insert(s,i,i);
	}
	return no;
}
//PARAMETERS ARE OBJ OF STRUCT AND THE NO ON WHICH RECORD IS TO BE INSERTED
void insert(struct stud s[],int sr,int nr){
	int tmp=2000;
	s[sr].serno = tmp+nr;
	printf("Enter student rollno: ");
	scanf("%d",&s[sr].rollno);
	printf("Enter student name: ");
	scanf("\n");
	gets(s[sr].name);
	printf("Enter student mobile no: ");
	scanf("%ld",&s[sr].mno);
	while(s[sr].mno < 9000000000 || s[sr].mno > 9999999999){
		printf("Mobile number not valid enter again: ");
		scanf("%ld",&s[sr].mno);
	}
	printf("Enter students percentages: ");
	scanf("%f",&s[sr].per);
	printf("Enter student date of birth :(DD MM YY) ");
	scanf("%d",&s[sr].dob.dd);
	scanf("%d",&s[sr].dob.mm);
	scanf("%d",&s[sr].dob.yy);
}
//PARAMETERS ARE STRUCT OBJ AND NO OF RECORD TO BE DISPLAYED
void disp(struct stud s[],int i){
		printf("%d \t %d \t", s[i].serno, s[i].rollno);
		printf("%s \t %f \t", s[i].name, s[i].per);
		printf("%ld \t", s[i].mno);
		printf("%d %d %d \n", s[i].dob.dd, s[i].dob.mm, s[i].dob.yy);
}
//PARAMETERS ARE STRUCT OBJ MAX NO OF RECORDS AVAILABLE+1 AND ROLLNO TO SEARCH
//RETURNS THE LOCATION OF STRUCTURE WHERE THE RECORD IS PRESENT
int search(struct stud s[],int norc,int tmp){
	int i;
	for(i=0;i<norc;i++)
	{
		if(s[i].rollno==tmp)
		{
			return i;
		}
	}
	return 999;
}
//MODIFY RECORD CONTENTS
void modify(struct stud s[],int tmp){
	int i;
	printf("What do you want to modify?\n1.Name\n2.Percentages\n3.Mobile No\n4.Date of birth");
	scanf("%d",&i);
	switch(i){
	case 1:	printf("Enetr new name: ");
		scanf("\n");
		gets(s[tmp].name);
	break;
	case 2: printf("Enter students percentages: ");
		scanf("%f",&s[tmp].per);
	break;
	case 3: printf("Enter student mobile no: ");
		scanf("%ld",&s[tmp].mno);
			while(s[tmp].mno < 9000000000 || s[tmp].mno > 9999999999){
			printf("Mobile number not valid enter again: ");
			scanf("%ld",&s[tmp].mno);
		}
	break;
	case 4:	printf("Enter student date of birth :(DD MM YY) ");
		scanf("%d",&s[tmp].dob.dd);
		scanf("%d",&s[tmp].dob.mm);
		scanf("%d",&s[tmp].dob.yy);
	break;
	}
}
//DELETE RECORDS
void delrc(struct stud s[],int tp,int norc){
	while(tp<=norc-1){
		s[tp]=s[tp+1];
		tp++;
	}
}
