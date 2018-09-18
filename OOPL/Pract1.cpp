/*
Assignment 1;
23343
*/
#include<iostream>
using namespace std;
class Weather_report{
        

        static int avghtmp,avgltmp,avgrain,avgsnow,count;
               int day,hightmp,lowtmp,amtrain,amtsnow;
               
               public:
                Weather_report(){
                        day = 99;
                        hightmp = 999;
                        lowtmp = -999;
                        amtrain = 99;
                        amtsnow = 999;                
                }
                void read_data(int no){
                        cout<<"Enter data for day: "<<no;
                        day=no;
                        cout<<"\nEnter high temperature: ";
                        cin>>hightmp;
                        cout<<"Enter low temperature: ";
                        cin>>lowtmp;
                        cout<<"Enter amount of rain: ";
                        cin>>amtrain;
                        cout<<"Enter amount of snow: ";
                        cin>>amtsnow;
                }
                
                static void init();
                
                void calavg(){
                        if(day!=99){
                        avghtmp+=hightmp;
                        avgltmp+=lowtmp;
                        avgrain+=amtrain;
                        avgsnow+=amtsnow;
                        count++;
                        }
                                    
                }
                
                static void showavg(){
                if(count==0){
                        cout<<"Enter data first to get monthly report!!";
                        return;
                }
                cout<<"Average high temperature= "<<avghtmp/count;
                cout<<"\nAverage low temperature= "<<avgltmp/count;
                cout<<"\nAverage rainfall= "<<avgrain/count;
                cout<<"\nAverage showfall= "<<avgsnow/count;
                }
                
                void show_data(){
                //display all data
                        cout<<endl<<day<<"\t"<<hightmp<<"\t"<<lowtmp<<"\t"<<amtrain<<"\t"<<amtsnow;
                }

};
int Weather_report::count;
int Weather_report::avghtmp;
int Weather_report::avgltmp;
int Weather_report::avgrain;
int Weather_report::avgsnow;
void Weather_report::init(){
                        avghtmp=0;
                        avgltmp=0;
                        avgrain=0;
                        avgsnow=0;
                        count=0;
                }

int main(){
        Weather_report wr[30];
        int ch,no,a;
        char ct;
        do{
        cout<<"Choose an option \n1.Enter data of a day.\n2.Display data of a day\n3.Display all month data\n4.Display monthly average report\n";
        cin>>ch;
        switch(ch){
                case 1: cout<<"Enter number of day to enter data ";
                        cin>>no;
                        if(no>30||no<1){
                                cout<<"Please enter day between 1 and 30";
                        break;
                        }
                        wr[no].read_data(no);
                        break;
                case 2: cout<<"Enter number of day to display data ";
                        cin>>no;
                        if(no>30||no<1){
                                cout<<"Please enter day between 1 and 30";
                                break;
                        }
                                wr[no].show_data();
                        break;
                case 3: cout<<"All month data\n";
                        cout<<"Day\tHtemp\tLtemp\tRain\tSnow";
                        for(int i=0;i<30;i++){
                                        wr[i].show_data();
                        }
                        break;
                case 4: cout<<"Monthly report\n";
                        Weather_report::init();
                        for(int i=0;i<30;i++){
                                       wr[i].calavg();
                        }
                        Weather_report::showavg();
                        break;
                default: cout<<"You did something wrong";
        }
        cout<<"\nEnter y if you want to contnue: ";
        cin>>ct;
        }while(ct=='y' || ct=='Y');
}
