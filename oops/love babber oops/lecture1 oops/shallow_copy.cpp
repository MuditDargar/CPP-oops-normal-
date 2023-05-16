#include<iostream>
#include<string.h>

using namespace std ;
class student{ 
private:
   int roll_no;
    int id;
   
    public:
       char *name;
       student(){
     cout<<"simple constructor called"<<endl;
        name = new char[100];
       }
       void print(){
        cout<<endl;
        cout<<"name is  "<<this->name<<endl;
        cout<<"the roll no is "<<this->roll_no<<endl;
        cout<<"the id is "<<this->id<<endl;

       }
    int setroll_no(int n){
          roll_no=n;
    }
    int getroll_no(){
      cout<< roll_no <<endl;
    }
    int setid(int h){
          id=h;
    }
    int getid(){
      cout<< id<<endl  ;
    }

void setname(char name[]){
    strcpy(this->name,name);
}


};
int main(){
student  s1;
s1.setroll_no(100);
s1.getroll_no();
s1.setid(21);
s1.getid();

student hero;
hero.setid(12);
hero.setroll_no(100);
char name[5]="md";
hero.setname(name);
hero.print();

// use defaukt copy constructor
student hero2(hero);
// student hero2= hero;
hero.name[0]='G';
hero.print();

hero2.print();

//assignment operator..
hero = hero2 ;
hero.print();
hero2.print();
return 0;
}