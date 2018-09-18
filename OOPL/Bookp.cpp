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
        char *title,*author,*publisher,*s;
        int  *price,*stock,*srno;
 
 	Book(){
 		stran = 0;
 		ftran = 0;
 		totbill = 0;
 		title = new char[20];
 		author = new char[20];
 		publisher = new char[20];
 		s = new char[20];
 		price = new int;
 		stock = new int;
 		srno  = new int;
 	}
 	~Book(){				//still misbehaves
 		cout<<"\tdistroying....";
 		delete(title);
 		delete(author);
 		delete(publisher);
 		delete(s);
 		delete(price);
 		delete(stock);
 		delete(srno);
 	}
//ADD BOOK
        void addbk(){
        	cin.ignore();
        	cout<<"Enter Title of book: ";
        	cin.getline(title,20);
        	cout<<"Enter Author name: ";
        	cin.getline(author,20);
        	cout<<"Enter publisher name: ";
        	cin.getline(publisher,20);
        	cout<<"Enter cost per unit: ";
        	cin>>*price;
        	cout<<"Enter no of books available: ";
        	cin>>*stock;	
        }

//UPDATE BOOK DETAILS
        void upbk(){
        	int ch;
        	cout<<"Choose what do you want to update: \n1.Title\n2.Author\n3.Publuisher\n4.Cost\n5.Stock\n";
        	cin>>ch;
        	switch(ch){
        		case 1:	cout<<"Enter New Title: ";
        			cin.ignore();
				cin.getline(title,20);
        			break;
	        	case 2: cout<<"Enter New Author Name: ";
	        		cin.ignore();
	        		cin.getline(author,20);
	        		break;
	        	case 3: cout<<"Enter New Publisher Name: ";
	        		cin.ignore();
	        		cin.getline(publisher,20);
	        		break;
	        	case 4: cout<<"Enter New Cost: ";
	        		cin>>*price;
	        		break;
	        	case 5: cout<<"Enter New Stock: ";
	        		cin>>*stock;
	        		break;
	       		default: cout<<"INVALID INPUT!!";
        	}        	
        }

//DISPLAY BOOKS        
        void showbks(){
        	cout<<*srno<<"\t"<<title<<"\t"<<author<<"\t"<<publisher<<"\t"<<*price<<"\t"<<*stock<<"\n";
        }
        
//PURCHASE BOOK
	int buybk(Book b){
		int tot;
		cout<<"How many copies do you want to buy: ";
		cin>>tot;
		if(tot>*stock){
			cout<<"That many copies of this book are not available sorry!!";
			ftran++;
			return 0;
		}else{
			cout<<"Transaction Success\nYou purchased "<<tot<<" copies of "<<title<<" Thank you";
			stran++;
			*stock-=tot;
			totbill+=tot*(*b.price);
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
	int i,ct=0;
		cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
		for(i=0;i<no;i++){
			if(strcmp(b[i].title,s)==0){
				b[i].showbks();
				ct++;
			}
		}
		if(ct!=0)
			return 0;
		return -1;
	}
	
};
int Book::stran;
int Book::ftran;
int Book::totbill;

int main(){
        int ch,no,n,r,p,t,j,ctr=0;
        static int fct=0;
        char cnt;
        char ser[20],temp[20];
        cout<<"Welcome to book store"<<endl;
        cout<<"Enter maximum number of books in store: ";
        cin>>no;
        no=no+1;
        Book *bk,B;
        bk=new Book[no];
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
			*bk[fct].srno=n;	
			bk[fct].addbk();
			fct++;
			//bk[n].showbks();
                        break;
                case 2://update details
                	cout<<"Enter Name of book to update: ";
			cin.ignore();
			cin.getline(temp,20);
			ctr=0;
			for(int i=0;i<=fct;i++){
				if(strcmp(bk[i].title,temp)==0){
					cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
					bk[i].showbks();
					bk[i].upbk();
					cout<<"\nUPDATED DETAILS: \n";
					cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
					bk[i].showbks();	
					ctr++;		//if book is found counter is increased hence error message is avoided
					break;
				}
			}if(ctr==0)
				cout<<"Invalid Book Name!!";
                        break;
                case 3://search book
                	cout<<"Enter book name to search: ";
                	cin.ignore();
                	cin.getline(ser,20);
                	t=B.search(ser,fct,bk);
                	if(t==-1){
                		cout<<"Book Not Found";
                	}
                        break;
                case 4://purchase book
                	cout<<"NO\tTITLE\tAUTHOR\tPUBLISHER COST\tSTOCK\t\n";
                	for(j=0;j<=fct;j++){	
                		if(*bk[j].srno!=0)
                		bk[j].showbks();
                	}
                		cout<<"Enter Name of book to buy: ";
                		cin.ignore();
                		cin.getline(temp,20);
                		ctr=0;			//counter for validation
                		for(int i=0;i<=fct;i++){
					if(strcmp(bk[i].title,temp)==0){
						ctr++;			//if book is found counter is increased hence error message is avoided
						bk[i].buybk(bk[i]);	
					}
				}if(ctr==0)
					cout<<"Invalid Book Name!!";
              			
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
        B.bill();
}
