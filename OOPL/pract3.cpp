/*
Assignment 3		COMPLEX NUMBERS OPERATIONS WITH RIEND FUNCTION
23343
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Complex{
	private: 
	int r,i;
	public:
	void get(){
		cout<<"\nEnter real part ";
		cin>>r;
		cout<<"Enter imaginary part ";
		cin>>i;
		cout<<"Number:\t";
		disp();
	}
	void disp(){
		cout<<r<<"+"<<i<<"i\n";
	}
	friend Complex operator	+(Complex c1,Complex C2);
	friend Complex operator	-(Complex c1,Complex C2);

	Complex operator *(Complex c2){
		Complex c3,t1,t2;
		t1.r=r*c2.r;
		t1.i=r*c2.i;
		t2.r=i*c2.r;
		t2.i=i*c2.i;
		c3.r=t1.r+t2.i;
		c3.i=t1.i+t2.r;
		return c3;
	}
	Complex operator /(Complex c2){
	Complex c3;
	c3.r=r/c2.r;
	c3.i=i/c2.i;
	return c3;
}
};

Complex operator +(Complex c1,Complex c2){
	Complex c3;
	c3.r=c1.r+c2.r;
	c3.i=c1.i+c2.i;
	return c3;
}

Complex operator -(Complex c1,Complex c2){
	Complex c3;
	c3.r=c1.r-c2.r;
	c3.i=c1.i-c2.i;
	return c3;
}

int main(){
	int no;
	char cnt;
	Complex c1,c2,c3;
		
	cout<<"Enter 1st number ";
	c1.get();
	cout<<"Enter 2nd number ";
	c2.get();
do{	
	cout<<"Select your choice:\n1.Add\n2.Substract\n3.Multiply\n4.Divide\n5.Exit\n";
	cin>>no;
		
	switch(no){
		case 1: cout<<"ADDITION: ";
			c3=c1+c2;
			c3.disp();
			break;
		case 2: cout<<"SUBSTRACTION: ";
			c3=c1-c2;
			c3.disp();
			break;
		case 3: cout<<"MULTIPLICATION: ";
			c3=c1*c2;
			c3.disp();
			break;
		case 4: cout<<"DIVISION: ";
			c3=c1/c2;
			c3.disp();
			break;
		case 5: exit(0);
			break;
		
	}
	cout<<"\nContinue (y / n): ";
        cin>>cnt;
}while(cnt=='y'||cnt=='Y');
}
