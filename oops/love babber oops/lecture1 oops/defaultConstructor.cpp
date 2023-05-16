#include<iostream>
using namespace std ;
class mudit{
       int health;
       public:
       char level;

// default constructor
       mudit(){
           cout<<" default constructor "<<endl;
       }
       //parameterised constructor
       mudit(int health){
        cout<<"this->"<<this<<endl;
        this->health=health;
       }
       void print(){
        cout<<level<<endl;
       }
       int getHealth(){
        cout<< health<<endl;
       }
       char getlevel(){
        cout << level<<endl;
       }
       void sethealth(int n){
        health=n;
       }
       void setlevel(char ch){
        level=ch;
       }
};
int main(){
  //object created statically
  cout<<"hiaa"<<endl;
mudit obj1;
cout<<"kehna"<<endl;
obj1.sethealth(25);
obj1.setlevel('a');
obj1.getHealth();
obj1.getlevel();

// dynamically allocated
mudit *b = new mudit ;

cout<<"address of mudit is "<<&b<<endl;
return 0;
}