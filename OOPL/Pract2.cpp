/*
Assignment 2
23343
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Book{
        public:
        static int stran,ftran,totbill;
        char title[20],author[30],publisher[20],s[20];
        int  price,stock,srno;
 
 	Book(){
 		stran = 0;
 		ftran = 0;
 		totbill = 0;
 	}
//ADD BOOK
        void addbk(){
        	cout<<"Enter Title of book: ";
        	cin>>title;
        	cout<<"Enter Author name: ";
        	cin>>author;
        	cout<<"Enter publisher name: ";
        	cin>>publisher;
        	cout<<"Enter cost per unit: ";
        	cin>>price;
        	cout<<"Enter no of books available: ";
        	cin>>stock;	
        }

//UPDATE BOOK DETAILS
        void upbk(){
        	int ch;
        	cout<<"Choose what do you want to update: \n1.Title\n2.Author\n3.Publuisher\n4.Cost\n5.Stock\n";
        	cin>>ch;
        	switch(ch){
        		case 1:	cout<<"Enter New Title: ";
				cin>>title;
        			break;
	        	case 2: cout<<"Enter New Author Name: ";
	        		cin>>author;
	        		break;
	        	case 3: cout<<"Enter New Publisher Name: ";
	        		cin>>publisher;
	        		break;
	        	case 4: cout<<"Enter New Cost: ";
	        		cin>>price;
	        		break;
	        	case 5: cout<<"Enter New Stock: ";
	        		cin>>stock;
	        		break;
	       		default: cout<<"INVALID INPUT!!";
        	}        	
        }

//DISPLAY BOOKS        
        void showbks(){
        	cout<<srno<<"\t"<<title<<"\t"<<author<<"\t"<<publisher<<"\t"<<price<<"\t"<<stock<<"\n";
        }
        
//PURCHASE BOOK
	int buybk(){
		int tot;
		cout<<"How man copies do you want to buy: ";
		cin>>tot;
		if(tot>stock){
			cout<<"That many copies of this book are not available sorry!!";
			ftran++;
			return 0;
		}else{
			cout<<"Transaction Success\nYou purchased "<<tot<<" copies of "<<title<<" Thank you";
			stran++;
			stock-=tot;
			totbill+=tot*price;
		}
	}
//PRINT BILL	
	void bill(){
		system("clear");
		cout<<"Total Successfull Transactions = "<<stran<<endl;
		cout<<"Total Failed Transactions = "<<ftran<<endl;
		cout<<"Total Billed Amount = "<<totbill<<endl;
	}
//SEARCH BY NAME
	int search(char s[],int no,Book b[]){
	int i;
	string sr;
		cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
		for(i=1;i<=no;i++){
			sr=b[i].title;
			if(sr.find(s)==0){
				b[i].showbks();
				
			}
		}
		return -1;
	}
	
};
int Book::stran;
int Book::ftran;
int Book::totbill;

int main(){
        int ch,no,n,r,p,t;
        char cnt,ser[20];
        cout<<"Welcome to book store"<<endl;
        cout<<"Enter maximum number of books in store: ";
        cin>>no;
        no=no+1;
        Book bk[no],B;
        do{
        system("clear");
        cout<<"Enter your choice:\n1.Add book\n2.Update book details\n3.Search book\n4.Purchase book\n5.Exit\n";
        cin>>ch;
        switch(ch){
                case 1: //Addbk
			cout<<"Enter Number of book: ";
			cin>>n;
			if(n>no || n<1)	
			{
				cout<<"Invalid Book number!!"; 
				break;
			}
			bk[n].srno=n;	
			bk[n].addbk();
			//bk[n].showbks();
                        break;
                case 2://update details
                	cout<<"Enter Number of book: ";
			cin>>n;
			if(n>no || n<1)
			{
				cout<<"Invalid Book number!!"; 
				break;
			}
			if(bk[n].srno!=n){
				cout<<"Insert book first then update!";
                		break;
                	}
			cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
			bk[n].showbks();
			bk[n].upbk();
			cout<<"\nUPDATED DETAILS: \n";
			cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
			bk[n].showbks();
                        break;
                case 3://search book
                	cout<<"Enter book name to search: ";
                	cin>>ser;
                	t=B.search(ser,no,bk);
                	if(t==-1){
                		cout<<"Book Not Found";
                	}
                        break;
                case 4://purchase book
                	cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
                	for(int j=1;j<=no;j++){
                		
                		if(bk[j].srno!=j){
                			continue;
                		}	
                		
                		bk[j].showbks();
                	}
                		cout<<"Enter Number of book to buy: ";
                		cin>>p;
                		if(p < 0 || p>no || bk[p].srno!=p){
                			cout<<"THERE IS NO SUCH BOOK! ";
                			break;
                		}
                		bk[p].buybk();
              			
                        break;
                case 5: //exit
                	cout<<"Thank you bye!";
                        break;
                default: cout<<"You did something wrong!!";                     
                        break;
        }
        cout<<"\nContinue (y / n): ";
        cin>>cnt;
        }while(cnt=='y'||cnt=='Y');
        bk[1].bill();
}
