#include<string>
#include"nlohmann\json.hpp"
#include<iostream>
#include<fstream>
using Json= nlohmann::json;
using namespace std;
class files{//uses data.json
Json data;
public:
void display(){//user and admin
cout <<"display is called\n";

std::ifstream data_file("data.json");
data_file >> data;
int quant=(int)data["quantity"];
 cout<<"product name"<<std::setw(15)<<"price"<<"\n";
for(int i=1;i<=quant;i++){
    string p=to_string(i);
string s="product"+p;
   
    cout<<std::setw(20)<<left<<(string)data[s]["prodname"]<<right;
    cout<<(int)data[s]["price"]<<"\n";
} 
}
void append(){//only admin can change price and stock
//admin can add and delet a product
cout<<"append is called\n";
int flag=1,choice;
cout<<"following features available for admins:\n";
while(flag!=0){
cout<<"1)add a product: "<<"2)delete a product: "<<"3)append a product information: \n"<<"4)Exit:\n";
cin>>choice;
switch(choice){
    case 1:
    cout<<"add a product\n"<<"enter information as showen:\n";

    break;
    case 2:
    cout<<"deletion of product is called:\n"<<"please enter product id for removal\n";
    break;
    case 3:
    cout<<"Appending is called:\n"<<"please enter product id for product identification\n";
    break;
    case 4:
    flag=0;
    break;
    default:
    cout<<"enter a valid choice\n";
    break;
}
}
}
void purchase(){//only user can purchase and it changes stock
std::ifstream data_file("data.json");
data_file >> data;
cout<<"your purchase is starting\n";
for(int j=-2;j<0;){
    string tempprod;
    int quant=(int)data["quantity"],flag=0;
cout<<"enter product name:  ";
getline(cin,tempprod);
for(int i=1;i<=quant;i++){
string s="product"+to_string(i);
string prodname=(string)data[s]["prodname"];
int length=prodname.length();
if(prodname.compare(0,length,tempprod)==0){
    int stockneed;
    cout<<"your entered product is detected\n";
    cout<<"enter required quantity ::";
    cin>>stockneed;
    int check;
    if((int)data[s]["stock"]>=stockneed){
        cout<<"we can provide you with entered product\n";
        cout<<"enter acc number to confirm payment: ";
        cin>>check;
        cout<<(int)data[s]["price"]*stockneed<<": are deducted from your account";

    }
    else{
        cout<<"we regret but we can only provide:"<<data[s]["stock"]<<"\n";
        cout<<"want to purchase then press 0";
        cin>>check;
        stockneed=(int)data[s]["stock"];
        if(check==0){
         cout<<"enter acc number to confirm payment: ";
        cin>>check;
        cout<<(int)data[s]["price"]*stockneed<<": are deducted from your account";
        }
        
    }
    flag=1;
    j=10;
    break;  }
}
if(flag==0)
cout<<"enter correct product name\n";
}
cout<<"thank you for your pateronage\n";
}
};
