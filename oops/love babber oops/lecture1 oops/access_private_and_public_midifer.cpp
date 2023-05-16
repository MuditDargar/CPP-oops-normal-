#include<iostream>
#include<string>
using namespace std ;
class modi{
    private:
    int health;
    public:
    char level ;

void print(){
    cout<<level<<endl;
}
int getHealth(){
    return health;
}
char getLevel(){
    return level;
}


void setHealth(int h){
    health = h;
}

void setlevel(char ch){
    level=ch;
}


};
int main(){


modi ramesh; // default constructor..
cout<<"ramesh health is "<<ramesh.getHealth()<<endl;
ramesh.setHealth(70);
ramesh.setlevel('Q');
//static allocation
cout<<"ramesh health is "<<ramesh.getHealth()<<endl;
cout<<"ramesh level  is "<<ramesh.getLevel()<<endl;

// dynamic allocation
modi *b = new modi ;
b->setlevel('Z');
b->setHealth(200);
cout<<"level is: "<<(*b).level<<endl;
cout<<"health is: "<<(*b).getHealth()<<endl;


cout<<"level is: "<<b->level<<endl;
cout<<"health is: "<<b->getHealth()<<endl;
return 0;
}