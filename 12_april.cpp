#include<iostream>
#include<string>
using namespace std ;

class library{
    public:
 string username ;
 string password ;
void login();
void Register();
void Registration();
void logout();
};
void library ::login(){
cout<<"enter your user name "<<endl ;
cin>> username ;
cout<<endl;
Register();
};
void library :: Register (){
    cout << "enter your password "<<endl;
    cin>>password ;
    cout<<endl;
    Registration();
};
void library::Registration(){
    cout<<username<<endl;
    cout<<"***************"<<endl;
    cout<<"register successfully "<<endl;
    logout();
};
void library::logout(){
    cout<<"logout successfully" <<endl;
};

class user:public library{
    public:
    string name ;
    private :
    string id ;
void verify();
void check_account();
void get_book_info();

 void set_user(){
   cout<<"enter the name "<<endl;
   cin>>name ;
   cout<<endl;
 }

};
void user:: verify(){
    if(name==username){
        cout<<"the book issue from library "<<endl;
    }
    else{
        cout<<"no book issue from library"<<endl;
    }
}
void user::check_account(){
    if(id==username){
        cout<<"then definitely issue book from library "<<endl;
    }
};

class book : public library , public user {
public:
 string title ;
 string author ;
 string ISBN ;
 string Publication ;
 void Show_duedt();
 void Reservation_status();
 void feedback();
 void book_request();
 void Renw_info() ;
};
class librarian : public book , public library{
string name ;
string od ;
string password ;
string Search_string ;
void Verify_librarian();
void Search() ;

};
class library_database : public librarian ,public book {
    string list_OF_BOOKS ;
    void add();
    void delet();
    void update();
    void display();
    void search();
};
int main(){
library std1 ;
std1.login();
return 0;
}