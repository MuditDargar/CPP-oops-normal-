#include<iostream>
using namespace std ;
class animal{
public:
int age;
int weight ;

public:
void bark(){
    cout<<"barking"<<endl;
}
};
class dog:public animal{

};
// multi-level inheritance;
class german_shapered:public dog{

};
class human{
public:
string color;
void speak(){
    cout<<"speaking"<<endl;
}
};

// multiple inheritance
class hybrid:public animal,public human{

};
int main(){
    german_shapered g1;
    g1.bark();
hybrid h1;
h1.speak();
h1.bark();
return 0;
}