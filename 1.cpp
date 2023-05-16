#include<iostream>
using namespace std ;
class mudit{
     int roll_no;
     int sno;
     char name[100];

public:
mudit(){
    cout<<"enter the roll no."<<endl;
    cin>>roll_no ;
    cout<<"enter the sno"<<endl;
    cin>>sno;
    cout<<"enter the name"<<endl;
    cin>>name ;
}
void display(){
    cout<<roll_no<<endl;
    cout<<sno<<endl;
    cout<<name<<endl;
}
};

int main(){
mudit m;
m.display();

return 0;
}