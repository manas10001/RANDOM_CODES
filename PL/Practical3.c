/*
 ============================================================================
Roll No: 23343	Batch: G11 Class: SEIT 11
Name: Manas Nitin Patil
Assignment number: 3
Problem Statement: Perform following operations on string
					1.Lenth
					2.Palindrome
					3.Comparision
					4.Copy
					5.Reverse
					6.Substring
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#define MX 50

int main(void)
{
	int ch,l,cm,pal,su;
	char rv[MX],str1[MX],str2[MX],sc[MX];
//PROTOTYPES
	int len(char s[MX]);
	int cmp(char s1[MX],char s2[MX]);
	void rev(char s[MX],int l);
	void copy(char s1[MX],char s2[MX]);
	int palindrome(char s1[MX]);
	int substr(char s1[MX],char s2[MX]);

	printf("Enter string: ");
	gets(str1);
	do
	{
	printf("\n\nChoose Your operation:\n 1.Lenth of string.\n 2.Compare two strings.\n 3.Reverse String.\n 4.Palindrom.\n 5.Copy.\n 6.Check for sybstring.\n 7.Exit. ");
	scanf("%d",&ch);
		switch(ch)
		{
		case 1:
				l=len(str1);
				printf("Length of strig 1 is : %d",l);
				break;
		case 2:
				printf("Enter Second string: ");
				scanf("\n");
				gets(str2);
				cm=cmp(str1,str2);
				if(cm==0)
					printf("Strings are alphabetically equal!");
				else if(cm<0)
					printf("String 1 is alpabetically greater than string 2");
				else
					printf("String 2 is alpabetically greater than string 1");
				break;
		case 3:
				l=len(str1);
				rev(str1,l);
				puts(str1);
				break;
		case 4:
				printf("Enter string to find palindrome ");
				scanf("\n");
				gets(sc);
				pal=palindrome(sc);
				if(pal==0)
					printf("String is palindrome!" );
				else
					printf("String is not palindrome! ");
				break;
		case 5:
				printf("Enter string to be copied : ");
				scanf("\n");
				gets(sc);
				copy(str1,sc);
				printf("Copied string is : %s",str1);
				break;
		case 6:
				printf("Enter string to check for sub-string : ");
				scanf("%s",&sc);
				su=substr(str1,sc);
				if(su==0)
					printf("No sub-string found ");
				else
					printf("Sub-string found %d times",su);
				break;
		case 7:
				exit(0);
				break;
		}
	}while(1);

}

int len(char s[MX])
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}

int cmp(char s1[MX],char s2[MX])
{
	int i,ret=0,l1,l2;
	l1=len(s1);
	l2=len(s2);
	if(l2>l1)
		l1=l2;
	for(i=0;i<l1;i++)
	{
		if(ret!=0)
			return ret;
		ret=s1[i]-s2[i];
	}
	return ret;
}

void rev(char s[MX],int l)
{
	int i,j=0;
	char temp;
	i=0;
	j=l-1;
	while(i<(l/2))
	{
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
				i++;
				j--;

	}

}

void copy(char s1[MX],char s2[MX])
{
	int i;
	for(i=0;s2[i]!='\0';i++)
		s1[i]=s2[i];
	s1[i]=NULL;
}
int palindrome(char s1[MX])
{
	char s[MX];
	copy(s,s1);
	int ln,cm;
	ln=len(s1);
	rev(s,ln);
	cm=cmp(s1,s);
	if(cm==0)
		return 0;
	else
		return 1;
}
int substr(char s1[MX],char s2[MX])
{
	int i,j,k=0,it,ln,ct=0;
	ln=len(s2);
	for(i=0;s1[i]!='\0';i++)
	{
		it=i;
		for(j=0;j<ln;j++)
		{
			k=s1[it]-s2[j];
			it++;
			if(k!=0)
				break;
		}
		if(k==0)
			ct++;
	}
	return ct;
}
