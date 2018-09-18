/*
Inheritance using Virtual function

*/
#include<iostream>
using namespace std;

class shape{
	protected :		
		double l,w;
	public:
		void input(){
			cout<<"Enter length: ";
			cin>>l;
			cout<<"Enter Width: ";
			cin>>w;
		}
		virtual void compute_area()=0;
};

class tri : public shape{
	public:
		void compute_area(){
			cout<<"AREA of triangle = "<<(l*w)/2<<endl;
		}
};

class rect : public shape{
	public: 
		
		void compute_area(){
			cout<<"AREA of rectangle = "<<l*w<<endl;
		}
};

int main(){
	tri t;
	rect r;
	shape *s;
	int n;
	while(1){
		cout<<"Enter your choice \n1.Triangle\n2.Rectangle\n3.Exit ";
		cin>>n;
		switch(n){
			case 1:
				s=&t;
				cout<<"Enter Inputs for Triangle: \n";
				s->input();
				s->compute_area();
				break;
			case 2:
				s=&r;
				cout<<"Enter Inputs for Rectangle: \n";
				s->input();
				s->compute_area();
				break;
			case 3:
				return 0;
				break;		
		}
	}
}
