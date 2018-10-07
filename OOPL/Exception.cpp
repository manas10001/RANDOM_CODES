/*
Exception handling

*/
#include<iostream>
using namespace std;

class ex{
        protected:
                double n1,n2,ans;
        public:
                void read(){
                        cout<<"Enter first number: ";
                        cin>>n1;
                        cout<<"Enter second number: ";
                        cin>>n2;
                }

                void divide(){
                        try{
                                if(n2==0){
                                        throw(n2);
                                }else{
                                        ans=n1/n2;
                                        cout<<"DIVISION IS = "<<ans<<endl;
                                }
                        }catch(double n2){
                                throw;
                        }
                }
};
int main(){
        cout<<"Execption handling: \n";
        ex e;
        e.read();
        try{
                e.divide();
        }catch(double n2){
                cout<<"DIVIDE BY ZERO EXCEPTION!!\n";
        }
}
