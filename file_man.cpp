//prog for logging and 
//purchasing different courses/stuff.
#include <iomanip>
#include<iostream>
#include<string>
#include<C:\Users\Admin\Desktop\cpp course\read.hpp>
//#include<json/value.h>
using namespace std;

class login {
    string pwd;
    public:
    void admin(){
    
        cout<<"write password for admin login: ";
        cin>>pwd;
        if(pwd.compare(0,6,"admin1")==0){
            cout<<"login as an Admin accepted "<<"\n following features available\n";
        //comparing string for loging
         int in;
       
        while(1){
        cout<<"\n1)display of products\n"<<"2)appending\n"<<"3)exit"<<":";
        cin>>in;
        files mang;
        int io=1;//test for exit
        switch(in){
            case 1:
            mang.display();
            break;
            case 2:
            mang.append();
            break;
            case 3:
            io=0;
            break;
            default:
            cout<<"enter correct value for actions to work\n";
        }
        if(io==0){
            break;
        }
        }
        cout<<"logging out is done\n";
        }
    
        else{
            cout<<"enter correct password ";
            this->admin();
            }
}
    void user(){
//user login
    files file;
        cout<<"\nwrite password for user login: ";
        cin>>pwd;
        if((pwd.compare(0,6,"imuser"))==0){
           cout<<"login as a user accepted "<<"\n following features available\n";
        int in;
       
        while(1){
        cout<<"1)display of products\n"<<"2)purchase\n"<<"3)exit"<<":";
        cin>>in;
        files mang;
        int io=1;//test for exit
        switch(in){
            case 1:
             mang.display();
            break;
            case 2:
            mang.purchase();
            break;
            case 3:
            io=0;
            break;
            default:
            cout<<"enter correct value for actions to work\n";
        }
        if(io==0){
            break;
        }
        }
        cout<<"logging out is done\n";
        }
        else{
            cout<<"enter correct password ";
            this->user();
        }
    }
};
int main(){ 
login l;
int option,t=1;
cout<<"hello welcome to jdmart "<<"\n"<<"login to continue\n";
while(t!=0){
cout<<"1)as an Admin"<<" "<<"2)as a User\n"<<": ";
cin>>option;
if(option==1){
    l.admin();
    t=0;
}
else if(option ==2){
    l.user();
    t=0;
}
else{
cout<<"please enter correct(either 1 or 2) option\n ";
}
}
    return 0;
}